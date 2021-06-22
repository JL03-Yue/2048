#include "Board.h"
#include "utilities.h"
#include <iostream>
#include <iomanip>
#include "Score.h"


using namespace std;

Board::Board() {
	//the position of two random number
	int x1, x2, y1, y2;

	do {
		x1 = randInt(ROW);
		y1 = randInt(COL);
		x2 = randInt(ROW);
		y2 = randInt(COL);

	} while ((x1 == x2) &&( y1 == y2));

	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			//1st rand num
			if (x1 == i && y1 == j)
			{
				int num = (randInt(ROW) % 2 + 1) * 2;
				this->mBoard[i][j] = num;
			}
			//2nd rand num
			else if (x2 == i && y2 == j)
			{
				int num = (randInt(ROW) % 2 + 1) * 2;
				this->mBoard[i][j] = num;
			}
			else
			{
				this->mBoard[i][j] = 0;
			}

		}
	}

}

void Board::setGrid(int r, int c, int cell) {
	mBoard[r][c] = cell;
}

int Board::getGrid(int r, int c) const
{
	if (r < ROW && r >= 0 && c < COL && c >= 0)
	{
		return this->mBoard[r][c];
	}
	else {
		exit(0);
	}
}


void Board::printBoard() {
	for (int i = 0;i < ROW;i++)
	{
		cout << "---------------------" << endl;
		cout << "|";
		for (int j = 0;j < COL;j++)
		{
			
			if (this->mBoard[i][j] == 0)
			{
				cout << setw(4) << " " << "|";
			}
			else
			{
				cout << setw(4) << this->mBoard[i][j] << "|";
			}
			
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
}

void Board::move(char ch) {
	switch (ch)
	{
	case 'w':
		up();
		break;
	case 's':
		down();
		break;
	case 'a':
		left();
		break;
	case 'd':
		right();
		break;
	case 'q':
		exit(0);
		break;

	default:
		return;
	}
}

//each direction
void Board::up() {
	for (int k = 0;k < ROW - 1;k++)
	{
		for (int i = 0;i < ROW - 1;i++)
		{
			for (int j = 0;j < ROW;j++)
			{
				//if mBoard[i][j] is empty
				if (mBoard[i][j] == 0)
				{
					this->mBoard[i][j] = this->mBoard[i + 1][j];
					this->mBoard[i + 1][j] = 0;
				}
				//else if mBoard[i][j] is the same as mBoard[i+1][j]
				else if (this->mBoard[i][j] == this->mBoard[i + 1][j])
				{
					mScore.addScore(this->mBoard[i][j]);
					this->mBoard[i][j] = this->mBoard[i + 1][j] + this->mBoard[i][j];
					this->mBoard[i + 1][j] = 0;

				}
			}
		}
	}
}
void Board::down() {
	for (int k = 0;k < ROW - 1;k++)
	{
		for (int i = ROW - 1;i > 0;i--)
		{
			for (int j = 0;j < ROW;j++)
			{
				//if mBoard[i][j] is empty
				if (this->mBoard[i][j] == 0)
				{
					this->mBoard[i][j] = this->mBoard[i - 1][j];
					this->mBoard[i - 1][j] = 0;
				}
				//else if mBoard[i][j] is the same as mBoard[i-1][j]
				else if (this->mBoard[i][j] == this->mBoard[i - 1][j])
				{
					mScore.addScore(this->mBoard[i][j]);
					this->mBoard[i][j] = this->mBoard[i - 1][j] + this->mBoard[i][j];
					this->mBoard[i - 1][j] = 0;
				}
			}
		}
	}
}

//move left 
void Board::left() {
	for (int k = 0;k < COL - 1;k++)
	{
		for (int i = 0;i < COL;i++)
		{
			for (int j = 0;j < COL - 1;j++)
			{
				//if mBoard[i][j] is empty
				if (this->mBoard[i][j] == 0)
				{
					this->mBoard[i][j] = this->mBoard[i][j + 1];
					this->mBoard[i][j + 1] = 0;
				}
				//else if mBoard[i][j] is the same as mBoard[i][j + 1]
				else if (this->mBoard[i][j] == this->mBoard[i][j + 1])
				{
					mScore.addScore(this->mBoard[i][j]);
					this->mBoard[i][j] = this->mBoard[i][j] + this->mBoard[i][j + 1];
					this->mBoard[i][j + 1] = 0;
				}
			}
		}
	}
}
void Board::right() {
	for (int k = 0;k < COL - 1;k++)
	{
		for (int i = 0;i < COL;i++)
		{
			for (int j = COL - 1;j > 0;j--)
			{
				//if mBoard[i][j] is empty
				if (this->mBoard[i][j] == 0)
				{
					this->mBoard[i][j] = this->mBoard[i][j - 1];
					this->mBoard[i][j - 1] = 0;
				}
				//else if mBoard[i][j] is the same as mBoard[i][j - 1]
				else if (this->mBoard[i][j] == this->mBoard[i][j - 1])
				{
					mScore.addScore(this->mBoard[i][j]);
					this->mBoard[i][j] = this->mBoard[i][j] + this->mBoard[i][j - 1];
					this->mBoard[i][j - 1] = 0;
				}
			}
		}
	}
}

void Board::updateBoard()
{

		int x = rand() % ROW;
		int y = rand() % COL;
		do {
			x = rand() % ROW;
			y = rand() % COL;
		} while (this->mBoard[x][y] != 0);

		int num = (rand() % 2 + 1) * 2;
		this->mBoard[x][y] = num;

}

void Board::printScoreBoard()
{
	mScore.printScore();
}


bool Board::isLose()
{
	bool isFilled = true;
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			if (this->mBoard[i][j] == 0)
			{
				isFilled = false;
				break;
			}

		}
	}

	return isFilled;
}


bool Board::isWin()
{
	for (int i = 0;i < ROW;i++)
	{
		for (int j = 0;j < COL;j++)
		{
			if (this->mBoard[i][j] == 2048)
			{
				return true;
			}

		}
	}
	return false;
}