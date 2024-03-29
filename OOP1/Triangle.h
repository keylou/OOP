#ifndef TRIANGLE_LAB1_OOP
#define TRIANGLE_LAB1_OOP
#define PI 3.1415926
#define E 1e-10

#include <iostream>
#include <cmath>
#include <string>

class Triangle
{
private:
	double sideAB, sideBC, sideAC;
	double angleA, angleB, angleC;
	bool CheckSides();
	bool CheckAngles();

public:
	Triangle();
	Triangle(double, double, double, int);
	//void SetTwoSidesAndAngle(double, double, double);
	//void SetTwoAnglesAndSide(double, double, double);

	void Set_sideAB(double);
	void Set_sideBC(double);
	void Set_sideAC(double);
	void Set_angleA(double);
	void Set_angleB(double);
	void Set_angleC(double);
	
	double Get_sideAB();
	double Get_sideBC();
	double Get_sideAC();
	double Get_angleA();
	double Get_angleB();
	double Get_angleC();

	double CalcArea();
	double CalcPerim();
	void CalcHeights(double&, double&, double&);
	std::string TriType();

	std::string toString();
};

#endif
