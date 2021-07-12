#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic {
	class Dispatcher : public Player {
	public:
		Dispatcher(Board& b, City c);
		Player& fly_direct(City c);
		string role();
	};
}