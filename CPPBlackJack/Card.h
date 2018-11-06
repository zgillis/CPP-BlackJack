/* C++ BlackJack		*
* By, Zachary Gillis	*/

#pragma once
#include <string>
class Card
{
public:
	enum class Value {
		ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	enum class Suit {
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
	Card(Value, Suit);
	~Card();
	Value getValue();
	Suit getSuit();
	std::string toString();
	int calcVal();
private:
	Value _value;
	Suit _suit;
};

