#pragma once

#include <chrono>
#include <limits>

#include "checkers.hpp"
#include "evaluate.hpp"

namespace search
{

	constexpr float MAX_VAL = std::numeric_limits<float>::max();
	constexpr float MIN_VAL = -MAX_VAL;

	checkers::Move searchTo(const checkers::Checkers &game, int iterations, unsigned int thread_amount);

	float negamax(checkers::Checkers &state, int depth, float alpha, float beta);
} // namespace search