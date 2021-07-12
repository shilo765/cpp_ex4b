#include <iostream>
#include <map>
#include <fstream>
#include <string>

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"


namespace pandemic {
	void Board::insertPaths() {
		ifstream file("cities_map.txt");

		string str;
		string delimiter = " ";
		
		while (getline(file, str))
		{
			size_t pos = 0;
			string token;
			string first;
			
			int counter = 0;

			while ((pos = str.find(delimiter)) != std::string::npos) {
				token = str.substr(0, pos);

				if (counter == 0)
					first = token;

				else if (counter != 1)
					paths[first][token] = true;	
				
				str.erase(0, pos + delimiter.length());
						
				counter++;
			}
			
			token = str.substr(0, str.length());
					
			paths[token][first] = true;
		}
	}

	Board::Board() {
		for (int city = 0; city < City::Cities; city++) {
			cubes[city] = 0;
			hasResearch[city] = false;

			for (int city2 = 0; city2 < City::Cities; city2++) {
				paths[cityNames[city]][cityNames[city2]] = false;
			}
		}

		for (int color = 0; color < Color::Colors; color++)
			hasCure[color] = false;

		insertPaths();
	}

	bool Board::is_clean() {
		int sum = 0;

		for (int i = 0; i < City::Cities; i++) {
			sum += cubes[i];
		}

		return sum == 0;
	}

	bool Board::is_connected(string a, string b) {
		return (paths[a][b] || paths[b][a]);
	}

	void Board::remove_cures() {
		for (int color = 0; color < Color::Colors; color++)
			hasCure[color] = false;
	}
}
