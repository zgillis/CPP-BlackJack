#pragma once
#include "Card.h"
#include "Deck.h"
#include <list>
#include <iterator>
#include <string>
#include <iostream>

class Game
{
	struct HandInfo {
		int points;
		string text;
	};
	list<Card*> _playerHand;
	list<Card*> _dealerHand;
	Deck _gameDeck;
	HandInfo _calcHandPoints(list<Card*>);
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

