#pragma once
#include "Date.h"
#include <string>

using namespace std;

class Calendar
{
private:
	const int month_value[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int lenght;
	Date* time = new Date[30];
	string* event = new string[30];
public:
	Calendar(void);
	Calendar(const int _time, string _event);
	Calendar(const int _day, const int _month, const int _year, const string _event);
	Calendar(const Calendar& c);
	bool add(const int _time, const string _event);
	bool add(const int _day, const int _month, const int _year, const string _event);
	Date getDate(const string _event);
	int getDifference(const Date& _date, const string _event);
	int getDifference(const int _day, const int _month, const int _year, const string _event);
	bool dateShift(const string _event, const int _day);
	Calendar& operator= (const Calendar& c);
	friend istream & operator>> (istream & in, Calendar & c);
	friend ostream & operator<< (ostream & out, const Calendar & c);
	~Calendar();
};