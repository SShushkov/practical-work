#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

void initArr(size_t arr[][5]) // Функция инициализации змейкой
{
	size_t counter = 0;
	for (int i = 0; i < 5; ++i)
	{
		int multiplier = -1 + (i % 2 * 2);
		for (int j = 0; j < 5; ++j)
		{
			arr[i][(4 * (i % 2)) - (j * multiplier)] = counter;
			counter++;
		}
	}
}
void outputArr(size_t arr[][5])
{
	cout << endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	size_t snakeArr[5][5];

	cout << "TASK-6 Snake..." << endl;

	initArr(snakeArr);	 // Вызов функции инициализации массива змейкой
	outputArr(snakeArr); // Вызов функции вывода массива

	preventConsoleClosing();
	return 0;
}