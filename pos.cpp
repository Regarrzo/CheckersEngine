#include <assert.h>

#include "pos.hpp"

namespace pos
{

	Pos::Pos() : x(0), y(0) {}
	Pos::Pos(int x, int y) : x(x), y(y) {}

	Pos Pos::operator+(const Pos &other) const
	{
		return Pos(x + other.x, y + other.y);
	}

	Pos Pos::operator-(const Pos &other) const
	{
		return Pos(x - other.x, y - other.y);
	}

	Pos Pos::operator*(int other) const
	{
		return Pos(x * other, y * other);
	}

	bool Pos::operator==(Pos other) const
	{
		return (x == other.x && y == other.y);
	}

	bool Pos::inBounds(int min, int max) const
	{
		return !(this->x < min || this->x > max ||
				 this->y < min || this->y > max);
	}

	Pos Pos::getPosBetween(const Pos &other) const
	{
		assert((this->x + other.x) % 2 == 0 || (this->y + other.y) % 2 == 0);
		return Pos(
			(this->x + other.x) / 2,
			(this->y + other.y) / 2);
	}
} // namespace pos