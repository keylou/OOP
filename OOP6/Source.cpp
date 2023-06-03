#include "Flex_Array.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag)
	{
		int sizeA;
		cout << "Введите размер гибкого массива: ";
		cin >> sizeA;
		Flex_Array<int> A(sizeA);
		cout << "Введите элементы: ";
		for (int i = 0; i < sizeA; i++)
		{
			cin >> A[i];
		}

		char oper;
		bool label1 = true;
		bool label2 = true;
		while (label1)
		{
			cout << "Выберите операцию: 1)добавить, 2) удалить, 3)заменить, 4)найти: ";
			cin >> oper;
			switch (oper)
			{
			case '1':
			{
				int sizeB;
				cout << "Введите количество добавляемых элементов: ";
				cin >> sizeB;
				Flex_Array<int> B(sizeB);
				cout << "Введи элементы: ";
				for (int i = 0; i < sizeB; i++)
				{
					cin >> B[i];
				}

				int id;
				cout << "Введите номер, в который вложить элементы(начинаю с 0): "; cin >> id;
				A.append(id, B);

				cout << "Результат: " << endl;
				for (int i = 0; i < A.get_size(); i++)
					cout << A[i] << " ";

				label1 = false;
				break;
			}
			case '2':
				int id1, id2;
				cout << "Введите границы удаляемых элементов(начинаю с 0): "; cin >> id1 >> id2;
				A.remove(id1, id2);

				cout << "Результат: " << endl;
				for (int i = 0; i < A.get_size(); i++)
					cout << A[i] << " ";

				label1 = false;
				break;
			case '3':
			{
				int sizeB;
				cout << "Введите количество заменяемых элементов: ";
				cin >> sizeB;
				Flex_Array<int> B(sizeB);
				cout << "Введи элементы: ";
				for (int i = 0; i < sizeB; i++)
				{
					cin >> B[i];
				}

				int id1, id2;
				cout << "Ввести границы замены(начинаю с 0): "; cin >> id1 >> id2;

				A.replace(id1, id2, B);

				cout << "Результат: " << endl;
				for (int i = 0; i < sizeA; i++)
					cout << A[i] << " ";

				label1 = false;
				break;
			}
			case '4':
				char mode2;
				while (label2) {
					cout << "1)поиск одного элемента, 2) поиск группы элементов: "; cin >> mode2;
					switch (mode2)
					{
					case '1':
						int ch;
						cout << "Введите элемент: "; cin >> ch;
						cout << "Результат: [" << A.find(ch) << "]" << endl;
						label2 = false;
						break;
					case '2':
					{
						int sizeB;
						cout << "Введите кол-во элементов: " << endl;
						cin >> sizeB;
						Flex_Array<int> B(sizeB);
						cout << "Введите элементы: ";
						for (int i = 0; i < sizeB; i++)
						{
							cin >> B[i];
						}
						cout << "Результат: [" << A.finds(B) << "]" << endl;
						label2 = false;
						break;
					}
					default:
						cout << "Неверный ввод!" << endl;
						label2 = true;
						break;
					}
				}
				label1 = false;
				break;
			default:
				cout << "Неверный ввод!" << endl;
				label1 = true;
				break;
			}
		}

		char choice;
		bool label3 = true;
		while (label3)
		{
			cout << "Желаете начать заново или выйти? 1 - заново, 2 - выйти ";
			cin >> choice;
			switch (choice)
			{
			default:
				cout << "Неверный ввод!" << endl;
				label3 = true;
				break;
			case '1':
				flag = true;
				label3 = false;
				break;
			case '2':
				flag = false;
				label3 = false;
				break;
			}
		}
	}
}
