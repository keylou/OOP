#ifndef MATRIX_LAB2_OOP
#define MATRIX_LAB2_OOP

#include <iostream>

class SQmatrix
{
private:
	int n;
	int** matrix;
public:
	SQmatrix();
	SQmatrix(int n, int**);
	SQmatrix(int n);

	SQmatrix(const SQmatrix& object);
	~SQmatrix();

	SQmatrix operator + (SQmatrix);
	SQmatrix operator - (SQmatrix);
	SQmatrix operator * (SQmatrix);
	SQmatrix operator * (int x);
	friend SQmatrix operator * (int x, SQmatrix);

	bool operator == (SQmatrix);
	bool operator != (SQmatrix);

	SQmatrix& operator = (const SQmatrix& object);

	friend std::ostream& operator << (std::ostream&, SQmatrix&);
	friend std::istream& operator >> (std::istream&, SQmatrix&);

	std::string toString();
};
#endif
