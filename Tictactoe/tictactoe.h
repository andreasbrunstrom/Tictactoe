#pragma once
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cctype>

using namespace std;
class TicTacToe 
{
private:
	char board[3][3];
	int cxpos, cypos;
	bool firstplayer;

public:
	TicTacToe();
	~TicTacToe();

	void drawBoard();
	void setO(int x, int y) { board[x][y] = 'O'; }
	void setX(int x, int y) { board[x][y] = 'X'; }
	void setCXpos(int x) { cxpos = x; }
	void setCYpos(int y) { cypos = y; }
	void update();
	int checkForWinner();

};
