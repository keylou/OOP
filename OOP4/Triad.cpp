#include "Triad.h"

Triad::Triad(int p1, int p2, int p3)
{
	first = p1;
	second = p2;
	third = p3;
}

void Triad::set_first(int value)
{
	first = value;
}

void Triad::set_second(int value)
{
	second = value;
}

void Triad::set_third(int value)
{
	third = value;
}

int Triad::get_first() const
{
	return first;
}

int Triad::get_second() const
{
	return second;
}

int Triad::get_third() const
{
	return third;
}

bool Triad::operator==(Triad& triad)
{
	return first == triad.get_first() && second == triad.get_second() && third == triad.get_third();
}

bool Triad::operator!=(Triad& triad)
{
	return first != triad.get_first() || second != triad.get_second() || third != triad.get_third();
}

std::ostream& operator<<(std::ostream& stream, const Triad& triad)
{
	stream << "first value: " << triad.get_first() << " second value: " << triad.get_second() << " third value: " << triad.get_third() << '\n';
	return stream;
}

std::istream& operator>>(std::istream& stream, Triad& triad)
{
	int f, s, t;
	stream >> f >> s >> t;
	triad.set_first(f);
	triad.set_second(s);
	triad.set_third(t);

	return stream;
}
