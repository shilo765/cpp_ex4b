#include <iostream>
#include "OperationsExpert.hpp"

namespace pandemic {
	OperationsExpert::OperationsExpert(Board& b, City c) : Player(b, c) { }

	Player& OperationsExpert::build() {
		if (!board.hasResearch[city]) {
			cout << "Building Research at " << cityNames[city] << endl;

			board.hasResearch[city] = true;
		}
		else {
			cout << "Cannot build more than 1 research." << endl;
		}

		return *this;
	}

	string OperationsExpert::role() {
		return "OperationsExpert!";
	}
}