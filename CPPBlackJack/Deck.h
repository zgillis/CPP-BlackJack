#pragma once
#include <list>
#include <iterator>
#include "Card.h"

using namespace std;

class Deck
{
	list<Card> _cardList;
	list<Card>::iterator _deckPoint;
public:
	Deck();
	~Deck();
	Card* drawCard();
};

