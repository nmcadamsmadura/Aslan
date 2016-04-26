#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum Guy {
	space, water, marshal, general, colonels, majors, captains, lieutenants, sergeants,
	miners, scouts, spy, bomb, flag
};
string guys[] = { "space","water","marshal","general","colonel","major","captain","lieutenant", "sergeant",
"miner","scout","spy","bomb","flag"};
enum Color { red, blue };
class piece
{
public:
	int value;
	Guy guy;
	Color col;
	bool moved;
	int pos[2];
	piece(Guy g, Color c,int x,int y)
	{
		moved = false;
		guy = g;
		col = c;
		pos[0] = x;
		pos[1] = y;
	}
	piece(Guy g, Color c)
	{
		moved = false;
		guy = g;
		col = c;
	}
	piece(Guy g)
	{
		moved = false;
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
		pc.col == 0 ? os << "R" << pc.guy : os << "B" << pc.guy;
		return os;
	}
	else if (pc.guy == 0)
	{
		os << "0";
		return os;
	}
	else if (pc.guy == 1)
	{
		os << "WA";
		return os;
	}
	else if (pc.guy == 12)
	{
		os << "BM";
		return os;
	}
	else if (pc.guy == 13)
	{
		os << "F";
		return os;
	}
}
