#include <iostream>
#include <string>
#include "user_input.hpp"

using std::cin;
using std::cout;
using std::endl;

size_t realSize = 0;

void outputVectorInt(const std::string msg, std::vector<int> vec)
{
	for (size_t i = 0; i <= realSize - 1; i++)
	{
		if (i == 0)
		{
			cout << msg;
			cout << vec[i] << " ";
		}
		else if (i > 0 && i < realSize  - 1)
			cout << vec[i] << " ";
		else if (i == realSize  - 1)
			cout << vec[i] << endl;
	}
}

std::vector<int> addVector(std::vector<int> vec, int userInput)
{
	for (size_t i = 0; i <= vec.size() -1; i++)
	{
		if(i < vec.size() - 1) 
		{
			vec[i] = vec[i + 1];
		}
		else if (i == vec.size() - 1)
		{
			vec[i] = userInput;
		}
	}
	return vec;
}

int main()
{
	
	std::vector<int> storageVector(20);
	int userInput = 0;

	cout << "Task 3... BUFFER" << endl << endl;

	while (true)
	{
		userInput = getNumericUserInput("Enter command: ");

		if (userInput == -1)
		{
			outputVectorInt("Output: ", storageVector);
		}
		else if (realSize < storageVector.size())  // Заполняем массив до 19го элемента
		{
			storageVector[realSize] = userInput;
			realSize++;
		}
		else if (realSize == storageVector.size()) // Вызов функци если realSize == 19
		{
			storageVector = addVector(storageVector, userInput);
		}

	}


	preventConsoleClosing();
	return 0;
}
