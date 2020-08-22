#include <array>

#include "bitboard.hpp"

using namespace bitboard;

BitBoard::BitBoard() : kings(),
					   white(default_pieces::white),
					   black(default_pieces::black),
					   occupied(default_pieces::black | default_pieces::white) {}

PieceBits BitBoard::getBlackBoard() const
{
	return black;
}

PieceBits BitBoard::getWhiteBoard() const
{
	return white;
}

PieceBits BitBoard::getBoardFor(Color color) const
{
	if (color == bitboard::Color::Black)
	{
		return black;
	}
	else
	{
		return white;
	}
}

PieceBits BitBoard::getEnemyBoardFor(Color color) const
{
	if (color == bitboard::Color::Black)
	{
		return white;
	}
	else
	{
		return black;
	}
}

PieceBits BitBoard::getOccupied() const
{
	return occupied;
}

PieceBits BitBoard::getKings() const
{
	return kings;
}

const std::vector<pos::Pos> &BitBoard::getMovementFor(Color color) const
{
	if (color == bitboard::Color::Black)
	{
		return BitBoard::BLACK_MOVEMENT;
	}
	else
	{
		return BitBoard::WHITE_MOVEMENT;
	}
}

void BitBoard::setBoardFor(Color color, PieceBits new_board)
{
	if (color == bitboard::Color::Black)
	{
		black = new_board;
	}
	else
	{
		white = new_board;
	}

	occupied = black | white;
}

void BitBoard::setEnemyBoardFor(Color color, PieceBits new_board)
{
	if (color == bitboard::Color::Black)
	{
		white = new_board;
	}
	else
	{
		black = new_board;
	}

	occupied = black | white;
}

void BitBoard::setOccupied(PieceBits new_board)
{
	occupied = new_board;
}

void BitBoard::setKings(PieceBits new_board)
{
	kings = new_board;
}

void BitBoard::movePiece(Color color, const pos::Pos &start, const pos::Pos &end)
{
	PieceBits mask = 0;
	mask = setBitAt(mask, true, start);
	mask = setBitAt(mask, true, end);

	assert(hasBitAt(mask, start));
	assert(hasBitAt(mask, end));

	assert(!hasBitAt(getBoardFor(color), end));
	assert(hasBitAt(getBoardFor(color), start));

	setBoardFor(color, swapMask(getBoardFor(color), mask));

	if (hasBitAt(kings, start))
	{
		assert(!hasBitAt(kings, end));
		kings = swapMask(kings, mask);
	}
	else if (end.y == 0 || end.y == (constants::BOARD_SIZE - 1))
	{
		kings = setBitAt(kings, true, end);
	}
}

void BitBoard::removePieces(Color color, PieceBits pieces)
{

	PieceBits player_board = getBoardFor(color);
	setBoardFor(color, (player_board ^ pieces) & player_board);
	kings = (kings ^ pieces) & kings;
}