#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>

#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {
	class Board {
	public:
		int cubes[City::Cities];
		bool hasResearch[City::Cities];
		bool hasCure[Color::Colors];

		map<string, map<string, bool>> paths;

		Board();

		bool is_clean();
		bool is_connected(string a, string b);

		void insertPaths();
		void remove_cures();

		int& operator[](City c) {
			return cubes[c];
		}
		
		friend ostream& operator<<(ostream& os, const Board& b)
		{
			os << "Board print" << endl;
			
			return os;
		}
	};
}
