#include "GeneSplicer.hpp"

namespace pandemic {
	GeneSplicer::GeneSplicer(Board& b, City c) : Player(b, c) { }

	Player& GeneSplicer::discover_cure(Color c) {
		if (board.hasResearch[city]) {
			int sum = 0;

			for (int i = 0; i < City::Cities; i++) {
				sum += cards[i];
			}

			cout << "Found " << sum << " Cards of that color" << endl;

			if (sum >= CARDS_TO_CURE) {
				int counter = CARDS_TO_CURE;

				// Consume cards
				for (int i = 0; i < City::Cities; i++) {
					if (counter <= 0)
						break;

					if (cards[i] > 0) {
						cards[i] = cards[i] - 1;
						counter--;
					}
				}

				board.hasCure[c] = true;

				cout << "Cured discovered for color " << c << endl;
			}
			else {
				cout << "You need atleast " << CARDS_TO_CURE << " cards of that color" << endl;

				throw std::invalid_argument("You dont have enough cards");
			}
		}
		else {
			cout << "There is no research in your city " << cityNames[city] << endl;

			throw std::invalid_argument("There is no research in your city");
		}

		return *this;
	}

	string GeneSplicer::role() {
		return "GeneSplicer!";
	}
}
