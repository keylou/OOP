#include "SQmatrix.h"
#include <iostream>
#include <string>

SQmatrix::SQmatrix()
{
	n = 1;
	matrix = new int* [n];
	matrix[0] = new int[n];
	matrix[0][0] = 0;
}

SQmatrix::SQmatrix(int _n, int** A)
{
	n = _n;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = A[i][j];
		}
	}
}

SQmatrix::SQmatrix(int _n)
{
	n = _n;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

SQmatrix::SQmatrix(const SQmatrix& object)
{
	this->matrix = new int* [object.n];
	for (int i = 0; i < object.n; i++)
	{
		this->matrix[i] = new int[object.n];
	}
	this->n = object.n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->matrix[i][j] = object.matrix[i][j];
		}
	}
}

SQmatrix::~SQmatrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}


SQmatrix SQmatrix::operator+(SQmatrix object)
{
	SQmatrix temp(object.n);
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.n; j++)
		{
			temp.matrix[i][j] = matrix[i][j] + object.matrix[i][j];
		}
	}
	return temp;

}

SQmatrix SQmatrix::operator-(SQmatrix object)
{
	SQmatrix temp(object.n);
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.n; j++)
		{
			temp.matrix[i][j] = matrix[i][j] - object.matrix[i][j];
		}
	}
	return temp;

}

SQmatrix SQmatrix::operator*(SQmatrix object)
{
	SQmatrix temp(object.n);
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.n; j++)
		{
			temp.matrix[i][j] = 0;
			for (int k = 0; k < temp.n; k++)
			{
				temp.matrix[i][j] += matrix[i][k] * object.matrix[k][j];
			}
		}
	}
	return temp;
}

SQmatrix SQmatrix::operator*(int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = x * matrix[i][j];
		}
	}
	return *this;
}

SQmatrix operator*(int x, SQmatrix object)
{
	for (int i = 0; i < object.n; i++)
	{
		for (int j = 0; j < object.n; j++)
		{
			object.matrix[i][j] = x * object.matrix[i][j];
		}
	}
	return object;
}

bool SQmatrix::operator==(SQmatrix object)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] != object.matrix[i][j])
			{
				flag = false;
			}
		}
	}

	return flag;
}

bool SQmatrix::operator!=(SQmatrix object)
{
	return !this->operator==(object);
}


SQmatrix& SQmatrix::operator=(const SQmatrix& object)
{
	if (this == &object)
		return *this;
	if (matrix)
	{
		for (int i = 0; i < n; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
	}

	n = object.n;
	matrix = new int* [object.n];
	for (int i = 0; i < object.n; i++)
	{
		matrix[i] = new int[object.n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->matrix[i][j] = object.matrix[i][j];
		}
	}
	return *this;
}

std::string SQmatrix::toString()
{
	std::string as;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			as += std::to_string(matrix[i][j]) + " ";
		}
		as += '\n';
	}
	return as;
}

std::ostream& operator<<(std::ostream& out, SQmatrix& object)
{
	return out << object.toString();
}

std::istream& operator>>(std::istream& in, SQmatrix& object)
{
	if (object.matrix)
	{
		for (int i = 0; i < object.n; i++)
		{
			delete[]object.matrix[i];
		}
		delete[]object.matrix;
	}
	in >> object.n;
	object.matrix = new int* [object.n];
	for (int i = 0; i < object.n; i++)
	{
		object.matrix[i] = new int[object.n];
		for (int j = 0; j < object.n; j++)
		{
			in >> object.matrix[i][j];
		}
	}
	return in;
}
