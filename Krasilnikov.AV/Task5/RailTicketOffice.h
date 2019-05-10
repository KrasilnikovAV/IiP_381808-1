#pragma once

#include "GorkyRailway.h"
#include <string>

using namespace std;

class RailTicketOffice
{
private:
	GorkyRailway GR; // Железная дорога
	bool order; // Переменная хранит 1, если введены данные и 0, если нет
	int day; // День брони
	int direction; // Направление брони
	int type_wagon;	// Тип вагона
	int wagon; // Номер вагона
	int type_place;	// Тип поезда
	int count;	// Количество мест
	string fio;	// ФИО покупателя
public:
	// Функция принимает заказ мест
	bool take_an_order(int _day, int _direction, int _type_wagon, int _wagon, int _type_place, int _count, string _fio);
	// Функция проверяет, сободны ли места
	bool Check();
	// Функция резервирует места
	bool Reserve();
	// Функция возвращает стоимость билетов
	int price();
	// Функция отменяет заказ билетов
	void cancel();
	RailTicketOffice();
	~RailTicketOffice();
};

