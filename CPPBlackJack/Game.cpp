#include "Game.h"
#include <Windows.h>

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

Game::HandInfo Game::_calcHandPoints(vector<Card*> hand)
{
	HandInfo handInfo;
	handInfo.points = 0;
	int aceCount = 0;

	for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
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
	_playerHand.push_back(drawCard);
	cout << "Player gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

Card* Game::dealerHit(bool secret)
{
	Card* drawCard = _gameDeck.drawCard();
	_dealerHand.push_back(drawCard);
	if (secret)
		cout << "Dealer gets 1 card face down." << endl;
	else
		cout << "Dealer gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

void Game::playGame()
{
	bool playerStand = false;

	system("CLS");
	playerHit();
	Sleep(TEXT_SPEED);
	dealerHit(true);
	Sleep(TEXT_SPEED);
	playerHit();
	Sleep(TEXT_SPEED);
	dealerHit(false);
	Sleep(TEXT_SPEED);

	//Game loop
	while (true)
	{
		system("CLS");
		HandInfo playerInfo = calcPlayerHand();
		HandInfo dealerInfo = calcDealerHand();
		
		cout << "\nDEALER HAND: " << dealerInfo.text << endl
			   << "DEALER TOTAL: " << dealerInfo.points << endl;
		cout << "\nPLAYER HAND: " << playerInfo.text << endl
			   << "PLAYER TOTAL: " << playerInfo.points << endl << endl;

		if (playerInfo.points > 21) {
			cout << "PLAYER BUSTS! YOU LOST :(" << endl;
			Sleep(2000);
			getchar();
			system("CLS");
			break;
		}
		else if (dealerInfo.points > 21) {
			cout << "DEALER BUSTS! YOU WIN :)" << endl;
			Sleep(2000);
			getchar();
			system("CLS");
			break;
		}

		if (!playerStand)
		{
			cout << "Would you like to:" << endl
				<< "\t1. Hit" << endl
				<< "\t2. Stand" << endl;
			char choice = getchar();
			if (choice == '1') {
				system("CLS");
				playerHit();
				Sleep(TEXT_SPEED);
			}
			else if (choice == '2') {
				playerStand = true;
			}
			else {
				system("CLS");
				continue;
			}
		}
		else
		{
			if (dealerInfo.points < 17) {
				system("CLS");
				dealerHit(false);
				Sleep(TEXT_SPEED);
			}
			else {
				// TODO: deal with soft 17 (aces)
				// Stand 17+
				if (dealerInfo.points > playerInfo.points) {
					cout << "\nDEALER WINS! You lost :(" << endl;
					Sleep(2000);
					getchar();
					system("CLS");
				}
				else if (dealerInfo.points < playerInfo.points) {
					cout << "\PLAYER WINS! You won :(" << endl;
					Sleep(2000);
					getchar();
					system("CLS");
				}
				else {
					cout << "\nDEALER AND PLAYER PUSH. It's a tie!" << endl;
					Sleep(2000);
					getchar();
					system("CLS");
				}
				break;
			}
		}
	}
}
