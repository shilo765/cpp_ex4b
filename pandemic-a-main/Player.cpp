#include <map>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

#define CARDS_TO_CURE 5

using namespace pandemic;

namespace pandemic {
	Player::Player(Board& b, City c) : board(b), city(c) { }

	void Player::init() {
		for (int city = 0; city < City::Cities; city++) {
			cards[city] = 0;
		}
	}

	Player& Player::take_card(City c) {
		int current = cards[c];

		cards[c] = 1;

		return *this;
	}

	Player& Player::build() {
		if (!board.hasResearch[city]) {
			if (cards[city] >= 1) {
				int current = cards[city];

				cards[city] = current - 1;

				cout << "Building Research in city " << cityNames[city] << endl;

				board.hasResearch[city] = true;
			}
			else {
				throw std::invalid_argument("You dont have the city's card!");
			}
		}
		else {
			cout << cityNames[city] << " already have a research!" << endl;
		}

		return *this;
	}

	Player& Player::drive(City c) {
		if (!board.is_connected(cityNames[city], cityNames[c])) {
			throw std::invalid_argument("No Path between the cities");
		}

		city = c;

		cout << "Driving to " << cityNames[city] << endl;

		return *this;
	}
	Player& Player::fly_direct(City c) {
		if (c != city) {
			if (cards[c] >= 1) {
				cout << "flying to " << cityNames[c] << endl;

				this->city = c;

				cards[c] = 0;
			}
			else
				throw std::invalid_argument("You don't have the city's card");
		}
		else
			cout << "You're already in this city" << endl;

		return *this;
	}

	Player& Player::fly_shuttle(City c) {
		if (c != city) {
			if (board.hasResearch[c] && board.hasResearch[city]) {
				cout << "flying shuttle to " << cityNames[c] << endl;

				this->city = c;
			}
			else
				cout << "cant fly, you don't have research on both cities" << endl;
		}
		else
			cout << "You're already in this city" << endl;

		return *this;
	}

	Player& Player::fly_charter(City c) {
		if (c != city) {
			if (cards[city] >= 1) {
				cout << "flying charter to city " << cityNames[c] << endl;

				this->city = c;

				cards[city] = 0;
			}
			else {
				throw std::invalid_argument("You don't have the city's card");
			}
		}
		else {
			cout << "You're already in this city" << endl;
		}

		return *this;
	}

	Player& Player::treat(City c) {
		if (c != city)
			throw std::invalid_argument("You are not in the city");

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

		return *this;
	}

	Player& Player::discover_cure(Color c) {
		if (!board.hasCure[c]) {
			if (board.hasResearch[city]) {
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
			}
			else {
				cout << "There is no research in your city " << cityNames[city] << endl;

				throw std::invalid_argument("There is no research in your city");
			}
		}
		else {
			cout << "You already have a cure for that color" << endl;

			throw std::invalid_argument("Cure is already being found");
		}

		return *this;
	}

	string Player::role() {
		return "Player";
	}
}
