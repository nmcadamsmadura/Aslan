
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>
#include "Player.h"
#include "StrategoBoard.h"
#include "RotateFunctions.h"
#include "Piece.h"
using namespace std;
using namespace std::chrono;
void findAllAndRemove(deque<vector<vector<piece>>> test,int x, int y)
{
	for (int i = 0; i < test.size(); i++)
	{
		if (test.at(i)[x][y].guy == 12 | test.at(i)[x][y].guy == 13)
		{
			test.erase(remove(test.begin(), test.end(), test.at(i)), test.end());
		}
	}

}
void genPossibleOpInit()
{
	int testBoard[4][10] = { {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0} };

	int flagPos1[3][3] = { {0,12,0},
						   {12,13,12},
					    	{0,0,0}
	};
	int flagPos2[3][3] = { { 0,0,0 },
						   { 0,12,0 },
						   { 12,13,12 }
	};


	deque<vector<vector<int>>> flagRotations;
	flagRotations = rotate(flagPos2, flagPos2);


	//printGrid(testBoard);
	//cout << flagRotations.size() << endl;
	/*deque <vector<vector<piece>>> differentSetupsOpp;
	differentSetupsOpp = convertIntsAndInits(shiftThrough(flagRotations));
	vector<vector<piece>> exampleSetup(4,vector<piece>(10));
	Player p2;
	int l = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (l == 40) break;
			exampleSetup[i][k] = piece(Guy(p2.pces[l]), red);
			l++;
		}

	}*/
	/*while(!differentSetupsOpp.empty() | differentSetupsOpp.size() > 1)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (exampleSetup[k][j].guy != 12 | exampleSetup[k][j].guy != 13)
				{
					findAllAndRemove(differentSetupsOpp, k, j);
				}
			}
		}
	}*/
	//printGrid(differentSetupsOpp.at(0));
}

int main()
{
	//StrategoBoard newBoard;
	//newBoard.setupBoard();
	//newBoard.printCurrentBoard();

	system("PAUSE");
	return 0;
}

