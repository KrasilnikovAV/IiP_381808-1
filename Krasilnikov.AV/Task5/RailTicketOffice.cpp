#include "RailTicketOffice.h"


// Функция принимает заказ мест и возвращает 1, если данные введены верно.
bool RailTicketOffice::take_an_order(int _day, int _direction, int _type_wagon, int _wagon, int _type_place, int _count, string _fio)
{
	if (_type_place == 1) {
		if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 8) {
			return 0;
		}
		order = 1;
		day = _day;
		direction = _direction;
		type_wagon = _type_wagon;
		wagon = _wagon;
		type_place = _type_place;
		count = _count;
		fio = _fio;
		return 1;
	}
	else if (_type_place == 2) {
		if (_type_wagon == 1) {
			if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 4) {
				return 0;
			}
			order = 1;
			day = _day;
			direction = _direction;
			type_wagon = _type_wagon;
			wagon = _wagon;
			type_place = _type_place;
			count = _count;
			fio = _fio;
			return 1;
		}
		else if (_type_wagon == 2) {
			if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 6) {
				return 0;
			}
			order = 1;
			day = _day;
			direction = _direction;
			type_wagon = _type_wagon;
			wagon = _wagon;
			type_place = _type_place;
			count = _count;
			fio = _fio;
			return 1;
		}
		else if (_type_wagon == 3) {
			if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 2) {
				return 0;
			}
			order = 1;
			day = _day;
			direction = _direction;
			type_wagon = _type_wagon;
			wagon = _wagon;
			type_place = _type_place;
			count = _count;
			fio = _fio;
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (_type_place == 3) {
		if (_type_wagon == 1) {
			if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 4) {
				return 0;
			}
			order = 1;
			day = _day;
			direction = _direction;
			type_wagon = _type_wagon;
			wagon = _wagon;
			type_place = _type_place;
			count = _count;
			fio = _fio;
			return 1;
		}
		else if (_type_wagon == 2) {
			if (_day < 1 || _day > 31 || _direction < 1 || _direction > 2 || _wagon < 1 || _wagon > 8) {
				return 0;
			}
			order = 1;
			day = _day;
			direction = _direction;
			type_wagon = _type_wagon;
			wagon = _wagon;
			type_place = _type_place;
			count = _count;
			fio = _fio;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

// Функция проверяет, сободны ли места
// Сначала считает все свободные места в вагоне и сравнивает с нужным колличеством
bool RailTicketOffice::Check()
{
	if (order == 0) {
		return 0;
	}
	int free = 0;
	for (int i = 0; i < day; i++) {
		if (GR.Check_private(day, direction, type_wagon, wagon, i + 1, type_place) == 1) {
			free++;
		}
	}
	if (free >= count) {
		return 1;
	}
	else {
		return 0;
	}
}

// Функция резервирует места
bool RailTicketOffice::Reserve()
{
	if (order == 0) {
		return 0;
	}
	if (Check() == 0) {
		return 0;
	}
	for (int i = 0; i < day; i++) {
		if (GR.Check_private(day, direction, type_wagon, wagon, i + 1, type_place) == 1) {
			GR.Set_private(day, direction, type_wagon, wagon, i + 1, type_place);
		}
	}
}

// Функция возвращает стоимость билетов
int RailTicketOffice::price()
{
	if (order == 0) {
		return 0;
	}
	if (type_place == 1) {
		return count * GR.lastsochka_price;
	}
	if (type_place == 2) {
		if (type_wagon == 1) {
			return count * GR.firmeniy_plac_price;
		}
		if (type_wagon == 2) {
			return count * GR.firmeniy_kupe_price;
		}
		if (type_wagon == 3) {
			return count * GR.firmeniy_sv_price;
		}
	}
	if (type_place == 3) {
		if (type_wagon == 1) {
			return count * GR.skoriy_plac_price;
		}
		if (type_wagon == 2) {
			return count * GR.skoriy_kupe_price;
		}
	}
}

// Функция отменяет заказ билетов
void RailTicketOffice::cancel()
{
	order = 0;
}

RailTicketOffice::RailTicketOffice()
{
	order = 0;
}


RailTicketOffice::~RailTicketOffice()
{
}
