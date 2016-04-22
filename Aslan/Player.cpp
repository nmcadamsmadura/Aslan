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