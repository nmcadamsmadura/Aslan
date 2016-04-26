#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>
#include <cstdlib>      // std::rand, std::srand
using namespace std;
deque<vector<vector<int>>> rotate(int pos1[3][3], int pos2[3][3])
{
	int newArray[3][3];
	int temp2[3][3];
	int temp3[3][3];
	deque<vector<vector<int>>> rotationsSet;
	vector<vector<int>> temp1(3, vector<int>(3));
	vector<vector<int>> temp4(3, vector<int>(3));
	for (int i = 0; i < 3;++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp2[i][j] = pos1[i][j];
		}
	}
	for (int i = 0; i < 3;++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp3[i][j] = pos2[i][j];
		}
	}
	int num2 = 4;
	int num3 = 4;
	/**************************/
	//THIS IS FOR FLAG POS ONE
	/*************************/
	while (num2 > 0)
	{
		for (int i = 0; i < 3;++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				newArray[i][j] = temp2[3 - j - 1][i];
			}
		}
		for (int i = 0; i < 3;++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				temp2[i][j] = newArray[i][j];
			}
		}
		for (int i = 0; i < 3;i++)
		{
			for (int j = 0; j < 3; j++)
			{
				temp1[i][j] = newArray[i][j];
				//cout << temp1[i][j] << ' ';

			}
			//cout << endl;
		}
		//cout << endl;
		rotationsSet.push_back(temp1);
		num2--;
	}
	/**************************/
	//THIS IS FOR FLAG POS TWO
	/*************************/
	while (num3 > 0)
	{
		for (int i = 0; i < 3;++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				newArray[i][j] = temp3[3 - j - 1][i];
			}
		}
		for (int i = 0; i < 3;++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				temp3[i][j] = newArray[i][j];
			}
		}
		for (int i = 0; i < 3;i++)
		{
			for (int j = 0; j < 3; j++)
			{
				temp4[i][j] = newArray[i][j];
				//cout << temp1[i][j] << ' ';

			}
			//cout << endl;
		}
		//cout << endl;
		rotationsSet.push_back(temp4);
		num3--;
	}
	return rotationsSet;
}
void printGrid(vector<vector <piece>> grid)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			cout << grid[i][k] << ' ';
		}
		cout << endl;
	}

}
void cycledown(vector<vector<int>> & matrix, int n, int c)
{
	int temp;	int col, r;
	col = c;
	for (r = n - 1; r>-1; r--)
	{
		if (r > 0)
		{
			temp = matrix[r][col];
			matrix[r][col] = matrix[r - 1][col];
			matrix[r - 1][col] = temp;
		}
		else if (r == 0)
		{
			temp = matrix[r][col];
			matrix[r][col] = matrix[r][col];
			matrix[r][col] = temp;
		}
	}
}
void cycleright(vector<vector<int>> & matrix, int n, int r)
{
	int temp;	int row, c;
	row = r;
	//cout << "Performing row cycle right...\n";
	for (c = n - 1; c>-1; c--)
	{
		if (c > 0)
		{
			temp = matrix[row][c];
			matrix[row][c] = matrix[row][c - 1];
			matrix[row][c - 1] = temp;
		}
		else if (c == 0)
		{
			temp = matrix[row][c];
			matrix[row][c] = matrix[row][c];
			matrix[row][c] = temp;
			//cout << "ok thats weird" << endl;
		}
	}
}
int myrandom(int i) { return rand() % i; }
deque <vector<vector<piece>>> convertIntsAndInits(deque<vector<vector<int>>> initSetupsOpp)
{
	int OppPossiblePcs[] = {10,9,8,8,7,7,7,6,6,6,6,5,5,5,5,4,4,4,4,3,3,3,3,3,2,2,2,2,
		2,2,2,2,11,12,12,12};
	deque<vector<vector<piece>>> init;
	vector<vector<piece>> temp(4, vector<piece> (10));
	
	for (int i = 0; i < initSetupsOpp.size(); i++)
	{
		int loop = 0;
		random_shuffle(begin(OppPossiblePcs), end(OppPossiblePcs));
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (initSetupsOpp.at(i)[k][j] == 0)
				{
					temp[k][j] = piece(Guy(OppPossiblePcs[loop]), red,k, j);
					loop++;

				}
				if(initSetupsOpp.at(i)[k][j] == 12 || initSetupsOpp.at(i)[k][j] == 13)
				{
					temp[k][j] = piece(Guy((initSetupsOpp.at(i))[k][j]), red, k , j);
				}
			}
		}
		printGrid(temp);
		cout << endl;
		init.push_back(temp);
	}
	return init;
}
deque<vector<vector<int>>> shiftThrough(deque<vector<vector<int>>> rotations)
{
	int num = 7;
	deque<vector<vector<int>>> possibleOppSetups;
	for (int rot = 0; rot < rotations.size(); rot++)
	{
		//cout << "********************************" << endl;
		//cout << "HERES THE " << rot << " ROTATION" << endl;
		//cout << "********************************" << endl;
		rot == 0 | rot == 4 ? num = 8 : num = 7;
		int test[4][10];
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				test[i][k] = (rotations.at(rot))[i][k];
			}
		}
		int change = 1;
		int change2 = 1;
		int num2 = num;
		int num3 = num;
		vector<vector<int>> temp3(4, vector<int>(10));

		vector<vector<int>> temp2(4, vector<int>(10));
		for (int i = 0; i < 3;++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				temp3[i][j] = test[i][j];
			}
		}
		//Here's just a copy block so I dont mess with the original in the cycle down
		for (int i = 0; i < 4;++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				temp2[i][j] = temp3[i][j];
			}
		}
		/*Ok so heres where it gets confusing in the code

		first I try to shift right the starting array i.e for the first one:
		12 0  0...0
		13 12 0...0
		12 0  0...0
		0.........0
		All the way to:
		0...12 0
		0...13 12
		0...12 0

		While storing each array in a deque

		I then shift it down one spot (store it in the map)
		then shift right again and store those states in the map

		This function's purpose is to develop the different possitions that the
		flag would be. It assumes that the flag position is protected by an amount of bombs
		A minor problem now is this assumption since it would be easy to exploit if known,
		but for now it's fine; atleast for testing.
		*/
		while (num2 > 0) {
			//cout << "HERES: Cycle Right Change " << change << endl;
			for (int i = 0; i < 3; i++) {
				cycleright(temp3, 10, i);
			}
			possibleOppSetups.push_back(temp3);
			num2--;
			change++;
		}
		//cout << "HERES: Cycle Down Change " << endl;
		for (int i = 0; i < 3; i++) {
			cycledown(temp2, 4, i);

		}
		possibleOppSetups.push_back(temp2);
		while (num3 > 0) {
			//	cout << "HERES: Cycle Right Change " << change << endl;
			for (int i = 0; i < 4; i++) {
				cycleright(temp2, 10, i);


			}
			possibleOppSetups.push_back(temp2);
			num3--;
			change++;
		}
		
	}
	return possibleOppSetups;
}
