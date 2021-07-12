#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic {
	class FieldDoctor : public Player {
	public:
		FieldDoctor(Board& b, City c);
		Player& treat(City c);
		string role();
	};
}