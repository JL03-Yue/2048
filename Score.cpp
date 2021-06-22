#include <iostream>
#include "Score.h"
using namespace std;

Score::Score() :mScore(0) {

}

int Score::getScore() {
	return mScore;
}
void Score::addScore(int n)
{
	mScore += n;
}
bool Score::isWin(int n)
{
	if (n >= 2048)
		return true;
	return false;
}

void Score::printScore()
{
	cout << endl;
	cout << "################" << endl;
	cout << "Your score: "  << mScore<< endl;
	cout << "################" << endl;
	
}
