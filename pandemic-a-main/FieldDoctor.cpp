#include "FieldDoctor.hpp"
#include <iostream>

namespace pandemic {
	FieldDoctor::FieldDoctor(Board& b, City c) : Player(b, c) { }

	Player& FieldDoctor::treat(City c) {
		if (c == city || board.is_connected(cityNames[c], cityNames[city]))
		{
			if (board.cubes[c] <= 0)
				throw std::invalid_argument("No cubes left in the city");

			int color = c / CITIES_PER_REGION;

			if (board.hasCure[color]) {
				board[c] = 0;

				cout << "Treated with cure, 0 cubes left" << endl;
			}
			else {
				board[c] = board[c] - 1;

				cout << "Treated without cure, " << board[c] << " cubes left" << endl;
			}
		}
		else {
			throw std::invalid_argument("You are not in the city or on one of its connected");
		}

		return *this;
	}

	string FieldDoctor::role() {
		return "Field Doctor!";
	}
}
