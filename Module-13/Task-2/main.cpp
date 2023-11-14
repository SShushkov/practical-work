#include <iostream>
#include <string>
#include "user_input.hpp"

using std::cin;
using std::cout;
using std::endl;

void outputVectorInt(const std::string msg, std::vector<int> vec)
{
	for (size_t i = 0; i <= vec.size()-1; i++)
	{
		if (i == 0)
		{
			cout << msg;
			cout << vec[i] << ", ";
		}
		else if (i > 0 && i < vec.size()-1)
			cout << vec[i] << ", ";
		else if (i == vec.size()-1)
			cout << vec[i] << endl;
	}
}
void outputVectorFloat(const std::string msg, std::vector<float> vec)
{
	for (size_t i = 0; i <= vec.size()-1; i++)
	{
		if (i == 0)
		{
			cout << msg;
			cout << vec[i] << ", ";
		}
		else if (i > 0 && i < vec.size()-1)
			cout << vec[i] << ", ";
		else if (i == vec.size()-1)
			cout << vec[i] << endl;
	}
}

int main()
{
	std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
	std::vector<int> items{1, 1, 0, 3};
	float amountCost = 0;

	cout << "Task 2.. SHOPING." << endl;

	for (size_t i = 0; i < items.size(); i++)
	{
		amountCost += prices[items[i]];
	}

	outputVectorFloat("Prices: ", prices);
	outputVectorInt("Items: ", items);
	cout << "Total cost of purchases = " << amountCost << endl;

	preventConsoleClosing();
	return 0;
}
