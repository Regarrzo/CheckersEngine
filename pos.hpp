#pragma once

namespace pos
{

	class Pos
	{
	public:
		int x, y;

		Pos();
		Pos(int x, int y);

		Pos operator+(const Pos &) const;
		Pos operator-(const Pos &) const;
		Pos operator*(int) const;
		bool operator==(Pos other) const;

		bool inBounds(int, int) const;
		Pos getPosBetween(const Pos &) const;
	};
} // namespace pos