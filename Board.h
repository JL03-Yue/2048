#ifndef BOARD_H
#define BOARD_H


#define COL 4
#define ROW 4
#include "Score.h"

class Board
{
public:
	Board();
	void printBoard();
	int getGrid(int r, int c) const;
	void setGrid(int r, int c, int cell);
	void updateBoard();
	void move(char ch);
	bool isLose();
	bool isWin();
	void printScoreBoard();
private:
	int mBoard[ROW][COL] = { 0 };
	Score mScore;

	void up();
	void down();
	void left();
	void right();

};



#endif // !BOARD_H
