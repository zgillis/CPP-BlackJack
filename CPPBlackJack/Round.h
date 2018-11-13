#pragma once
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <iterator>
#include <string>
#include <iostream>

#define TEXT_SPEED 1000


class Round
{
	struct HandInfo {
		int points;
		string text;
	};
	vector<Card*> _playerHand;
	vector<Card*> _dealerHand;
	Deck _gameDeck;
	HandInfo CalcHandPoints(vector<Card*>);
protected:
	HandInfo calcPlayerHand();
	HandInfo calcDealerHand();
	Card* DealerHit(bool);
	Card* PlayerHit();
public:
	enum {
		PlayerWin,
		DealerWin,
		Push
	};
	int PlayRound();
};

