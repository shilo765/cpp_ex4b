#include "Researcher.hpp"

namespace pandemic {
	Researcher::Researcher(Board& b, City c) : Player(b, c) { }

	Player& Researcher::discover_cure(Color c) {
		int sum = 0;
		int start = c * CITIES_PER_REGION;

		for (int i = start; i < start + CITIES_PER_REGION; i++) {
			sum += cards[i];
		}

		cout << "Found " << sum << " Cards of that color" << endl;

		if (sum >= CARDS_TO_CURE) {
			int counter = CARDS_TO_CURE;

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

		return *this;
	}

	string Researcher::role() {
		return "Researcher!";
	}
}
