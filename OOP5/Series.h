#pragma once
#include <fstream>
#include <iostream>

class Series {
protected:
	double* arr;
	int n;
public:
	Series() { n = 0; }
	Series(int n_) {
		n = n_;
		arr = new double[n]();
	}
	Series(double* arr_, int n_) {
		n = n_;
		double* arr = new double[n];
		for (int i = 0; i < n; i++) arr[i] = arr_[i];
	};
	~Series()
	{
		delete[] arr;
	}
	double Get_ai(int i) { return arr[i]; };
	void Set_ai(double val, int index) { arr[index] = val; };
	virtual double n_elem(int n) = 0;
	virtual double sum(int n) = 0;
};
