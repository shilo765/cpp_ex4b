#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic {
	class Scientist : public Player {
	public:
		int n;

		Scientist(Board& b, City c, int num);
		Player& discover_cure(Color c);
		string role();
	};
}