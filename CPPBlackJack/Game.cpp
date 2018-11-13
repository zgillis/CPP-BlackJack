#include "Game.h"
#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
	
}


Game::~Game()
{

}

void Game::PlayGame()
{
	_playerChips = STARTER_CHIPS;

	while (_playerChips > 0)
	{
		system("CLS");
		cout << "PLAYER CHIPS:\t$" << _playerChips << endl << endl;
		cout << "Round about to start. What's your bet (Ex: 100)? ";
		int bet = 0;
		cin >> bet;

		if (cin.fail()) {
			system("CLS");
			cout << "You must enter an integer value to bet.";
			Sleep(2000);
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		else if (bet < 1) {
			system("CLS");
			cout << "You must bet at least 1!";
			Sleep(2000);
			continue;
		}
		else if (bet > _playerChips) {
			system("CLS");
			cout << "You cannot bet more chips than you have.";
			Sleep(2000);
			continue;
		}

		system("CLS");
		cout << "You are betting $" << bet << ".";
		Sleep(2000);

		Round currentRound = Round();
		int roundResult = currentRound.PlayRound();

		if (roundResult == Round::DealerWin)
			_playerChips -= bet;
		else if (roundResult == Round::PlayerWin)
			_playerChips += bet;
	}

	system("CLS");
	cout << "PLAYER CHIPS:\t$" << _playerChips << endl << endl;
	cout << "YOU ARE OUT OF CHIPS. GAME OVER :(" << endl <<endl;
	Sleep(3000);
}
