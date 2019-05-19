#pragma once
#include <iostream>

using namespace std;

class Ship
{
private:
	int lenght;
	pair<int, int>* coordinate;
	bool* deck;
	bool alive;
public:
	Ship();
	bool Set_ship(int x1, int y1, int x2, int y2, int lenght);
	bool Check_intersection(int x1, int y1, int x2, int y2);
	bool Check_hit(int x, int y);
	bool Check_kill();
	~Ship();
	Ship& operator=(const Ship& ship);
};

