#pragma once
#include "Piece.h"
#include<iomanip>
using namespace std;
class StrategoBoard
{
private:
	piece * board[10][10];
public:
	StrategoBoard()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k <10; k++)
			{
				board[i][k] = new piece(space);
			}
		}

		//Adds water to the board.
		board[4][2] = new piece(water);
		board[4][3] = new piece(water);
		board[5][2] = new piece(water);
		board[5][3] = new piece(water);
		board[4][6] = new piece(water);
		board[4][7] = new piece(water);
		board[5][6] = new piece(water);
		board[5][7] = new piece(water);
	}
	int * makeMove(Player p, int x, int y)
	{
		int * move;
		if (!p.isAI)
		{
			cout << "Do you wish to move Player " << p.isAI << " to position " << x << "," << y << "?" << endl;
			move[0] = x;
			move[1] = y;
		}
		else
		{
			//This is where the ai will go through minimax algorithm
			cout << "AI makes move " << endl;
			//MTDF(n);
		}
	}
	void printCurrentBoard()
	{
		for (int i = 9; i >= 0; i--)
		{

			for (int k = 9; k >= 0; k--)
			{
				cout << *board[i][k] << "    ";
			}
			cout << endl;
			cout << endl;
		}
		cout << endl;
	}
	void setupBoard()
	{
		Player p1;
		Player p2;
		int j = 0;
		for (int i = 3; i >= 0; i--)
		{
			for (int k = 0; k < 10; k++)
			{
				if (j == 40) break;
				//cout << guys[p.pces[k*j]] << endl;
				board[i][k] = new piece(Guy(p1.pces[j]), blue);
				j++;
			}

		}
		int l = 0;
		for (int i = 9; i >= 6; i--)
		{
			for (int k = 0; k < 10; k++)
			{
				if (l == 40) break;
				//cout << guys[p.pces[k*j]] << endl;
				board[i][k] = new piece(Guy(p2.pces[l]), red);
				l++;
			}

		}
	}
};
