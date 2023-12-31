#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

void creatingDiagonalMatrix(const std::string msg, int a[][4], size_t rows, size_t cols)  // Функция преобразование в диагональную матрицу 
{
	cout << endl
		 << msg << endl;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i != j)
			{
				a[i][j] = 0;
			}
		}
	}
}

void matrixСomparison(int matA[][4], int matB[][4],size_t rows, size_t cols)  // Функция сравнения матриц
{
	//bool equa = std::equal(&matA[0][0], &matA[0][0] + rows * cols, &matB[0][0]);
	bool equa = std::equal(matA[0], (matA+3)[0], matB[0]);

	if (equa){
		cout << endl << "The matrices are equal.." << endl;
	}
	else{
		cout << endl << "Matrices are not equal.." << endl;
	}

}

void matrixOutput (const std::string msg,int a [][4], size_t rows, size_t cols) // Функция вывода массива
{
	cout << endl << msg << endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t y = 0; y < cols; y++)
		{
			cout << a[i][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void matrixInput (const std::string msg,int a [][4])   // Функция ввода массва
{
	cout << msg << endl;
	for (size_t i = 0; i < 4; i++)
	{
		unsigned b[4];
		getPositiveNumericArrayOfUserInput("Enter the 4 elements of the " + std::to_string(i)  + " row of the matrix: ", b, 4);
		for (size_t y = 0; y < 4; y++)
		{
			a[i][y] = b[y];
		}
	}
	cout << endl;
}

int main()
{

	int a[4][4];
	int b[4][4];

	matrixInput("Enter matrix a: ", a);
	matrixInput("Enter matrix b: ", b);

	matrixOutput("Matrix \"a\" output:", a, 4, 4);
	matrixOutput("Matrix \"b\" output:",b, 4, 4);

	matrixСomparison(a, b, 4, 4);

	creatingDiagonalMatrix("Creating a diagonal matrix...", a, 4, 4);
	matrixOutput("Diagonal Matrix output:", a, 4, 4);

	preventConsoleClosing();
	return 0;
}