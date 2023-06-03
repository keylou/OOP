#pragma once
#include "Series.h"
class Linear : public Series
{
	double d;
public:
	Linear(int n) :Series(n), d(0) {};
	Linear(double a0, double d_) :d(d_) { for (int i = 0; i < n; i++) arr[i] = a0 + (d * i); };
	void set_d(double d_) { d = d_; };
	void set_arr(double a0) { for (int i = 0; i < n; i++) arr[i] = a0 + (d * i); }
	double n_elem(int n_) override
	{
		if (n_ < n)
			return arr[n_];
		else
		{
			double res = arr[n - 1];
			for (int i = n; i < n_; ++i)
				res += d;
			return res;
		}
	};
	double sum(int n_)override
	{
		if (n_ < n)
			return ((n_ + 1) * (arr[0] + arr[n_])) / 2;
		else return ((n_ + 1) * (arr[0] + n_elem(n_ + 1))) / 2;
	};
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "...\n" << "a0: " << arr[0] << "  " << "d: " << d << '\n';
	}
	std::string to_string()
	{
		std::string str;
		for (int i = 0; i < n; i++)
		{
			str += std::to_string(arr[i]) + ' ';
		}
		str += "...\na0: ";
		str += std::to_string(arr[0]);
		str += "d: ";
		str += std::to_string(d) + '\n';
		return str;
	}
};
