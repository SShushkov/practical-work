#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;


void vectorOutput (const std::string msg, std::vector<float> vec) // Функция вывода массива
{
	cout << endl << msg << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

std::vector<float> multiplyMatrix (float mat[][4],  std::vector<float> vec)
{
	std::vector<float> vecMultiply(4);

	for (size_t i = 0; i < 4; i++)
	{
		float sum = 0;
		for (size_t j = 0; j < 4; j++)
		{
			sum += mat[i][j] * vec[j];
		}
		vecMultiply[i] = sum;
	}
	return vecMultiply;
}

void matrixInput (const std::string msg,float a [][4])   // Функция ввода массва
{
	cout << msg << endl;
	for (size_t i = 0; i < 4; i++)
	{
		float b[4];
		getFloatNumberArrayOfUserInput ("Enter the 4 elements of the " + std::to_string(i)  + " row of the matrix: ", b, 4);
		for (size_t y = 0; y < 4; y++)
		{
			a[i][y] = b[y];
		}
	}
	cout << endl;
}

std::vector<float> vectorInput(std::string msg, std::vector<float> vec)
{
	cout << endl << msg << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = getFloatingPointNumericUserInput("Enter the " + std::to_string(i) + " element of the vector: ");
	}
	return vec;
}

int main()
{
	cout << "Multiplying a matrix by a vector!" << endl
		 << endl;

	float a[4][4];
	std::vector<float> b(4);
	std::vector<float> c(4);

    matrixInput("Enter matrix a: ", a);
	b = vectorInput("Enter vector b: ", b);
	c = multiplyMatrix(a, b);
	vectorOutput("Multiplying  matrix \"a\" by  vector \"b\"!", c);

	preventConsoleClosing();
	return 0;
}