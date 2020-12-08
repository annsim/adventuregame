#pragma once

#include "player.h"
#include "gamedata.h"


class Game {
public:
	GameData gameData;
	Player player;

	void run();
	
private:

	bool isRunning = true;
};
