#pragma once

#include <array>
#include <vector>
#include <assert.h>
#include <cinttypes>
#include <bitset>

#include "constants.hpp"
#include "pos.hpp"

namespace bitboard
{
	enum class Color
	{
		Black,
		White
	};

	typedef std::uint64_t PieceBits;

	constexpr bool hasBitAt(const PieceBits board, const pos::Pos &position)
	{
		assert(position.x >= 0 || position.x <= constants::BOARD_SIZE ||
			   position.y >= 0 || position.y <= constants::BOARD_SIZE);
		return (board >> (constants::BOARD_SIZE * position.y + position.x)) & 1;
	}

	constexpr PieceBits setBitAt(PieceBits board, bool value, const pos::Pos &position)
	{
		assert(position.x >= 0 || position.x <= constants::BOARD_SIZE ||
			   position.y >= 0 || position.y <= constants::BOARD_SIZE);
		PieceBits number = static_cast<PieceBits>(constants::BOARD_SIZE * position.y + position.x);
		return (board & ~(0 << number)) | (static_cast<uint64_t>(value) << number);
	}

	constexpr PieceBits mask(PieceBits board, PieceBits mask)
	{
		return board & mask;
	}

	constexpr PieceBits swapMask(PieceBits board, PieceBits mask)
	{
		return board ^ mask;
	}

	namespace default_pieces
	{
		const PieceBits black = 0x55AA550000000000;
		const PieceBits white = 0xAA55AA;
	} // namespace default_pieces

	class BitBoard
	{

	public:
		BitBoard();
		const std::vector<pos::Pos> &getMovementFor(Color color) const;
		PieceBits getBoardFor(Color color) const;
		PieceBits getEnemyBoardFor(Color color) const;
		PieceBits getOccupied() const;
		PieceBits getKings() const;

		PieceBits getBlackBoard() const;
		PieceBits getWhiteBoard() const;

		void setBoardFor(Color color, PieceBits new_board);
		void setEnemyBoardFor(Color color, PieceBits new_board);
		void setOccupied(PieceBits new_board);
		void setKings(PieceBits new_board);

		void movePiece(Color color, const pos::Pos &start, const pos::Pos &end);
		void removePieces(Color color, PieceBits pieces);

		// Kings can move in every direction
		static const inline std::vector<pos::Pos> KING_MOVEMENT = {
			pos::Pos(1, -1), pos::Pos(-1, -1), pos::Pos(1, 1), pos::Pos(-1, 1)};

		// Black can move upwards
		static const inline std::vector<pos::Pos> BLACK_MOVEMENT = {
			pos::Pos(1, -1), pos::Pos(-1, -1)};

		// White can move downwards
		static const inline std::vector<pos::Pos> WHITE_MOVEMENT = {
			pos::Pos(1, 1), pos::Pos(-1, 1)};

	private:
		PieceBits kings;
		PieceBits white;
		PieceBits black;
		PieceBits occupied;
	};
} // namespace bitboard
