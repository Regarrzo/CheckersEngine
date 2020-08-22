
#include <vector>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <future>
#include <thread>

#include "extern/CTPL/ctpl_stl.h"
#include "search.hpp"
#include "evaluate.hpp"
#include "bitboard.hpp"

long int explored_moves;

struct ThreadInput
{
    checkers::Checkers state;
    checkers::Move last_move;
    int depth;
};

struct ThreadOutput
{
    checkers::Move move;
    float score;
};

float search::negamax(checkers::Checkers &state, int depth, float alpha, float beta)
{
    //std::cout << "Negamax:" << std::endl;
    //std::cout << state.toString() << std::endl;

    explored_moves++;

    std::vector<checkers::Move> moves = state.generateLegalMoves();
    float score = MIN_VAL;

    if (state.isWon(moves))
    {
        return MIN_VAL;
    }

    if (depth <= 0)
    {
        return state.getCurrentPlayer() == bitboard::Color::Black
                   ? evaluate::evaluateBoard(state.getBoard())
                   : -evaluate::evaluateBoard(state.getBoard());
    }

    for (const checkers::Move &move : moves)
    {

        state.step(move);
        float value = -negamax(state, --depth, -beta, -alpha);
        state.undoStep();

        if (value > score)
        {
            score = value;
        }

        if (score > alpha)
        {
            alpha = score;
        }

        if (alpha >= beta)
        {
            return alpha;
        }
    }

    return score;
}

ThreadOutput negamax_thread(int id, ThreadInput input)
{
    ThreadOutput out;
    out.move = input.last_move;
    out.score = -search::negamax(input.state, input.depth, search::MIN_VAL, search::MAX_VAL);
    return out;
}

checkers::Move search::searchTo(const checkers::Checkers &game, int iterations, unsigned int thread_amount)
{
    explored_moves = 0;

    std::vector<checkers::Move> moves = game.generateLegalMoves();

    if (moves.empty())
    {
        throw std::runtime_error("Search called on position with no possible moves.");
    }

    if (moves.size() == 1)
    {
        std::cout << "Only one move possible" << std::endl;
        return moves[0];
    }

    if (thread_amount > moves.size())
    {
        thread_amount = moves.size();
    }
    ctpl::thread_pool pool(thread_amount);
    std::vector<std::future<ThreadOutput>> results(moves.size());

    checkers::Checkers game_copy = game;

    std::cout << "Spawning " << thread_amount << " threads " << std::endl;

    for (unsigned int i = 0; i < moves.size(); i++)
    {
        game_copy.step(moves[i]);
        results[i] = pool.push(negamax_thread, ThreadInput{game_copy, moves[i], iterations});
        game_copy.undoStep();
    }

    std::cout << "Fetching thread results" << std::endl;

    float best_move_score = MIN_VAL;
    checkers::Move best_move = moves[0];

    for (unsigned int i = 0; i < moves.size(); i++)
    {

        ThreadOutput result = results[i].get();
        std::cout << "Found move: " << result.score << std::endl;

        if (result.score > best_move_score)
        {
            best_move_score = result.score;
            best_move = result.move;
        }
    }

    std::cout << "Score: " << best_move_score << std::endl;
    std::cout << "Explored " << explored_moves << " moves" << std::endl;
    return best_move;
}
