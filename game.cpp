#include "game.h"

#include <vector>
#include <string>
#include <iostream>

void Game::run()
{
	//std::cout << "Debugging Locations \n";
	//gameData.debugLocations();
	std::cout << "Welcome to my amazing TextAdventureGame! \n";
	player.currentLocation = gameData.getStartLocation();

	while (isRunning) {
		if (player.currentLocation == nullptr) {
			std::cout << "Player is not at a valid location \n";
			break;
		}

		std::cout << player.currentLocation->text << "\n\n";

		if (player.currentLocation->choices.size() == 0) {
			std::cout << "Game Over! \n";
			break;
		}

		std::cout << "Choose you option \n";

		for (int i = 0; player.currentLocation->choices.size(); ++i) {
		std::cout << "[" << i << "]" << player.currentLocation->choices[i].text << "\n";
		}
	
		int choice = 1;

		while (choice < 0 || choice >= player.currentLocation->choices.size()) {
			std::cin >> choice;
		}
		// Use a const reference to save copying the string to a local variable
		const std::string& nextLocationId = player.currentLocation->choices[choice].locationId;
		player.currentLocation = gameData.getLocationWithId(nextLocationId);
		player.moves++;
	}

	std::cout << "You made " << player.moves << " moves! \n";
	}

