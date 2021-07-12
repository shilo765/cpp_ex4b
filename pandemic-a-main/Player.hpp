#pragma once

#include <map>
#include "Board.hpp"
#include "City.hpp"

#define CARDS_TO_CURE 5

namespace pandemic {
	class Player {
	public:
		Board& board;
		City city;
		map<int, int> cards;

		void init();
		Player(Board& b, City c);
		Player& take_card(City c);
		virtual Player& build();
		Player& drive(City c);
		virtual Player& fly_direct(City c);
		Player& fly_shuttle(City c);
		Player& fly_charter(City c);
		virtual Player& treat(City c);
		virtual Player& discover_cure(Color c);
		virtual string role();
	};
}