#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include "Card.h"

using namespace std;

class Deck
{
	vector<Card> _cardList;
	vector<Card>::iterator _deckPoint;
public:
	Deck();
	~Deck();
	Card* DrawCard();
};

