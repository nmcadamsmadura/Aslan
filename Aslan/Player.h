#ifndef Player_HEADER
#define Player_HEADER
#include <vector>
#include <deque>
#include <string>
using namespace std;
class Player
{
public:
	int pces[40];
	bool isAI;
	double prob[12];
	//This is for Aslan he'll be using a board set up used by master players
	//This will be final until I come up with a way to determine the best starting board strategy using an AI algorithm
	//It's called the "Shoreline Bluff" perfect to test the AI's bluff detection ;)
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
		isAI = true;
	}
	//This will be for the oppenent
	Player(int oppPc[],string name)
	{
		isAI = false;
	}

	/*************************************************************/
	/* THIS CODE IS BASED OFF THE CODE FROM PAGE 170 IN THE BOOK */
	/*************************************************************/
	/*int minValue(StrategoBoard tempboard,Player opp,Player ai,deque<piece> movablePiecesforOpp, deque<piece> movablePiecesforAi, deque<piece> capturedPiecesAI,deque<piece> capturedPiecesOpp, int alpha, int beta, bool oppFoundFlag,bool aiFoundFlag,int possibleFlagPosition[2]) {
		if (aiFoundFlag)
			return 1;
		else if (oppFoundFlag | capturedPiecesOpp.size() > 20)
			return -1;

		int v = INT_MAX; // based on code from page 170 in book
		piece temp;

		for (int i = 0; i < movablePiecesforOpp.size(); i++) { // for each action I can make in
												// sample hand
			if (possibleFlagPosition[0]-movablePiecesforOpp.at(i).pos[0] < 0) {
				oppFoundFlag = true;
				temp = movablePiecesforOpp.at(i);
				movablePiecesforOpp.erase(remove(movablePiecesforOpp.begin(), movablePiecesforOpp.end(), temp), movablePiecesforOpp.end());
				tempboard.makeMove(opp,temp,);
				v = (v < maxValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos)) ? v
					: maxValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos);
				if (v <= alpha) {
					oppFoundFlag = false;
					return v;
				}
				beta = (beta < v) ? beta : v;
				oppFoundFlag = false;
			}
			else {
				aiFoundFlag = true;
				temp = movablePiecesforOpp.at(i);
				movablePiecesforOpp.erase(remove(movablePiecesforOpp.begin(), movablePiecesforOpp.end(), temp), movablePiecesforOpp.end());
				v = (v < maxValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos)) ? v
					: maxValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos);
				if (v <= alpha) {
					aiFoundFlag = false;
					return v;
				}
				beta = (beta < v) ? beta : v;
				aiFoundFlag = false;
			}
			hand.add(i, playedpiecess.remove(playedpiecess.size() - 1));
		}
		return v;
	}

	private static int maxValue(StrategoBoard tempboard,Player opp,Player ai,deque<piece> movablePiecesforOpp, deque<piece> movablePiecesforAi, deque<piece> capturedPiecesAI,deque<piece> capturedPiecesOpp, int alpha, int beta, bool oppFoundFlag,bool aiFoundFlag,int possibleFlagPosition[2]) {
		
		if (aiFoundFlag)
		return 1;
		else if (oppFoundFlag | capturedPiecesOpp.size() > 20)
		return -1;

		int v = Integer.MIN_VALUE;
		piece temp;

		for (int i = 0; i < hand.size(); i++) {
			temp = movablePiecesforAI.at(i);
			movablePiecesforAI.erase(remove(movablePiecesforOpp.begin(), movablePiecesforOpp.end(), temp), movablePiecesforOpp.end());
			v = (v > minValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos)) ? v
				: minValue(tempBoard, opp, ai,movablePiecesForOpp,movablePiecesforAi, alpha, beta,oppFoundFlag, aiFoundFlag, possibleFlagPos);
			if (v >= beta) {
				return v;
			}
			alpha = (alpha > v) ? alpha : v;
		}
		return v;
	}
}	*/
};
#endif