#include <string>
#include <iostream>
#include <Windows.h>
#include "Linear.h"
#include "Exponential.h"
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Введите размерность последовательностей \n";
	int n;
	cin >> n;

	Series* l = new Linear(n);
	Series* e = new Exponential(n);
	Linear* p_l = dynamic_cast<Linear*>(l);
	Exponential* p_e = dynamic_cast<Exponential*>(e);

	cout << "Введём пару алг или геом прогрессию?(1/2)\n";
	int menu;
	cin >> menu;

	switch (menu)
	{
	case 1:
		cout << "Введите a0 и d\n";
		double a0, d;
		cin >> a0 >> d;
		p_l->set_d(d);
		p_l->set_arr(a0);
		p_l->print();

		cout << "Выберите необходимое действие:\n 1)Вывести N-ый элемент \n 2)Сумма до N-ого члена\n";
		int menu_act;
		cin >> menu_act;
		switch (menu_act)
		{
		case 1:
			int n;
			do
			{
				cout << "Введите нужный член n(>0)\n";
				cin >> n;
			} while (n < 0);
			cout << "N-ый член =" << l->n_elem(n - 1) << "\n";
			break;
		case 2:
			do
			{
				cout << "Введите нужный член n(>0)\n";
				cin >> n;
			} while (n < 0);
			cout << "Cумма до N-го члена=";
			cout << l->sum(n - 1) << "\n";
			break;
		}
		break;
	case 2:
		cout << "Введите a0 и q\n";
		double a0_e, q;
		cin >> a0_e >> q;
		p_e->set_d(q);
		p_e->set_arr(a0_e);
		p_e->print();
		cout << "Выберите необходимое действие?\n 1)Вывести N-ый элемент \n 2)Сумма до N-ого члена\n";
		cin >> menu_act;
		switch (menu_act)
		{
		case 1:
			int n;
			do
			{
				cout << "Введите нужный член n(>0)\n";
				cin >> n;
			} while (n < 0);
			cout << "N-ый член =" << e->n_elem(n - 1) << "\n";
			break;
		case 2:
			do
			{
				cout << "Введите нужный член n(>0)\n";
				cin >> n;
			} while (n < 0);
			cout << "Cумма до N-го члена=";
			cout << e->sum(n - 1) << "\n";
			break;
		}
		break;
	}
	delete l, e;
	cin.ignore();
	cin.get();
	return 0;
}
