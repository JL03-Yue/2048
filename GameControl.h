#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class GameControl
{
public:
	GameControl();
	//Player getPlayer();
	Board* getBoard();
	void printTitle();


private:
	//score
	int mScore;
	//board
	Board *mBoard;
	//Player mPlayer;

};
#endif // !GAME_H

