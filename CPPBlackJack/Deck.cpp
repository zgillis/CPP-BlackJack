#include "Deck.h"
#include <vector>

using namespace std;

Deck::Deck()
{
	_cardList.push_back(Card(Card::Value::ACE, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::ACE, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::TWO, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::THREE, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::FOUR, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::FIVE, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::SIX, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::SEVEN, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::EIGHT, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::NINE, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::TEN, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::JACK, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::QUEEN, Card::Suit::CLUBS));
	_cardList.push_back(Card(Card::Value::KING, Card::Suit::CLUBS));

	_cardList.push_back(Card(Card::Value::ACE, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::TWO, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::THREE, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::FOUR, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::FIVE, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::SIX, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::SEVEN, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::EIGHT, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::NINE, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::TEN, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::JACK, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::QUEEN, Card::Suit::DIAMONDS));
	_cardList.push_back(Card(Card::Value::KING, Card::Suit::DIAMONDS));

	_cardList.push_back(Card(Card::Value::ACE, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::TWO, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::THREE, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::FOUR, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::FIVE, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::SIX, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::SEVEN, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::EIGHT, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::NINE, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::TEN, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::JACK, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::QUEEN, Card::Suit::HEARTS));
	_cardList.push_back(Card(Card::Value::KING, Card::Suit::HEARTS));

	_cardList.push_back(Card(Card::Value::ACE, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::TWO, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::THREE, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::FOUR, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::FIVE, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::SIX, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::SEVEN, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::EIGHT, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::NINE, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::TEN, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::JACK, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::QUEEN, Card::Suit::SPADES));
	_cardList.push_back(Card(Card::Value::KING, Card::Suit::SPADES));

	// TODO: add shuffling.

	// Initialize iterator
	_deckPoint = _cardList.begin();
}


Deck::~Deck()
{
}

Card* Deck::drawCard()
{
	Card* nextCard = NULL;
	_deckPoint++;
	if (_deckPoint != _cardList.end())
		nextCard = &*_deckPoint;
	return nextCard;
}
