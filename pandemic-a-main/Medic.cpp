#include "Medic.hpp"

namespace pandemic {
	Medic::Medic(Board& b, City c) : Player(b, c) { }

	Player& Medic::treat(City c) {
		if (c != city)
			throw std::invalid_argument("Exception1");

		if (board.cubes[c] <= 0)
			throw std::invalid_argument("Exception2");

		board.cubes[c] = 0;

		return *this;
	}
	string Medic::role() {
		return "Medic!";
	}
}
