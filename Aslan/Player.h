#ifndef Player_HEADER
#define Player_HEADER
#include <vector>
#include <deque>
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
	Player(int oppPc[])
	{
		isAI = false;
	}

	/*************************************************************/
	/* THIS CODE IS BASED OFF THE CODE FROM PAGE 170 IN THE BOOK */
	/*************************************************************/
	/*int minValue(StrategoBoard tempboard,Player opp,Player ai,deque<piece> movablePiecesforOpp, deque<piece> movablePiecesforAi, deque<piece> capturedPiecesAI,deque<piece> capturedPiecesOpp, int alpha, int beta, bool oppFoundFlag,bool aiFoundFlag,int possibleFlagPosition[2]) {
		Player ai();
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
				v = (v < maxValue(opponent, hand, playedCards, trump, oppFoundFlag, aiFoundFlag, alpha, beta)) ? v
					: maxValue(opponent, hand, playedCards, trump, tricks1, tricks2, alpha, beta);
				if (v <= alpha) {
					tricks2--;
					hand.add(i, playedCards.remove(playedCards.size() - 1));
					return v;
				}
				beta = (beta < v) ? beta : v;
				oppFoundFlag = false;
			}
			else {
				tricks1++;
				temp = hand.remove(i);
				playedCards.add(temp);
				v = (v < maxValue(opponent, hand, playedCards, trump, tricks1, tricks2, alpha, beta)) ? v
					: maxValue(opponent, hand, playedCards, trump, tricks1, tricks2, alpha, beta);
				if (v <= alpha) {
					tricks1--;
					hand.add(i, playedCards.remove(playedCards.size() - 1));
					return v;
				}
				beta = (beta < v) ? beta : v;
				tricks1--;
			}
			hand.add(i, playedCards.remove(playedCards.size() - 1));
		}
		return v;
	}

	private static int maxValue(ArrayList<Card> hand, ArrayList<Card> opponent, ArrayList<Card> playedCards, Card trump,
		int tricks1, int tricks2, int alpha, int beta) {
		if (tricks1 > 3)
			return 1;
		else if (tricks2 > 3)
			return -1;

		int v = Integer.MIN_VALUE;
		Card temp;

		for (int i = 0; i < hand.size(); i++) {
			temp = hand.remove(i);
			playedCards.add(temp);
			v = (v > minValue(opponent, hand, playedCards, trump, tricks1, tricks2, alpha, beta)) ? v
				: minValue(opponent, hand, playedCards, trump, tricks1, tricks2, alpha, beta);
			if (v >= beta) {
				hand.add(i, playedCards.remove(playedCards.size() - 1));
				return v;
			}
			alpha = (alpha > v) ? alpha : v;
			hand.add(i, playedCards.remove(playedCards.size() - 1));
		}
		return v;
	}
}

	int * moveAI(int piecePlc[][] )
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
					Integer.MAX_VALUE) > 0)
					wins[j]++;
				// undo the move for the next iteration
				tempHand.add(j, tempPlayed.remove(tempPlayed.size() - 1));
			}
		}

		return findBestCard(tempHand, wins);
	}*/
	
};
#endif