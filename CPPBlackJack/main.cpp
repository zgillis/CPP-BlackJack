/* C++ BlackJack		*
 * By, Zachary Gillis	*/

#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Game.h"

using namespace std;

void playGame()
{

}

int main()
{
	system("CLS");
	cout << "Welcome to CPP BlackJack - Zach Gillis" << endl
		<<  "======================================" << endl << endl;

	// Game menu loop
	while (true)
	{
		cout << "Please choose an option:\n"
				<< "\t1. Start a new game\n"
				<< "\t2. Exit\n\n>";

		char choice = getchar();
		getchar(); // Toss out the return key press

		system("CLS");
		if (choice == '1') {
			Game game = Game();
			game.playGame();
		}
		else if (choice == '2')
			return 0;
		else
			cout << "INVALID CHOICE\n\n";
	}
	return 0;
}

