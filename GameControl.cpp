#include <iostream>
#include "GameControl.h"
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "utilities.h"
#include "Board.h"
using namespace std;

using namespace std;

GameControl::GameControl():mScore(0) {
	mBoard = new Board();
}

void GameControl::printTitle() {
	cout << "###################################################" << endl;

	cout << "------------------Simple 2048 v1-------------------" << endl;
	cout << "###################################################" << endl << endl;
	cout << "Press 'w' 's' 'a' 'd' to control the game" << endl;
	cout << "Press 'q' to quit" << endl;
	cout << "Press 'n' to start a new game" << endl;
}
Board* GameControl::getBoard()
{
	return mBoard;
}

int main() {
	



	//Initialize the game
	GameControl myGame;
	myGame.printTitle();
	myGame.getBoard()->printBoard();
	myGame.getBoard()->printScoreBoard();

	char c = 0;
	do
	{
		//getChar
		c = getCharacter();

		if (c == 'w' || c == 's' || c == 'a' || c == 'd')
		{
			//proceed
			myGame.getBoard()->move(c);
			if (myGame.getBoard()->isWin())
			{
				cout << "You Win!!!" << endl;
				break;
			}
			if (myGame.getBoard()->isLose())
			{
				cout << "You Lose:(" << endl;
				break;
			}
			myGame.getBoard()->updateBoard();

			//clean the board
			clearScreen();
			myGame.printTitle();
			myGame.getBoard()->printBoard();
			myGame.getBoard()->printScoreBoard();



		}
		else if (c == 'n')
		{
			clearScreen();
			GameControl myGame;
			myGame.printTitle();
			myGame.getBoard()->printBoard();
			myGame.getBoard()->printScoreBoard();
		}
		else if (c == 'q')
		{
			break;
		}
		else
		{
			//clean the board
			clearScreen();
			myGame.printTitle();
			myGame.getBoard()->printBoard();
			myGame.getBoard()->printScoreBoard();
		}




	} while (!myGame.getBoard()->isWin());

	return 0;
}