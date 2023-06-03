#include <iostream>
#include "SQmatrix.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag)
	{
		bool menu = true;
		while (menu)
		{
			int n;
			std::cout << "Напишите порядок матриц: "; std::cin >> n;
			int** matrix1 = new int* [n];
			int** matrix2 = new int* [n];
			for (int i = 0; i < n; i++)
			{
				matrix1[i] = new int[n];
			}
			for (int i = 0; i < n; i++)
			{
				matrix2[i] = new int[n];
			}
			std::cout << "\nЗаполните 1-ю матрицу: \n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cin >> matrix1[i][j];
				}
			}

			std::cout << "Заполните 2-ю матрицу: \n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cin >> matrix2[i][j];
				}
			}
			SQmatrix m1(n, matrix1);
			SQmatrix m2(n, matrix2);
			SQmatrix result;

			char choice1;
			std::cout << "Выберите арифметическое действие (сложение(+), вычитание(-), умножение матриц(*), умножение 1-й матрицы на число(n)): ";
			std::cin >> choice1;
			switch (choice1)
			{
			case '+':
				result = m1 + m2;
				menu = false;
				break;
			case '-':
				result = m1 - m2;
				menu = false;
				break;
			case '*':
				result = m1 * m2;
				menu = false;
				break;
			case 'n':
				int n;
				std::cout << "Введи число, которое нужно умножить: "; std::cin >> n;
				result = m1 * n;
				menu = false;
				break;
			case '=':
				if (m1 == m2)
					std::cout << "Они равны!\n";
				else
					std::cout << "Они не равны!\n";
				break;
			default:
				std::cout << "Неверный ввод! " << std::endl;
				menu = true;
				break;
			}
			std::cout << "Результат:\n" << result << std::endl;
			menu = false;
		}

		char choice;
		bool label = true;
		while (label)
		{
			std::cout << "Желаете начать заново или выйти? (1 - заново, 2 - выйти): ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "Неверный ввод!" << std::endl;
				label = true;
				break;
			case '1':
				flag = true;
				label = false;
				break;
			case '2':
				flag = false;
				label = false;
				break;
			}
		}
		
	}
}
