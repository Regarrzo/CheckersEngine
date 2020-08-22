#pragma once

namespace constants
{
	// Board info
	constexpr int BOARD_SIZE = 8;

	// Evaluation
	const float PIECE_VALUE = 1.0f;
	const float KING_VALUE = 2.0f;

	const float ADVANCE_BONUS = 0.04f;
	const float CENTER_CONTROL_BONUS = 0.1f;
	const float INTACT_BACK_ROW_BONUS = 0.2f;

	const float MOVE_SCORE_CUTOFF = 10000;
} // namespace constants