// Aslan.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum Guy {
	space, water, marshal, general, colonels, majors, captains, lieutenants, sergeants,
	miners, scouts, spy, bomb, flag, board1
};
string guys[] = { "space","water","marshal","general","colonel","major","captain","lieutenant", "sergeant",
"miner","scout","spy","bomb","flag","board" };
enum Color { red, blue };
class piece
{
public:
	int value;
	Guy guy;
	Color col;
	piece(Guy g, Color c)
	{
		guy = g;
		col = c;
	}
	piece(Guy g)
	{
		guy = g;
	}
	piece()
	{

	}

	friend ostream& operator<<(ostream &os, const piece& pc);
};
ostream& operator<<(ostream& os, const piece& pc)
{
	if (pc.guy > 1 & pc.guy != 13 & pc.guy != 12)
	{
		pc.col == 0 ? os << "*" : os << "B" << pc.guy;
		return os;
	}
	else if (pc.guy == 0)
	{
		os << "SP";
		return os;
	}
	else if (pc.guy == 1)
	{
		os << "WA";
		return os;
	}
	else if (pc.guy == 12)
	{
		pc.col == 0 ? os << "*" : os << "BM";
		return os;
	}
	else if (pc.guy == 13)
	{
		pc.col == 0 ? os << "*" : os << "F";
		return os;
	}
	else if (pc.guy == 14)
	{
		os << "0";
		return os;
	}
}
class Player
{
public:
	int pces[40];
	bool isAI;
	//This is for Aslan he'll be using a board set up used by master players
	//This will be final until I come up with a way to determine the best starting board strategy using an AI algorithm
	//It's called the "Shoreline Bluff" perfect for tests the AI's bluff detection ;)
	//The setup was given no full citation but can be found here: http://www.ultrastratego.com/setups.php
	Player() {
		int initBoard[] = { 2,2,12,13,12,12,4,2,2,2,
			7,9,8,12,10,7,12,3,8,7,
			5,4,6,6,3,3,6,2,6,5,
			2,4,3,5,2,11,4,12,5,3 };
		for (int k = 0; k < 40; k++)
		{
			pces[k] = initBoard[k];
		}
		isAI = false;
	}
	//This will be for the oppenent
	Player(int oppPc[])
	{
		isAI = true;
	}
};
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
	void makeMove(Player p, int x, int y)
	{
		if (!p.isAI)
			cout << "Do you wish to move " << << " to position " << x << "," << y << "?" << endl;
		else
			//This is where the ai will go through minimax algorithm
			cout << "AI makes move " << endl;
		
		

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


/*2 2 B F B B 4 2 2 2
*7 9 8 B 10 7 B 3 8 7
*5 4 6 6 3 3 6 2 6 5
*2 4 3 5 2 S 4 B 5 3
*
*/


int main()
{
	StrategoBoard newBoard;
	newBoard.setupBoard();
	newBoard.printCurrentBoard();
	Player p;
	piece pc(marshal, blue);
	p.makeMove(pc, 1, 2);

	system("PAUSE");
	return 0;
}

