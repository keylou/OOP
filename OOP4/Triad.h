#pragma once
#include <iostream>
class Triad
{
	int first, second, third;
public:
	Triad() { first = 0; second = 0; third = 0; };
	Triad(int p1, int p2, int p3);
	void set_first(int value);
	void set_second(int value);
	void set_third(int value);
	int get_first() const;
	int get_second() const;
	int get_third() const;
	bool operator == (Triad& triad);
	bool operator != (Triad& triad);
	friend std::ostream& operator<<(std::ostream& stream, const Triad& triad);
	friend std::istream& operator>>(std::istream& stream, Triad& triad);
};
