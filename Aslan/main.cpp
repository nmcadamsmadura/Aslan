// Aslan.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "StrategoBoard.h"
using namespace std;
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

	system("PAUSE");
	return 0;
}

