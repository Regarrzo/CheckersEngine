
#include <stdio.h>

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

#include "pos.hpp"
#include "bitboard.hpp"
#include "checkers.hpp"
#include "evaluate.hpp"
#include "search.hpp"

checkers::Move getUserInput(const std::vector<checkers::Move> &legal_moves)
{
	for (size_t i = 0; i < legal_moves.size(); i++)
	{
		checkers::Move move = legal_moves[i];
		printf("(%ld) Start: (Y=%d, X=%d), End: (Y=%d, X=%d), Takes:",
			   i, move.start.y, move.start.x, move.end.y, move.end.x);

		for (int y = 0; y < constants::BOARD_SIZE; y++)
		{
			for (int x = 0; x < constants::BOARD_SIZE; x++)
			{
				pos::Pos current_pos = pos::Pos(x, y);

				if (bitboard::hasBitAt(move.taken, current_pos))
				{
					printf("(Y=%d, X=%d), ", y, x);
				}
			}
		}
		printf("\n");
	}

	printf("Enter move: ");
	size_t inpt;
	std::cin >> inpt;

	if (inpt >= legal_moves.size())
	{
		throw std::runtime_error("Move chosen is out of bounds.");
	}

	return legal_moves[inpt];
}

int main()
{
	checkers::Checkers game = checkers::Checkers();

	while (true)
	{

		if (game.getCurrentPlayer() == bitboard::Color::Black)
		{
			std::cout << "Black turn: " << std::endl;
		}
		else
		{
			std::cout << "White turn: " << std::endl;
		}

		std::cout << game.toString() << std::endl;

		auto legal_moves = game.generateLegalMoves();

		std::cout << "Found " << legal_moves.size() << " moves." << std::endl;

		if (game.isWon(legal_moves))
		{
			if (game.getCurrentPlayer() == bitboard::Color::Black)
			{
				std::cout << "White won!" << std::endl;
			}
			else
			{
				std::cout << "Black won! " << std::endl;
			}

			break;
		}


		// By changing the color here you can configure which color the user plays
		if (game.getCurrentPlayer() == bitboard::Color::Black)
		{
			while (true)
			{
				try
				{
					game.step(getUserInput(legal_moves));
					break;
				}
				catch (const std::runtime_error &error)
				{
					std::cout << "Illegal move entered, try again:" << std::endl;
					continue;
				}
			}
		}
		else
		{
			game.step(search::searchTo(game, 26, 8));
		
		}
	}
	return 0;
}
