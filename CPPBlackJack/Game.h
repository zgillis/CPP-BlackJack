#pragma once
#include "Round.h"
#define STARTER_CHIPS 500

class Game
{
	int _playerChips;
public:
	Game();
	~Game();
	void PlayGame();
};

