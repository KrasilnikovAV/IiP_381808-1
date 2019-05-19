#include "Field.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Field F_my;
	Field F_other;
	F_other.Add_random();
	int way = -1, a, end;
	while (way < 0 || way > 1) {
		cout << "Добро пожалоать в Морской бой!" << endl;
		cout << "Выберите вариант расстановки ваших кораблей" << endl;
		cout << "(0 - автоматически, 1 - самостоятельно): ";
		cin >> way;
	}
	if (way == 0) {
		F_my.Add_random();
	}
	else {

	}
	way = 1;
	char aim1, aim2;
	while (F_my.Check_lose() == 0 && F_other.Check_lose() == 0) {
		end = 0;
		if (way == 1) {
			while (end == 0) {
				F_my.Print();
				cout << endl;
				cout << "Ваш ход, введите цель в формате БЦ(Буква, цифра): ";
				cin >> aim1 >> aim2;
				a = F_my.Shot(aim2 - 48, aim1 - 65, F_other);
				if (a == -2) {
					cout << "Неверные данные!" << endl;
					system("pause");
					continue;
				}
				if (a == -1) {
					cout << "Сюда не имеет смысла бить!" << endl;
					system("pause");
					continue;
				}
				if (a == 0) {
					cout << "Мимо!" << endl;
					system("pause");
					end = 1;
					continue;
				}
				if (a == 1) {
					cout << "Ранил!" << endl;
					system("pause");
					continue;
				}
				if (a == 2) {
					cout << "Убил" << endl;
					system("pause");
					continue;
				}
			}
			way = 2;
		}
		else {
			do {
				a = F_other.Shot(rand() % 10, rand() % 10, F_my);
			} while (a != 0);
			way = 1;
			F_my.Print();
			cout << "Враг сходил." << endl;
			system("pause");
		}
	}
	system("cls");
	if (F_my.Check_lose() == 1) {
		cout << "Вы проиграли!!!" << endl;
	}
	else {
		cout << "Вы выйграли!!!" << endl;
	}
	system("pause");
	return 0;
}