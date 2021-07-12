#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic {
	class Researcher : public Player {
	public:
		Researcher(Board& b, City c);

		Player& discover_cure(Color c);

		string role();
	};
}