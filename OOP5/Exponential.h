#pragma once
#include "Series.h"
class Exponential : public Series
{
	double q;
public:
	Exponential(int n) :Series(n), q(0) {};
	Exponential(double a0, double q_) :q(q_) { for (int i = 0; i < n; i++) arr[i] = a0 * (pow(q, i - 1)); }
	void set_d(double q_) { q = q_; };
	void set_arr(double a0)
	{
		for (int i = 1; i < n + 1; i++)
			arr[i - 1] = a0 * (pow(q, (i - 1)));
	}
	double n_elem(int n_)
	{
		if (n_ < n)
			return arr[n_];
		else
		{
			double res = arr[n - 1];
			for (int i = n; i < n_; ++i)
				res += pow(q, i - 1);
			return res;
		}
	};
	double sum(int n_)
	{
		if (n_ < n)
			return (q != 1 ? (arr[0] - arr[n_] * q) / (1 - q) : n_);
		else
			return (q != 1 ? (arr[0] - n_elem(n_ + 1) * q) / (1 - q) : n_);
	};

	void print()
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "...\n" << "a0: " << arr[0] << "  " << "q: " << q << '\n';
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
		str += "q: ";
		str += std::to_string(q) + '\n';
		return str;
	}
};
