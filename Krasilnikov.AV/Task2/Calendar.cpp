#include "Calendar.h"


Calendar::Calendar(void)
{
	lenght = 0;
}

Calendar::Calendar(const int _time, string _event)
{
	lenght = 1;
	Date d(_time);
	time[0] = d;
	event[0] = _event;
}

Calendar::Calendar(const int _day, const int _month, const int _year, const string _event)
{
	Date d(_day, _month, _year);
	time[0] = d;
	event[0] = _event;
	lenght = 1;
}

Calendar::Calendar(const Calendar & c)
{
	lenght = c.lenght;
	for (int i = 0; i < lenght; i++) {
		time[i] = c.time[i];
		event[i] = c.event[i];
	}
}

bool Calendar::add(const int _time, const string _event)
{
	if (_time > 737789 || _time < 0) {
		return 0;
	}
	Date d(_time);
	for (int i = 0; i < lenght; i++) {
		if (d == time[i]) {
			event[i] = _event;
			return 0;
		}
	}
	if (lenght < 30) {
		Date d(_time);
		time[lenght] = d;
		event[lenght] = _event;
		lenght++;
		return 1;
	}
	else {
		return 0;
	}
}

bool Calendar::add(const int _day, const int _month, const int _year, const string _event)
{
	if (_year > 2020 || _year < 1 || _month > 12 || _month < 1 || _day < 1) {
		return 0;
	}
	if (_day > month_value[_month - 1]) {
		return 0;
	}
	Date d(_day, _month, _year);
	for (int i = 0; i < lenght; i++) {
		if (d == time[i]) {
			event[i] = _event;
			return 0;
		}
	}
	if (lenght < 30) {
		Date d(_day, _month, _year);
		time[lenght] = d;
		event[lenght] = _event;
		lenght++;
		return 1;
	}
	else {
		return 0;
	}
}

Date Calendar::getDate(const string _event)
{
	for (int i = 0; i < lenght; i++) {
		if (_event == event[i]) {
			return time[i];
		}
	}
	return Date(0);
}

int Calendar::getDifference(const Date & _date, const string _event)
{
	Date d(_date);
	for (int i = 0; i < lenght; i++) {
		if (_event == event[i]) {
			d = d - time[i].getTime();
			return abs(d.getTime());
		}
	}
	return -1;
}

int Calendar::getDifference(const int _day, const int _month, const int _year, const string _event)
{
	Date d(_day, _month, _year);
	for (int i = 0; i < lenght; i++) {
		if (_event == event[i]) {
			d - time[i].getTime();
			return abs((d - time[i].getTime()).getTime());
		}
	}
	return -1;
}

bool Calendar::dateShift(const string _event, const int _day)
{
	for (int i = 0; i < lenght; i++) {
		if (_event == event[i]) {
			Date d(time[i] + _day);
			for (int j = 0; j < lenght; j++) {
				if (d == time[j]) {
					return 0;
				}
			}
			time[i] = d;
			return 1;
		}
	}
	return 0;
}

Calendar & Calendar::operator=(const Calendar & c)
{
	lenght = c.lenght;
	for (int i = 0; i < lenght; i++) {
		time[i] = c.time[i];
		event[i] = c.event[i];
	}
	return *this;
}


Calendar::~Calendar()
{
	delete[] time;
	delete[] event;
}

istream & operator>>(istream & in, Calendar & c)
{
	in >> c.lenght;
	for (int i = 0; i < c.lenght; i++) {
		in >> c.time[i];
		getline(in, c.event[i]);
	}
	return in;
}

ostream & operator<<(ostream & out, const Calendar & c)
{
	out << c.lenght;
	for (int i = 0; i < c.lenght; i++) {
		out << endl;
		out << c.time[i] << ' ' << c.event[i];
	}
	return out;
}
