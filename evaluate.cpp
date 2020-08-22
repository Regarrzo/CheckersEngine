#include "evaluate.hpp"
#include "bitboard.hpp"

float evaluate::evaluateBoard(const bitboard::BitBoard &board)
{

    float score = 0;

    bitboard::PieceBits white_board = board.getWhiteBoard();
    bitboard::PieceBits black_board = board.getBlackBoard();
    bitboard::PieceBits kings = board.getKings();

    for (int y = 0; y < constants::BOARD_SIZE; y++)
    {
        for (int x = 0; x < constants::BOARD_SIZE; x++)
        {
            pos::Pos current_pos = pos::Pos(x, y);

            // Black score

            if (bitboard::hasBitAt(black_board, current_pos))
            {
                // Material score

                if (bitboard::hasBitAt(kings, current_pos))
                {
                    score += constants::KING_VALUE;
                }
                else
                {
                    score += constants::PIECE_VALUE;

                    // Peasants get extra score for being advanced
                    score += (y * constants::ADVANCE_BONUS);

                    // Peasants get extra score for protecting the back rank

                    if (y == 0)
                    {
                        score += constants::INTACT_BACK_ROW_BONUS;
                    }
                }

                // Bonus for being in the center
                if (current_pos.inBounds(2, constants::BOARD_SIZE - 3))
                {
                    score += constants::CENTER_CONTROL_BONUS;
                }

                continue;
            }

            // White score

            if (bitboard::hasBitAt(white_board, current_pos))
            {
                if (bitboard::hasBitAt(kings, current_pos))
                {
                    score -= constants::KING_VALUE;
                }
                else
                {
                    score -= constants::PIECE_VALUE;

                    // Peasants get extra score for being advanced
                    score -= (((constants::BOARD_SIZE - 1) - y) * constants::ADVANCE_BONUS);

                    // Peasants get extra score for protecting the back rank

                    if (y == 7)
                    {
                        score -= constants::INTACT_BACK_ROW_BONUS;
                    }
                }
                // Bonus for being in the center
                if (current_pos.inBounds(2, constants::BOARD_SIZE - 3))
                {
                    score -= constants::CENTER_CONTROL_BONUS;
                }

                continue;
            }
        }
    }

    return score;
}