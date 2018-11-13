/* C++ BlackJack		*
 * By, Zachary Gillis	*/

#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Round.h"
#include "Game.h"

using namespace std;


int main()
{
	system("CLS");

	// Game menu loop
	while (true)
	{
		cout << "Welcome to CPP BlackJack - Zach Gillis" << endl
			<< "======================================" << endl << endl;
		cout << "Please choose an option:\n\n"
				<< "\t1. Start a new game\n"
				<< "\t2. Exit\n\n>";

		char choice = getchar();
		getchar(); // Toss out the return key press

		system("CLS");
		if (choice == '1') {
			//TODO: Insert start game logic
			Game game = Game();
			game.PlayGame();
		}
		else if (choice == '2')
			return 0;
		else
			cout << "INVALID CHOICE\n\n";
	}
	return 0;
}

