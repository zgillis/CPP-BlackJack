/* C++ BlackJack		*
* By, Zachary Gillis	*/

#include "Card.h"

Card::Card(Value value, Suit suit)
{
	_value = value;
	_suit = suit;
}

Card::~Card()
{
}

Card::Value Card::getValue()
{
	return _value;
}

Card::Suit Card::getSuit()
{
	return _suit;
}

int Card::calcVal()
{
	int val;
	switch (_value) {
	case(Value::ACE):
		val = 1;
		break;
	case(Value::TWO):
		val = 2;
		break;
	case(Value::THREE):
		val = 3;
		break;
	case(Value::FOUR):
		val = 4;
		break;
	case(Value::FIVE):
		val = 5;
		break;
	case(Value::SIX):
		val = 6;
		break;
	case(Value::SEVEN):
		val = 7;
		break;
	case(Value::EIGHT):
		val = 8;
		break;
	case(Value::NINE):
		val = 9;
		break;
	case(Value::TEN):
		val = 10;
		break;
	case(Value::JACK):
		val = 10;
		break;
	case(Value::QUEEN):
		val = 10;
		break;
	case(Value::KING):
		val = 10;
		break;
	}

	return val;
}

std::string Card::toString()
{
	std::string val, suit;
	switch (_value) {
	case(Value::ACE):
		val = "ACE";
		break;
	case(Value::TWO):
		val = "TWO";
		break;
	case(Value::THREE):
		val = "THREE";
		break;
	case(Value::FOUR):
		val = "FOUR";
		break;
	case(Value::FIVE):
		val = "FIVE";
		break;
	case(Value::SIX):
		val = "SIX";
		break;
	case(Value::SEVEN):
		val = "SEVEN";
		break;
	case(Value::EIGHT):
		val = "EIGHT";
		break;
	case(Value::NINE):
		val = "NINE";
		break;
	case(Value::TEN):
		val = "TEN";
		break;
	case(Value::JACK):
		val = "JACK";
		break;
	case(Value::QUEEN):
		val = "QUEEN";
		break;
	case(Value::KING):
		val = "KING";
		break;
	}

	switch (_suit) {
	case(Suit::CLUBS):
		suit = "CLUB";
		break;
	case(Suit::DIAMONDS):
		suit = "DMND";
		break;
	case(Suit::HEARTS):
		suit = "HEART";
		break;
	case(Suit::SPADES):
		suit = "SPADE";
	}

	return val + " of " + suit;
}
