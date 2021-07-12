#include "Virologist.hpp"

namespace pandemic {
	Virologist::Virologist(Board& b, City c) : Player(b, c) { }

	Player& Virologist::treat(City c) {
		if (c != city) {
			if (cards[c] >= 1)
				cards[c] --;
			else
				throw std::invalid_argument("Exception1");
		}

		if (board.cubes[c] <= 0)
			throw std::invalid_argument("Exception2");

		int color = c / CITIES_PER_REGION;

		if (board.hasCure[color]) {
			board.cubes[c] = 0;

			cout << "Treated with cure" << endl;
		}
		else {
			board.cubes[c]--;

			cout << "Treated without cure" << endl;
		}

		return *this;
	}

	string Virologist::role() {
		return "Virologist!";
	}
}
