#include <string.h>

#include <array>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <exception>

#include "checkers.hpp"
#include "constants.hpp"
#include "bitboard.hpp"
#include "pos.hpp"

using namespace checkers;

Checkers::Checkers() : board(), state_stack(), current_player(bitboard::Color::Black)
{
}

bool Checkers::canMove(const pos::Pos &position) const
{

	if (!position.inBounds(0, constants::BOARD_SIZE - 1))
	{
		return false;
	}

	return !bitboard::hasBitAt(board.getOccupied(), position);
}

struct MoveNode
{
	pos::Pos position;
	bitboard::PieceBits taken;
};

std::vector<Move> Checkers::generateLegalMoves() const
{
	bitboard::PieceBits player_board = board.getBoardFor(current_player);
	bitboard::PieceBits enemy_board = board.getEnemyBoardFor(current_player);
	const std::vector<pos::Pos> &player_movement = board.getMovementFor(current_player);

	std::vector<Move> moves = std::vector<Move>();

	bool take_moves_exist = false;

	for (int y = 0; y < constants::BOARD_SIZE; y++)
	{
		for (int x = 0; x < constants::BOARD_SIZE; x++)
		{
			pos::Pos current_pos = pos::Pos(x, y);

			// Nothing or enemy piece here
			if (!bitboard::hasBitAt(player_board, current_pos))
			{
				continue;
			}

			// Use king movement if the current pos is also flagged as a king
			const auto &current_movement = bitboard::hasBitAt(board.getKings(), current_pos) ? bitboard::BitBoard::KING_MOVEMENT : player_movement;

			for (const pos::Pos &dir : current_movement)
			{
				pos::Pos move_pos = current_pos + dir;
				if (canMove(move_pos))
				{
					moves.push_back({current_pos, move_pos, 0});
					continue;
				}
				else if (bitboard::hasBitAt(player_board, move_pos))
				{
					continue;
				}
				else
				{
					// Go one piece further
					pos::Pos possible_take_pos = move_pos;
					move_pos = move_pos + dir;

					// two enemies infront of current piece -> can't do anything
					if (!canMove(move_pos))
					{
						continue;
					}

					// Taking is possible

					take_moves_exist = true;

					MoveNode root = MoveNode{move_pos, bitboard::setBitAt(0, true, possible_take_pos)};
					std::stack<MoveNode> to_explore = std::stack<MoveNode>();
					to_explore.push(root);

					while (!to_explore.empty())
					{
						bool is_leaf = true;
						const MoveNode &current_node = to_explore.top();
						to_explore.pop();

						for (const pos::Pos &take_dir : current_movement)
						{

							pos::Pos new_pos = current_node.position + take_dir * 2;
							pos::Pos take_pos = current_node.position + take_dir;

							if (canMove(new_pos) && (bitboard::hasBitAt(enemy_board, take_pos) && !(bitboard::hasBitAt(current_node.taken, take_pos))))
							{
								is_leaf = false;
								MoveNode new_node = MoveNode{new_pos, bitboard::setBitAt(current_node.taken, true, take_pos)};
								to_explore.push(new_node);
							}
						}

						if (is_leaf)
						{
							moves.push_back(Move{current_pos, current_node.position, current_node.taken});
						}
					}
				}
			}
		}
	}

	// If there are moves that take, remove ones that don't

	if (take_moves_exist)
	{
		moves.erase(std::remove_if(begin(moves), end(moves), [](const auto &p) { return p.taken == 0; }), end(moves));
	}

	return moves;
}

std::string Checkers::toString() const
{
	std::string result = std::string();

	for (int y = 0; y < constants::BOARD_SIZE; y++)
	{
		result.append(std::to_string(y) + "  ");
		for (int x = 0; x < constants::BOARD_SIZE; x++)
		{
			pos::Pos current_pos = pos::Pos(x, y);

			if (bitboard::hasBitAt(board.getBoardFor(bitboard::Color::Black), current_pos))
			{
				if (bitboard::hasBitAt(board.getKings(), current_pos))
				{
					result.append("□ ");
				}
				else
				{
					result.append("○ ");
				}
			}
			else if (bitboard::hasBitAt(board.getBoardFor(bitboard::Color::White), current_pos))
			{
				if (bitboard::hasBitAt(board.getKings(), current_pos))
				{
					result.append("■ ");
				}
				else
				{
					result.append("● ");
				}
			}
			else
			{
				result.append("· ");
			}
		}
		result.append("\n");
	}

	result.append("   0 1 2 3 4 5 6 7");

	return result;
}

