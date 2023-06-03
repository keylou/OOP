#include "Date.h"

Date::Date(int d1, int d2, int d3)
{
	set_first(d1);
	set_second(d2);
	set_third(d3);
}

void Date::set_year(int y)
{
	int value;
	y > -1 ? value = y : value = 0;
	set_first(value);
}

void Date::set_month(int m)
{
	int value;
	m > 0 && m < 13 ? value = m : value = 1;
	set_second(value);
}

void Date::set_day(int d)
{
	int value;
	switch (get_month())
	{
	case 1:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 3:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 5:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 7:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 8:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 10:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 12:
		d > 0 && d < 32 ? value = d : value = 1;
		break;
	case 4:
		d > 0 && d < 31 ? value = d : value = 1;
		break;
	case 6:
		d > 0 && d < 31 ? value = d : value = 1;
		break;
	case 9:
		d > 0 && d < 31 ? value = d : value = 1;
		break;
	case 11:
		d > 0 && d < 31 ? value = d : value = 1;
		break;
	case 2:
		if (get_year() % 4 == 0)
			d > 0 && d < 30 ? value = d : value = 1;
		else
			d > 0 && d < 29 ? value = d : value = 1;
		break;
	}
	set_third(value);
}

int Date::get_year() const
{
	return get_first();
}

int Date::get_month() const
{
	return get_second();
}

int Date::get_day() const
{
	return get_third();
}

int Date::calculateDifference(Date anotherDate)
{
	return abs(toDays() - anotherDate.toDays());
}

int Date::toDays()
{
	int days=0;
	for (int i=1; i< get_second();i++)
		switch (i)
		{
		case 1:
			days += 31;
			break;
		case 3:
			days += 31;
			break;
		case 5:
			days += 31;
			break;
		case 7:
			days += 31;
			break;
		case 8:
			days += 31;
			break;
		case 10:
			days += 31;
			break;
		case 4:
			days += 30;
			break;
		case 6:
			days += 30;
			break;
		case 9:
			days += 30;
			break;
		case 11:
			days += 30;
			break;
		case 2:
			if (get_first() % 4 == 0)
				days += 29;
			else
				days += 28;
			break;
		}
	days += get_third();
	days += get_first()*365+get_first()/4;
	return days;
}

bool Date::operator>(Date& date)
{
	return get_first() > date.get_first() ? 1 :
		get_first() < date.get_first() ? 0 :
		get_second() > date.get_second() ? 1 :
		get_second() < date.get_second() ? 0 :
		get_third() > date.get_third() ? 1 :
		get_third() < date.get_third() ? 0 : 0;
}

bool Date::operator<(Date& date)
{
	return get_first() < date.get_first() ? 1 :
		get_first() > date.get_first() ? 0 :
		get_second() < date.get_second() ? 1 :
		get_second() > date.get_second() ? 0 :
		get_third() < date.get_third() ? 1 :
		get_third() > date.get_third() ? 0 : 0;
}

bool Date::operator>=(Date& date)
{
	return *this == date ? 1 :
		*this > date ? 1 : 0;
}

bool Date::operator<=(Date& date)
{
	return *this == date ? 1 :
		*this < date ? 1 : 0;
}
