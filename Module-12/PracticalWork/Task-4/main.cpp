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
  int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
  int sumNumbers = 0;
  int sumNumbersAll = 0;
  int minNum = 1000000;

  cout << "\"Sequence of numbers\"" << endl;

  for (int i = 0; i < 15; i++)
  {
    if (minNum > numbers[i])
    {
      minNum = numbers[i];
    }
    sumNumbersAll += numbers[i];
  }
  sumNumbers = (14 * (minNum + (minNum + 13))) / 2; // Формула Гауса
 
  if (sumNumbers > sumNumbersAll)
  {
    cout << "Repeating number: " << (sumNumbers - sumNumbersAll) - 1;
  }
  else
  {
    cout << "Repeating number: " << (sumNumbersAll - sumNumbers) ;
  }

  std::cin.ignore();
  std::cin.get();
  return 0;
}
