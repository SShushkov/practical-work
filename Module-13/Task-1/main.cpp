#include <iostream>
#include <string>
#include "user_input.hpp"

using std::cin;
using std::cout;
using std::endl;

void outputVector(const std::string msg, std::vector<int> vec)
{
	if (!vec.empty())
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (i == 0)
				cout << msg << endl;
			cout << vec[i] << " " << endl;
		}
	else
	{
		cout << msg << " Vector EMPTY.";
	}
}

int main()
{
	cout << "Task - 1....." << endl;
	std::vector<int> vec((size_t)getPositiveNumericUserInput("Input vector size: "));
	vec = getNumericSequenceOfUserInput("Input numbers: ", vec.size());
	int numberDel = getNumericUserInput("Input number to delete: ");
	bool flag = false;
	// outputVector("Result:", vec);

	for (size_t i = 0; i <= vec.size() - 1 && !vec.empty(); i++)
	{
	if (vec[i] == numberDel)
	{
		flag = true;
	}
	while (flag)
	{
		for (size_t y = i; y <= vec.size() - 1; y++)
		{
			if (vec.size() - 1 != y)
			{
				cout << "Siz: " << vec.size() << endl;
				vec[y] = vec[y + 1];
			}
			if (y == vec.size() - 1)
			{
				vec.pop_back();
				flag = false;
				i--;
				break;
			}
		}
	}
	}
	outputVector("Result:", vec);

	preventConsoleClosing();
	return 0;
}
