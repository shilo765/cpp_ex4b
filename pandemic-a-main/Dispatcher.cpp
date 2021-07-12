#include "Dispatcher.hpp"
#include <iostream>

namespace pandemic {
	Dispatcher::Dispatcher(Board& b, City c) : Player(b, c) { }

	Player& Dispatcher::fly_direct(City c) {
		if (board.hasResearch[city]) {
			cout << "flying to city number #" << c << endl;

			this->city = c;
		}
		else {
			cout << "cant fly, there is no research" << endl;
		}

		return *this;
	}

	string Dispatcher::role() {
		return "Dispatcher!";
	}
}