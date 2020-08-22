#pragma once

#include <vector>
#include <stack>
#include <string>

#include "bitboard.hpp"
#include "pos.hpp"

namespace checkers
{

	struct Move
	{
		pos::Pos start;
		pos::Pos end;
		bitboard::PieceBits taken;

		inline auto operator<=>(const Move &) const = default;
	};


	class Checkers
	{

	public:
		Checkers();

		bitboard::Color getCurrentPlayer() const;
		const bitboard::BitBoard &getBoard() const;

		std::vector<Move> generateLegalMoves() const;
		std::string toString() const;
		std::string toPDN() const;

		void loadPDN(std::string pdn);
		void step(Move move);
		void undoStep();
		bool isWon(const std::vector<Move> &legal_moves) const;

	private:
		bool canMove(const pos::Pos &position) const;
		void swapPlayer();

		bitboard::BitBoard board;
		std::stack<bitboard::BitBoard> state_stack;
		bitboard::Color current_player;
	};
} // namespace checkers
