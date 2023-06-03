#include "Triangle.h"

Triangle::Triangle()
{
	sideAB = 0;
	sideBC = 0;
	sideAC = 0;

	angleA = 0;
	angleB = 0;
	angleC = 0;
}

Triangle::Triangle(double A, double B, double C, int choice)
{
	double kayf;
	switch (choice)
	{
	case 1:
		sideAB = A;
		sideBC = B;
		sideAC = C;

		angleA = acos((sideAB * sideAB + sideAC * sideAC - sideBC * sideBC) / (2 * sideAB * sideAC)) * 180.0 / PI;
		angleB = acos((sideAB * sideAB + sideBC * sideBC - sideAC * sideAC) / (2 * sideAB * sideBC)) * 180.0 / PI;
		angleC = acos((sideBC * sideBC + sideAC * sideAC - sideAB * sideAB) / (2 * sideBC * sideAC)) * 180.0 / PI;

		break;
	case 2:
		double cosB;

		sideAB = A;
		sideBC = B;
		angleB = C;

		if (angleB <= 90)
		{
			cosB = cos(angleB * 180.0 / PI);
		}
		else
		{
			cosB = -cos(180 - angleB * 180.0 / PI);
		}

		sideAC = sqrt(sideAB * sideAB + sideBC * sideBC - 2 * sideAB * sideBC * cosB);
		angleA = acos((sideAB * sideAB + sideAC * sideAC - sideBC * sideBC) / (2 * sideAB * sideAC)) * 180.0 / PI;
		angleC = acos((sideBC * sideBC + sideAC * sideAC - sideAB * sideAB) / (2 * sideBC * sideAC)) * 180.0 / PI;

		break;
	case 3:
		angleA = A;
		angleB = B;
		sideAB = C;

		angleC = 180.0 - angleA - angleB;
		kayf = sideAB / sin(angleC * 180.0 / PI);
		sideBC = sin(angleA * 180.0 / PI) * kayf;
		sideAC = sin(angleB * 180.0 / PI) * kayf;

		break;
	default:
		sideAB = 0;
		sideBC = 0;
		sideAC = 0;

		angleA = 0;
		angleB = 0;
		angleC = 0;

		break;
	}
	
	if (!CheckSides() || !CheckAngles())
	{
		sideAB = 0;
		sideBC = 0;
		sideAC = 0;

		angleA = 0;
		angleB = 0;
		angleC = 0;
	}
}

//void Triangle::SetTwoSidesAndAngle(double A, double B, double C)
//{
//	double cosB;
//
//	sideAB = A;
//	sideBC = B;
//	angleB = C;
//
//	if (angleB <= 90)
//	{
//		cosB = cos(angleB * 180.0 / PI);
//	}
//	else
//	{
//		cosB = -cos(180 - angleB * 180.0 / PI);
//	}
//
//	sideAC = sqrt(sideAB * sideAB + sideBC * sideBC - 2 * sideAB * sideBC * cosB);
//	angleA = acos((sideAB * sideAB + sideAC * sideAC - sideBC * sideBC) / (2 * sideAB * sideAC)) * 180.0 / PI;
//	angleC = acos((sideBC * sideBC + sideAC * sideAC - sideAB * sideAB) / (2 * sideBC * sideAC)) * 180.0 / PI;
//
//	if (!CheckSides() || !CheckAngles())
//	{
//		sideAB = 0;
//		sideBC = 0;
//		sideAC = 0;
//
//		angleA = 0;
//		angleB = 0;
//		angleC = 0;
//	}
//}

//void Triangle::SetTwoAnglesAndSide(double A, double B, double C)
//{
//	angleA = A;
//	angleB = B;
//	sideAB = C;
//
//	angleC = 180.0 - angleA - angleB;
//	double kayf = sideAB / sin(angleC * 180.0 / PI);
//	sideBC = sin(angleA * 180.0 / PI) * kayf;
//	sideAC = sin(angleB * 180.0 / PI) * kayf;
//
//	if (!CheckSides() || !CheckAngles())
//	{
//		sideAB = 0;
//		sideBC = 0;
//		sideAC = 0;
//
//		angleA = 0;
//		angleB = 0;
//		angleC = 0;
//	}
//}

void Triangle::Set_sideAB(double _sideAB)
{
	sideAB = _sideAB;
}

void Triangle::Set_sideBC(double _sideBC)
{
	sideBC = _sideBC;
}

void Triangle::Set_sideAC(double _sideAC)
{
	sideAC = _sideAC;
}

void Triangle::Set_angleA(double _angleA)
{
	angleA = _angleA;
}

void Triangle::Set_angleB(double _angleB)
{
	angleB = _angleB;
}

void Triangle::Set_angleC(double _angleC)
{
	angleC = _angleC;
}

bool Triangle::CheckSides()
{
	if ((sideAB <= 0 || sideBC <= 0 || sideAC <= 0) || (sideAB + sideBC <= sideAC || sideBC + sideAC <= sideAB || sideAC + sideAB <= sideBC))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Triangle::CheckAngles()
{
	if ((abs(angleA) <= E || angleA - 180.0 >= E) || (abs(angleB) <= E || angleB - 180.0 >= E) || 
		(abs(angleC) <= E || angleC - 180.0 >= E) || (abs(angleA + angleB + angleC - 180.0) < E))
	{
		return false;
	}
	else
	{
		return true;
	}
}

double Triangle::Get_sideAB()
{
	return sideAB;
}

double Triangle::Get_sideBC()
{
	return sideBC;
}

double Triangle::Get_sideAC()
{
	return sideAC;
}

double Triangle::Get_angleA()
{
	return angleA;
}

double Triangle::Get_angleB()
{
	return angleB;
}

double Triangle::Get_angleC()
{
	return angleC;
}

double Triangle::CalcArea()
{
	double area;
	double h_perim = CalcPerim() / 2;

	return sqrt(h_perim * (h_perim - sideAB) * (h_perim - sideBC) * (h_perim - sideAC));
}

double Triangle::CalcPerim()
{
	return sideAB + sideBC + sideAC;
}

void Triangle::CalcHeights(double& h1, double& h2, double& h3)
{
	h1 = sideAB * sin(angleA * PI / 180.0);
	h2 = sideBC * sin(angleB * PI / 180.0);
	h3 = sideAC * sin(angleC * PI / 180.0);
}

std::string Triangle::TriType()
{
	std::string type;

	if (angleA - 90.0 < E && angleB - 90.0 < E && angleC - 90.0 < E)
	{
		type = "������������� �����������\n";
	}
	//else if (angleA - 90.0 > E || angleB - 90.0 > E || angleC - 90.0 > E)
	else if (abs(sideAB * sideAB + sideBC * sideBC - sideAC * sideAC) < E || abs(sideAC * sideAC + sideBC * sideBC - sideAB * sideAB) < E
		|| abs(sideAB * sideAB + sideAC * sideAC - sideBC * sideBC) < E)
	{
		type = "������������� �����������\n";
	} 
	else
	{
		type = "������������ �����������\n";
	}

	return type;
}

std::string Triangle::toString()
{
	return "������� AB = " + std::to_string(sideAB) + "\n������� BC = " + std::to_string(sideBC) + "\n������� AC = " + std::to_string(sideAC) + 
		"\n���� � = " + std::to_string(angleA) + "\n���� B = " + std::to_string(angleB) + "\n���� C = " + std::to_string(angleC) + "\n";
}
