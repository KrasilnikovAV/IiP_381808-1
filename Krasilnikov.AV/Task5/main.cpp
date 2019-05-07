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
		cout << "�������� ��������:" << endl;
		cout << "1 - ������� ����� �������" << endl;
		cout << "2 - ��������� ��������� �����" << endl;
		cout << "3 - ��������������� �����" << endl;
		cout << "4 - ��������� ���������" << endl;
		cout << "5 - �������� ����� �������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cout << "�������� ������ ����� � ������� Enter: " << endl;
		cin >> q;
		switch (q)
		{
		case '0':
			break;
		case '1':
			system("cls");
			cout << "������� ����(1 - 31): " << endl;
			cin >> day;
			cout << "������� �����������(1 - � ������ ��������; 2 - ������): " << endl;
			cin >> direction;
			cout << "������� ��� ������(1 - ��������; 2 - ���������; 3 - ������): " << endl;
			cin >> type_place;
			if (type_place != 1) {
				cout << "������� ��� ������(1 - ��������; 2 - ����; 3 - ��): " << endl;
				cin >> type_wagon;
			}
			cout << "������� ����� ������: " << endl;
			cin >> wagon;
			cout << "������� ���������� �������: " << endl;
			cin >> count;
			cout << "������� ��� ����������: " << endl;
			cin >> fio;
			if (RTO.take_an_order(day, direction, type_wagon, wagon, type_place, count, fio)) {
				cout << "����� �����������!" << endl;
			}
			else {
				cout << "�������� ������!" << endl;
			}
			system("pause");
			break;
		case '2':
			system("cls");
			if (RTO.Check()) {
				cout << "����� �� ������!" << endl;
			}
			else {
				cout << "����� ������!" << endl;
			}
			system("pause");
			break;
		case '3':
			system("cls");
			if (RTO.Reserve()) {
				cout << "����� ���������������!" << endl;
			}
			else {
				cout << "������!" << endl;
			}
			system("pause");
			break;
		case '4':
			system("cls");
			price = RTO.price();
			if (price) {
				cout << "����� ��������� ������� �����: " << price << endl;
			}
			else {
				cout << "������!" << endl;
			}
			system("pause");
			break;
		case '5':
			system("cls");
			RTO.cancel();
			cout << "����� ������!" << endl;
			system("pause");
			break;
		default:
			cout << "�� ����� ������������ ��������" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}