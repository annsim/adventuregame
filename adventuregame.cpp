// adventuregame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"


Game game;

int main() {
	game.run();
	GameData gameData;

	Location* startLocation = gameData.getStartLocation();

	if (startLocation == nullptr) {
		std::cout << "No startlocation found - something went wrong\n";
		return 1;

	}

	std::cout << "Start Location is " << startLocation->id << ":" << startLocation->text << "\n";

	

	if (startLocation->choices.size() > 0) {
		const std::string& secondLocationId = startLocation->choices[0].locationId;
		Location* secondLocation = gameData.getLocationWithId(secondLocationId);
		
		if (secondLocation != nullptr) {
			std::cout << "Possible Second Location: " << secondLocation->text << "\n";
		}
	}
	

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
