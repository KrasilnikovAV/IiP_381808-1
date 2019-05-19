#include "Field.h"



void Field::Print_kill_me(int x, int y, int xp, int yp)
{
	setlocale(LC_ALL, "C");
	my_field[x + 1][y + 1] = -3;
	for (int dx = -1; dx < 2; dx++)
		for (int dy = -1; dy < 2; dy++) {
			if (my_field[x + dx + 1][y + dy + 1] == -3 && (x + dx != xp || y + dy != yp)) {
				if (dx != 0 || dy != 0) {
					Print_kill_me(x + dx, y + dy, x, y);
				}
			}
			else {
				my_field[x + dx + 1][y + dy + 1] = '*';
			}
		}
	setlocale(LC_ALL, "Russian");
}

void Field::Print_kill_other(int x, int y, int xp, int yp)
{
	setlocale(LC_ALL, "C");
	other_field[x + 1][y + 1] = -3;
	for (int dx = -1; dx < 2; dx++)
		for (int dy = -1; dy < 2; dy++) {
			if (other_field[x + dx + 1][y + dy + 1] == -3 && (x + dx != xp || y + dy != yp)) {
				if (dx != 0 || dy != 0) {
					Print_kill_other(x + dx, y + dy, x, y);
				}
			}
			else {
				other_field[x + dx + 1][y + dy + 1] = '*';
			}
		}
	setlocale(LC_ALL, "Russian");
}

Field::Field()
{
	count = 0;
	lives_count = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			my_field[i][j] = -6;
			other_field[i][j] = -6;
		}
	}
}

bool Field::Add(int x1, int y1, int x2, int y2, int lenght)
{
	if (x1 > x2) {
		swap(x1, x2);
	}
	if (y1 > y2) {
		swap(y1, y2);
	}
	if (count == 10) {
		return 0;
	}
	for (int i = 0; i < count; i++) {
		if (ships[i].Check_intersection(x1, y1, x2, y2) == 0) {
			return 0;
		}
	}
	if (ships[count].Set_ship(x1, y1, x2, y2, lenght) == 0) {
		return 0;
	}
	count++;
	lives_count++;
	for (int dx = x1; dx <= x2; dx++)
		for (int dy = y1; dy <= y2; dy++) {
			my_field[dx + 1][dy + 1] = -2;
		}
	return 1;
}

void Field::Add_random()
{
	srand(time(0));
	count = 0;
	lives_count = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			my_field[i][j] = -6;
			other_field[i][j] = -6;
		}
	}
	int x1, x2, y1, y2;
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < 5 - i; j++) {
			do {
				if (rand() % 2 == 0) {
					x1 = x2 = rand() % 10;
					y1 = rand() % (11 - i);
					y2 = y1 + i - 1;
				}
				else {
					y1 = y2 = rand() % 10;
					x1 = rand() % (11 - i);
					x2 = x1 + i - 1;
				}
			} while (this->Add(x1, y1, x2, y2, i) == 0);
		}
	}
}

int Field::Shot(int x, int y, Field& field)
{
	if (x < 0 || x > 9 || y < 0 || y > 9) {
		return -2;
	}
	if (other_field[x + 1][y + 1] != -6) {
		return -1;
	}
	for (int i = 0; i < count; i++) {
		int way = field.Defense(x, y);
		if (way == 2) {
			Print_kill_other(x, y, x, y);
			return 2;
		}
		if (way == 1) {
			other_field[x + 1][y + 1] = -3;
			return 1;
		}
	}
	other_field[x + 1][y + 1] = -7;
	return 0;
}

int Field::Defense(int x, int y)
{
	for (int i = 0; i < count; i++) {
		if (ships[i].Check_kill() == 0) {
			if (ships[i].Check_hit(x, y)) {
				if (ships[i].Check_kill()) {
					lives_count--;
					Print_kill_me(x, y, x, y);
					return 2;
				}
				else {
					my_field[x + 1][y + 1] = -3;
					return 1;
				}
			}
		}
	}
	my_field[x + 1][y + 1] = -7;
	return 0;
}

void Field::Print()
{
	setlocale(LC_ALL, "C");
	system("cls");
	cout << " ABCDEFGHIJ   ABCDEFGHIJ\n";
	for (int i = 1; i < 11; i++) {
		cout << i - 1;
		for (int j = 1; j < 11; j++) {
			cout << my_field[i][j];
		}
		cout << "  " << i - 1;
		for (int j = 1; j < 11; j++) {
			cout << other_field[i][j];
		}
		cout << endl;
	}
	setlocale(LC_ALL, "Russian");
}

bool Field::Check_lose()
{
	if (lives_count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}


Field::~Field()
{
}
