#pragma once
#include <windows.h>
#include <random>
#include <ctime>
#include "Ship.h"

class Field
{
private:
	int count;
	int lives_count;
	Ship ships[10];
	char my_field[12][12];
	char other_field[12][12];
	void Print_kill_me(int x, int y, int xp, int yp);
	void Print_kill_other(int x, int y, int xp, int yp);
public:
	Field();
	bool Add(int x1, int y1, int x2, int y2, int lenght);
	void Add_random();
	int Shot(int x, int y, Field& field);
	int Defense(int x, int y);
	void Print();
	bool Check_lose();
	~Field();
};

