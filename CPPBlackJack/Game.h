#pragma once
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <iterator>
#include <string>
#include <iostream>

#define TEXT_SPEED 1000


class Game
{
	struct HandInfo {
		int points;
		string text;
	};
	vector<Card*> _playerHand;
	vector<Card*> _dealerHand;
	Deck _gameDeck;
	HandInfo _calcHandPoints(vector<Card*>);
protected:
	HandInfo calcPlayerHand();
	HandInfo calcDealerHand();
	Card* dealerHit(bool);
	Card* playerHit();
public:
	Game();
	~Game();
	
	void playGame();
};

