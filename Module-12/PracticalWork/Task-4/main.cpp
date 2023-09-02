#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;


int main()
{
  int numbers[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
  int sumNumbers = 0;
  int sumNumbersAll = 0;
  int minNum = 1000000;

  cout << "\"Sequence of numbers\"" << endl;

  int coutNum = std::size(numbers); // Переменная определяет количество элементов в массиве

  for (int i = 0; i < coutNum; i++)
  {
    if (minNum > numbers[i])
    {
      minNum = numbers[i];
    }
    sumNumbersAll += numbers[i];
  }
  sumNumbers = ((coutNum - 1) * (minNum + (minNum + coutNum - 2))) / 2; // Формула Гауса

  if (sumNumbers > sumNumbersAll)
  {
    cout << "Repeating number: " << (sumNumbers - sumNumbersAll) - 1;
  }
  else
  {
    cout << "Repeating number: " << (sumNumbersAll - sumNumbers);
  }

  std::cin.ignore();
  std::cin.get();
  return 0;
}
