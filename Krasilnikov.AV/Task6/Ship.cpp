#include "Ship.h"



Ship::Ship()
{
	lenght = 0;
	alive = 0;
}

bool Ship::Set_ship(int x1, int y1, int x2, int y2, int lenght)
{
	if (x1 > x2) {
		swap(x1, x2);
	}
	if (y1 > y2) {
		swap(y1, y2);
	}

	if (x1 < 0 || y1 < 0 || x2 > 9 || y2 > 9) {
		return 0;
	}
	if (x1 != x2 && y1 != y2) {
		return 0;
	}
	if (x1 == x2) {
		if (y2 - y1 + 1 != lenght) {
			return 0;
		}
	}
	if (y1 == y2) {
		if (x2 - x1 + 1 != lenght) {
			return 0;
		}
	}

	this->lenght = lenght;

	bool direction;
	if (x1 == x2) {
		direction = 1;
	}
	else {
		direction = 0;
	}

	this->coordinate = new pair<int, int>[lenght];
	this->deck = new bool[lenght];

	for (int i = 0; i < lenght; i++) {
		if (direction) {
			this->coordinate[i].first = x1;
			this->coordinate[i].second = y1 + i;
		}
		else {
			this->coordinate[i].first = x1 + i;
			this->coordinate[i].second = y1;
		}
		this->deck[i] = 1;
	}
	this->alive = 1;
	return 1;
}

bool Ship::Check_intersection(int x1, int y1, int x2, int y2)
{
	for (int dx = 0; dx <= x2 - x1; dx++) {
		for (int dy = 0; dy <= y2 - y1; dy++) {
			for (int i = 0; i < lenght; i++) {
				if (sqrt(pow(x1 + dx - coordinate[i].first, 2) + pow(y1 + dy - coordinate[i].second, 2)) < 1.9) {
					return 0;
				}
			}
		}
	}
	return 1;
}

bool Ship::Check_hit(int x, int y)
{
	if (alive == 0) {
		return 0;
	}
	for (int i = 0; i < this->lenght; i++) {
		if (x == this->coordinate[i].first && y == this->coordinate[i].second && this->deck[i] == 1) {
			this->deck[i] = 0;
			for (int j = 0; j < this->lenght; j++) {
				if (this->deck[j] == 1) {
					break;
				}
				if (j == this->lenght - 1) {
					this->alive = false;
				}
			}
			return 1;
		}
	}
	return 0;
}

bool Ship::Check_kill()
{
	return !this->alive;
}

Ship::~Ship()
{
	delete[] coordinate;
	delete[] deck;
}

Ship & Ship::operator=(const Ship& ship)
{
	if (this != &ship) {
		delete[] coordinate;
		delete[] deck;
		this->lenght = ship.lenght;
		this->alive = ship.alive;
		coordinate = new pair<int, int>[lenght];
		deck = new bool[lenght];
		for (int i = 0; i < lenght; i++) {
			this->coordinate[i] = ship.coordinate[i];
			this->deck[i] = ship.deck[i];
		}
	}
	return *this;
}

