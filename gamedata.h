#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct LocationChoice {
	LocationChoice(const std::string& nextId, const std::string& aText);

	std::string locationId;
	std::string text;
};

struct Location {
	Location(const std::string& anId, const std::string& aText);

	std::string id;
	std::string text;
	std::vector<LocationChoice> choices;
};

class GameData {

public:
	GameData();
	void debugLocations();

	Location* getStartLocation();
	Location* getLocationWithId(const std::string& id);
	
private:
	void createLocations();
	std::vector<Location>locations;
};




