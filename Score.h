#ifndef SCORE_H
#define SCORE_H

class Score {
public:
	Score();
	int getScore();
	void addScore(int n);
	bool isWin(int n);
	bool isLose();
	void printScore();
	
private:
	int mScore;
};
#endif // !SCORE_H

