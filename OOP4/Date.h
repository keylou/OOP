#pragma once
#include "Triad.h"
#include <iostream>

class Date : public Triad
{
public:
	Date() { set_first(0); set_second(0); set_third(0); }
	Date(int d1, int d2, int d3);

	void set_year(int y);
	void set_month(int m);
	void set_day(int d);

	int get_year() const;
	int get_month() const;
	int get_day() const;

	int calculateDifference(Date anotherDate);
	int toDays();

	bool operator> (Date& date);
	bool operator< (Date& date);
	bool operator>= (Date& date);
	bool operator<= (Date& date);
};