// TODO: Fix this
void Checkers::loadPDN(std::string pdn)
{

	char move_side = pdn[0];

	if (move_side == *"B")
	{
		current_player = bitboard::Color::Black;
	}
	else
	{
		current_player = bitboard::Color::White;
	}

	bitboard::Color current_piece_color = bitboard::Color::Black;

	// First two letters don't give board information
	for (size_t i = 2; i < pdn.length(); i++)
	{
		if (!isdigit(pdn[i]))
		{
			// Colons don't give useful information
			if (pdn[i] == *":")
			{
				continue;
			}
			// A new color is active
			else
			{
				if (pdn[i] == *"B")
				{
					current_piece_color = bitboard::Color::Black;
				}
				else
				{
					current_piece_color = bitboard::Color::White;
				}
			}
		}
		else
		{
		}
	}
}

std::string Checkers::toPDN() const
{
	std::string result = std::string();

	// Current player to move
	if (current_player == bitboard::Color::Black)
	{
		result.append("B:");
	}
	else
	{
		result.append("W:");
	}

	// Start with Black Pieces

	bool comma = false;
	result.append("B");

	for (int y = 0; y < constants::BOARD_SIZE; y++)
	{
		for (int x = 0; x < constants::BOARD_SIZE; x++)
		{
			pos::Pos current_pos = pos::Pos(x, y);

			if (!bitboard::hasBitAt(board.getBlackBoard(), current_pos))
			{
				continue;
			}

			// Convert current position to number from 1 to 32

			int pdn_pos = (y * constants::BOARD_SIZE + x) / 2 + 1;

			if (bitboard::hasBitAt(board.getKings(), current_pos))
			{
				result.append("K");
			}

			if (comma)
				result.append(",");
			else
				comma = true;

			result.append(std::to_string(pdn_pos));
		}
	}

	// White pieces

	comma = false;
	result.append(":W");

	for (int y = 0; y < constants::BOARD_SIZE; y++)
	{
		for (int x = 0; x < constants::BOARD_SIZE; x++)
		{
			pos::Pos current_pos = pos::Pos(x, y);

			if (!bitboard::hasBitAt(board.getWhiteBoard(), current_pos))
			{
				continue;
			}

			// Convert current position to number from 1 to 32

			int pdn_pos = (y * constants::BOARD_SIZE + x) / 2 + 1;

			if (bitboard::hasBitAt(board.getKings(), current_pos))
			{
				result.append("K");
			}

			if (comma)
				result.append(",");
			else
				comma = true;

			result.append(std::to_string(pdn_pos));
		}
	}

	return result;
}

bool Checkers::isWon(const std::vector<Move> &legal_moves) const
{
	if (legal_moves.empty())
	{
		return true;
	}

	if (board.getBoardFor(bitboard::Color::Black) == 0 ||
		board.getBoardFor(bitboard::Color::White) == 0)
	{
		return true;
	}

	return false;
}

void Checkers::swapPlayer()
{
	if (current_player == bitboard::Color::Black)
	{
		current_player = bitboard::Color::White;
	}
	else
	{
		current_player = bitboard::Color::Black;
	}
}

void Checkers::step(Move move)
{
	assert(move.start.inBounds(0, constants::BOARD_SIZE - 1));
	assert(move.end.inBounds(0, constants::BOARD_SIZE - 1));

	assert(bitboard::hasBitAt(board.getBoardFor(current_player), move.start));
	assert(!bitboard::hasBitAt(board.getOccupied(), move.end));

	// Copy all bitboards
	state_stack.push(board);
	board.movePiece(current_player, move.start, move.end);
	swapPlayer();
	board.removePieces(current_player, move.taken);
}

void Checkers::undoStep()
{
	if (!state_stack.empty())
	{
		swapPlayer();
		board = state_stack.top();
		state_stack.pop();
	}
	else
	{
		throw std::range_error("Undo called on empty undo stack.");
	}
}

bitboard::Color Checkers::getCurrentPlayer() const
{
	return current_player;
}

const bitboard::BitBoard &Checkers::getBoard() const
{
	return board;
}