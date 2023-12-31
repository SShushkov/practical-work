#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

void inputUserBlockMatrix(size_t blockMatrix[][5])                       // Функция ввода высоты блока в виде 2х мерного массива для функции initBlockMarix
{
	unsigned blockRows[5];
	for (size_t i = 0; i < 5; i++)
	{
		getPositiveNumericArrayOfUserInput("Input rows " + std::to_string(i) + " matrix of heights from 0 to 10: ", blockRows, 5, 0, 10);
		for (size_t j = 0; j < 5; j++)
		{
			blockMatrix[i][j] = blockRows[j];
		}
	}
}

void initBlockMarix(size_t blockMat[5][5][10], size_t blockLevel[][5])   //Функция инициализации трехмерного массива на основе массива blockuser[5][5];
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			for (size_t level = 0; level < 10; level++)
			{
				blockMat[i][j][level] = ((blockLevel[i][j] >= level) && (blockLevel[i][j] != 0)) ? 1 : 0;
			}
		}
	}
}


void sliceMatrix(size_t blockMat[5][5][10], size_t level)                //Функция среза и вовода
{
	cout << endl
		 << "Output slice level - " + std::to_string(level) + ": " << endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			cout << blockMat[i][j][level] << " ";
		}
		cout << endl;
	}
}

int main()
{
	size_t blockMatrix[5][5][10];
	size_t blockuser[5][5];
	size_t inputLevel;

	cout << "BLOCK MAINCRAFT!!" << endl
		 << endl;

	inputUserBlockMatrix(blockuser);
	initBlockMarix(blockMatrix, blockuser);

	while (true)
	{
		cout << endl;
		inputLevel = getPositiveNumericUserInput("Input slice from 0 to 9: ", 0, 9);
		sliceMatrix(blockMatrix, inputLevel);
	}

	preventConsoleClosing();
	return 0;
}