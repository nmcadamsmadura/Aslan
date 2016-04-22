#include <array>
#include <vector>
#include <deque>
#include "Piece.h"
using namespace std;
class Player
{
public:
	int pces[40];
	bool isAI;
	double prob[12];
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
		prob[0] = 1 / 40;
		prob[1] = 8 / 40;
		prob[2] = 5 / 40;
		prob[3] = 4 / 40;
		prob[4] = 4 / 40;
		prob[5] = 4 / 40;
		prob[6] = 3 / 40;
		prob[7] = 2 / 40;
		prob[8] = 1 / 40;
		prob[9] = 1 / 40;
		prob[10] = 6 / 40;
		prob[11] = 1 / 40;
		isAI = true;
	}
	//This will be for the oppenent
	Player(int oppPc[])
	{
		isAI = false;
	}
	//We should only generate all possible moves when in danger. s
	//Though we could generate a stocastic state machine
	/* To Explain, an SSM uses multiple probabilities of that state. 
	In this case, the multiple probabilities would be several set examples. 
	In other words, find probabilities of certain SPECIFIC states happening.
	We could generate a few specific states using the monte carlo technique we 
	used for the cards. Then generate the possibility of those specific states and use 
	them to 
	*/
	/*vector<int> genpossiblepieces()
	{
		vector<int> possibleRow;
		for (int k = 0; k < ; k++) {
		}
		// Awesome so we've made the possible cards that can be played
		return possibleCards;
		// Okay now we need to make hands and test them against current hands
	}*/


	/*int * moveAI(int piecePlc[][] )
	{
		int tempHandSize = sizeof(AiRow) / sizeof(AiRow[0]);
		int c [2];
		array<int,10> tempHand = AiRow;
		array<int, 10> tempPlayed = OppRow;
		int wins[30];
		// generate possible handss
		vector<int> test;
		test = genpossibleCards(hand, playedCards, trump);
		combinationUtil(test, data, 0, 21, 0, 7);
		for (int k = 0; k < 2; k++) {
			ArrayList<Card> opponentHand = new ArrayList<Card>();
			for (int i = 0; i < minHands.get(k).size(); i++) {
				opponentHand.add(minHands.get(k).get(i));
			}

			for (int j = 0; j < hand.size(); j++) {
				c = tempHand.remove(j);
				tempPlayed.add(c);
				if ((minValue(opponentHand, tempHand, tempPlayed, trump, trick1, trick2, Integer.MIN_VALUE,
					Integer.MAX_VALUE) > 0) & (endTime - startTime) / 1000000000.0 > 7)
					wins[j]++;
				// undo the move for the next iteration
				tempHand.add(j, tempPlayed.remove(tempPlayed.size() - 1));
			}
		}

		return findBestCard(tempHand, wins);
	}*/
	
};