#include "utilities.h"
#include <random>
#include <utility>
#include <windows.h>
#include <conio.h>
using namespace std;

static random_device rd;
static default_random_engine generator(rd());

int randInt(int limit)
{
	uniform_int_distribution<> dist(0, limit - 1);
	return dist(generator);
}

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperleft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperleft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperleft);

}

char getCharacter()
{
	char input;
	input = _getch();
	return input;
}

