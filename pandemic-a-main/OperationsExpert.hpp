#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic {
	class OperationsExpert : public Player {
	public:
		OperationsExpert(Board& b, City c);
		Player& build();
		string role();
	};
}