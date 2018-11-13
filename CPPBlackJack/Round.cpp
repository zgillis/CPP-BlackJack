#include "Round.h"
#include <Windows.h>

using namespace std;

Round::HandInfo Round::calcDealerHand()
{
	return CalcHandPoints(_dealerHand);
}

Round::HandInfo Round::calcPlayerHand()
{
	return CalcHandPoints(_playerHand);
}

Round::HandInfo Round::CalcHandPoints(vector<Card*> hand)
{
	HandInfo handInfo;
	handInfo.points = 0;
	int aceCount = 0;

	for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		Card* currentCard = *it;
		handInfo.text.append(currentCard->toString() + ((it == (hand.end() - 1)) ? " " : ", "));

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

Card* Round::PlayerHit()
{
	Card* drawCard = _gameDeck.DrawCard();
	_playerHand.push_back(drawCard);
	cout << "Player gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

Card* Round::DealerHit(bool secret)
{
	Card* drawCard = _gameDeck.DrawCard();
	_dealerHand.push_back(drawCard);
	if (secret)
		cout << "Dealer gets 1 card face down." << endl;
	else
		cout << "Dealer gets " << drawCard->toString().c_str() << "." << endl;
	return drawCard;
}

int Round::PlayRound()
{
	bool playerStand = false;

	system("CLS");
	PlayerHit();
	Sleep(TEXT_SPEED);
	DealerHit(true);
	Sleep(TEXT_SPEED);
	PlayerHit();
	Sleep(TEXT_SPEED);
	DealerHit(false);
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
			cout << "PLAYER BUSTS!" << endl;
			cout << "\DEALER WINS! You lost :(" << endl;
			Sleep(2000);
			getchar();
			system("CLS");
			return Round::DealerWin;
		}
		else if (dealerInfo.points > 21) {
			cout << "DEALER BUSTS!" << endl;
			cout << "\nPLAYER WINS! You won :(" << endl;
			Sleep(2000);
			getchar();
			system("CLS");
			return Round::PlayerWin;
		}

		if (!playerStand)
		{
			cout << "Would you like to:" << endl
				<< "\t1. Hit" << endl
				<< "\t2. Stand" << endl;
			char choice = getchar();
			if (choice == '1') {
				system("CLS");
				PlayerHit();
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
				DealerHit(false);
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
					return Round::DealerWin;
				}
				else if (dealerInfo.points < playerInfo.points) {
					cout << "\nPLAYER WINS! You won :(" << endl;
					Sleep(2000);
					getchar();
					system("CLS");
					return Round::PlayerWin;
				}
				else {
					cout << "\nDEALER AND PLAYER PUSH. It's a tie!" << endl;
					Sleep(2000);
					getchar();
					system("CLS");
					return Round::Push;
				}
				break;
			}
		}
	}
}
