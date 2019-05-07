#pragma once

#include "GorkyRailway.h"
#include <string>

using namespace std;

class RailTicketOffice
{
private:
	GorkyRailway GR; // �������� ������
	bool order; // ���������� ������ 1, ���� ������� ������ � 0, ���� ���
	int day; // ���� �����
	int direction; // ����������� �����
	int type_wagon;	// ��� ������
	int wagon; // ����� ������
	int type_place;	// ��� ������
	int count;	// ���������� ����
	string fio;	// ��� ����������
public:
	// ������� ��������� ����� ����
	bool take_an_order(int _day, int _direction, int _type_wagon, int _wagon, int _type_place, int _count, string _fio);
	// ������� ���������, ������� �� �����
	bool Check();
	// ������� ����������� �����
	bool Reserve();
	// ������� ���������� ��������� �������
	int price();
	// ������� �������� ����� �������
	void cancel();
	RailTicketOffice();
	~RailTicketOffice();
};

