#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits>

using std::cin;
using std::cout;
using std::endl;



int main()
{
  std::string text_user;
  const int sizeArray = 5;
  float numbersUser[sizeArray];
  cout << "\"Sorting\"" << endl;
  cout << "Enter 15 fractional numbers:"  << endl;

  while (true)                    // Цикл ввода и проверки что введены числа
  {
    bool inputBug = false;
    cout << "Input:";

    for (size_t i = 0; i < sizeArray; i++)
    {
      cin >> numbersUser[i];
      if (std::cin.fail())
      {
        cout << endl << "Error only numeric input is allowed" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputBug = true;
        break;
      }
      if (i == sizeArray-1 && cin.peek() != '\n' )
      {
        cout << endl << "Error: you need to enter: " << sizeArray << " numbers" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputBug = true;
        break;
      }
      if (i != sizeArray-1 && cin.peek() == '\n' )
      {
        cout << endl << "Error: you need to enter: " << sizeArray << " numbers" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputBug = true;
        break;
      }
    }
    if (inputBug == false)
    {
      break;
    }
  }

  
  for (size_t i = 0; i < sizeArray;)
  {
    if (numbersUser[i] < numbersUser[i + 1])
    {
      std::swap(numbersUser[i], numbersUser[i + 1]);
      i=0;
    }
    else
    {
      i++;
    }
  }

  cout << "Pin:";
  for (size_t i = 0; i < sizeArray; i++)
  {
    cout << numbersUser[i] << " ";
  }


  std::cin.ignore();
  std::cin.get();
  return 0;
}
