#include "tictactoe.h"

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';

	cxpos = cypos = 0;
	firstplayer = true;
}
TicTacToe::~TicTacToe()
{

}

void TicTacToe::drawBoard()
{
	char a, b, c, d, e, f, g, h, i = ' ';

	if (cxpos == 0 && cypos == 0)
		a = '+';
	else
		a = board[0][0];

	if (cxpos == 0 && cypos == 1)
		b = '+';
	else
		b = board[0][1];
	if (cxpos == 0 && cypos == 2)
		c = '+';
	else
		c = board[0][2];
	if (cxpos == 1 && cypos == 0)
		d = '+';
	else
		d = board[1][0];
	if (cxpos == 1 && cypos == 1)
		e = '+';
	else
		e = board[1][1];
	if (cxpos == 1 && cypos == 2)
		f = '+';
	else
		f = board[1][2];
	if (cxpos == 2 && cypos == 0)
		g = '+';
	else
		g = board[2][0];
	if (cxpos == 2 && cypos == 1)
		h = '+';
	else
		h = board[2][1];
	if (cxpos == 2 && cypos == 2)
		i = '+';
	else
		i = board[2][2];

	system("CLS");

	cout << " -------" << endl;
	cout << " |" << a << "|" << b << "|" << c << "|" << endl ;

	cout << " -------" << endl;
	cout << " |" << d << "|" << e << "|" << f << "|" << endl;

	cout << " -------" << endl;
	cout << " |" << g << "|" << h << "|" << i << "|" << endl;

	cout << " -------" << endl;
}

void TicTacToe::update()
{
	this->drawBoard();
	int ch;

	do {
		if (checkForWinner() == 1)
		{
			cout << "X wins" << endl;
			break;
		}
		else if (checkForWinner() == 2)
		{
			cout << "O wins" << endl;
			break;
		}
		ch = _getch();
		ch = toupper(ch);

		if (ch == 'W' && cxpos != 0)
			cxpos--;
		if (ch == 'S' && cxpos != 2)
			cxpos++;
		if (ch == 'A' && cypos != 0)
			cypos--;
		if (ch == 'D' && cypos != 2)
			cypos++;

		if (ch == ' ' && firstplayer)
		{
			if (board[cxpos][cypos] == 'O' || board[cxpos][cypos] == 'X')
				board[cxpos][cypos] = board[cxpos][cypos];

			else
			{
				setO(cxpos, cypos);
				firstplayer = !firstplayer;
			}
		}

		if (ch == ' ' && !firstplayer)
		{
			if (board[cxpos][cypos] == 'O' || board[cxpos][cypos] == 'X')
				board[cxpos][cypos] = board[cxpos][cypos];

			else
			{
				setX(cxpos, cypos);
				firstplayer = !firstplayer;
			}

		}
		this->drawBoard();
	} while (ch != 'Q');

	
}

int TicTacToe::checkForWinner()
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 1;
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 2;

	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 1;
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 2;

	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 1;
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 2;

	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return 1;
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		return 2;

	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return 1;
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return 2;

	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return 1;
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return 2;

	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 1;
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 2;

	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
		return 1;
	if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
		return 2;

	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 1;
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 2;
}
