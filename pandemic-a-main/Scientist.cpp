#include "Scientist.hpp"

namespace pandemic {
	Scientist::Scientist(Board& b, City c, int num) : Player(b, c), n(num) { }

	Player& Scientist::discover_cure(Color c) {
		if (board.hasResearch[city]) {
			int sum = 0;
			int start = c * CITIES_PER_REGION;

			for (int i = start; i < start + CITIES_PER_REGION; i++) {
				sum += cards[i];
			}

			cout << "Found " << sum << " Cards of that color" << endl;

			if (sum >= n) {
				int counter = n;

				// Consume cards
				for (int i = start; i < start + CITIES_PER_REGION; i++) {
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

	string Scientist::role() {
		return "Scientist!";
	}
}
