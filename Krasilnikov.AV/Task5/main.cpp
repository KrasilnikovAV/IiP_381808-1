#include <iostream>
#include <cstdlib>
#include "RailTicketOffice.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	RailTicketOffice RTO;
	int day;
	int price = 0;
	int direction;
	int type_wagon = 0;
	int wagon;
	int type_place;
	int count;
	string fio;

	char q = 1;
	while (q != '0') {
		system("cls");
		cout << "Выберите действие:" << endl;
		cout << "1 - Принять заказ билетов" << endl;
		cout << "2 - Проверить свободные места" << endl;
		cout << "3 - Зарезервировать места" << endl;
		cout << "4 - Расчитать стоимость" << endl;
		cout << "5 - Отметить заказ билетов" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "Выберите нужный пункт и нажмите Enter: " << endl;
		cin >> q;
		switch (q)
		{
		case '0':
			break;
		case '1':
			system("cls");
			cout << "Введите день(1 - 31): " << endl;
			cin >> day;
			cout << "Введите нарпавление(1 - в Нижний Новгород; 2 - Москву): " << endl;
			cin >> direction;
			cout << "Введите тип поезда(1 - Ласточка; 2 - Фирменный; 3 - Скорый): " << endl;
			cin >> type_place;
			if (type_place != 1) {
				cout << "Введите тип вагона(1 - Плацкарт; 2 - Купе; 3 - СВ): " << endl;
				cin >> type_wagon;
			}
			cout << "Введите номер вагона: " << endl;
			cin >> wagon;
			cout << "Введите количество билетов: " << endl;
			cin >> count;
			cout << "Введите ФИО покупателя: " << endl;
			cin >> fio;
			if (RTO.take_an_order(day, direction, type_wagon, wagon, type_place, count, fio)) {
				cout << "Заказ сформирован!" << endl;
			}
			else {
				cout << "Неверные данные!" << endl;
			}
			system("pause");
			break;
		case '2':
			system("cls");
			if (RTO.Check()) {
				cout << "Места не заняты!" << endl;
			}
			else {
				cout << "Места заняты!" << endl;
			}
			system("pause");
			break;
		case '3':
			system("cls");
			if (RTO.Reserve()) {
				cout << "Места зарезервированы!" << endl;
			}
			else {
				cout << "Ошибка!" << endl;
			}
			system("pause");
			break;
		case '4':
			system("cls");
			price = RTO.price();
			if (price) {
				cout << "Общая стоимость билетов равна: " << price << endl;
			}
			else {
				cout << "Ошибка!" << endl;
			}
			system("pause");
			break;
		case '5':
			system("cls");
			RTO.cancel();
			cout << "Заказ отменён!" << endl;
			system("pause");
			break;
		default:
			cout << "Вы ввели некорректное значение" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}