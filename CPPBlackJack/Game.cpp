#include "Game.h"

using namespace std;

Game::Game()
{

}

Game::~Game()
{
}

Game::HandInfo Game::calcDealerHand()
{
	return _calcHandPoints(_dealerHand);
}

Game::HandInfo Game::calcPlayerHand()
{
	return _calcHandPoints(_playerHand);
}

Game::HandInfo Game::_calcHandPoints(list<Card*> hand)
{
	HandInfo handInfo;
	handInfo.points = 0;
	int aceCount = 0;

	for (list<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		Card* currentCard = *it;
		handInfo.text.append(currentCard->toString() + " ");

		if (currentCard->calcVal() == 1)
			aceCount++;
		else
			handInfo.points += currentCard->calcVal();
	}

	for (int i = 0; i < aceCount; i++)
	{
		if (handInfo.points + 11 > 21)
			handInfo.points++;
		else
			handInfo.points += 11;
	}

	return handInfo;
}

Card* Game::playerHit()
{
	Card* drawCard = _gameDeck.drawCard();
	_dealerHand.push_back(drawCard);
	cout << "Player gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

Card* Game::dealerHit(bool secret)
{
	Card* drawCard = _gameDeck.drawCard();
	_playerHand.push_back(drawCard);
	if (secret)
		cout << "Dealer gets 1 card face down." << endl;
	else
		cout << "Dealer gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

void Game::playGame()
{
	system("CLS");
	playerHit();
	dealerHit(true);
	playerHit();
	dealerHit(false);

	//Game loop
	while (true)
	{
		HandInfo playerInfo = calcPlayerHand();
		HandInfo dealerInfo = calcDealerHand();
		
		cout << "\nDEALER HAND: " << dealerInfo.text << endl
			   << "DEALER TOTAL: " << dealerInfo.points << endl << endl;
		cout << "\nPLAYER HAND: " << playerInfo.text << endl
			   << "PLAYER TOTAL: " << playerInfo.points << endl << endl;

		cout << "Would you like to:" << endl
				<< "\t1. Hit" << endl
				<< "\t2. Stand" << endl;
		char choice = getchar();
		if (choice == '1') {

		}
		else if (choice == '2') {

		}
		else {
			system("CLS");
			continue;
		}
	}
}
