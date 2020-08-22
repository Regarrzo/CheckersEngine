#pragma once

#include "bitboard.hpp"
#include "constants.hpp"

namespace evaluate
{
	float evaluateBoard(const bitboard::BitBoard &board);
} // namespace evaluate
