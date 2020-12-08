#include "gamedata.h"


#include <iostream>


LocationChoice::LocationChoice(const std::string& nextId, const std::string& aText)
{
	locationId = nextId;
	text = aText;
}

Location::Location(const std::string& anId, const std::string& aText)
{
	id = anId;
	text = aText;
}



GameData::GameData()
{
	createLocations();

}

void GameData::debugLocations()
{
	std::cout << "Total Locations" << locations.size() << "\n";

	for (size_t i = 0; i < locations.size(); ++i) {
		Location location = locations[i];
		std::cout << location.id << " : " << location.text << "\n";

		for (size_t j = i + 1; j < locations.size(); ++j) {
			if (location.id == locations[j].id) {

				std::cout << "ALERT ther is a duplicate in Location id " << location.id << "\n";

			}
		}

	}

}

void GameData::createLocations()
{
	Location room1("Start", "You are in the first room of this story.");
	room1.choices.push_back(LocationChoice("room2", "Go North"));
	room1.choices.push_back(LocationChoice("exit", "Exit"));
	locations.push_back(room1);

	Location room2("room2", "You are in the second room of this story.");
	room2.choices.push_back(LocationChoice("exit", "Exit"));
	locations.push_back(room2);

	Location room3("room3", "You are in the third room of this story.");
	room3.choices.push_back(LocationChoice("exit", "Exit"));
	locations.push_back(room3);

	Location exit("exit", "This is the exit!");
	locations.push_back(exit);
}

Location* GameData::getStartLocation()
{
	if (locations.size() == 0) {
		return nullptr;
	}

	return &locations[0];
}

Location* GameData::getLocationWithId(const std::string& id)
{
	for (size_t i = 0; i < locations.size(); ++i) {
		if (locations[i].id == id) {
			return &locations[i];
		}
	}
	return nullptr;
}


