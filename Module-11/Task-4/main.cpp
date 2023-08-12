#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

std::string chekWon(std::string strXO)
{
  std::string check = "Nobody";

  for (size_t i = 0; i <= 3; i++)  // Цыкл проверки победителя по вертикали
  {
    size_t y = 0;

    if (strXO[i] == 'X' && strXO[(y + 3) + i] == 'X' && strXO[(y + 6) + i] == 'X')
    {
      check = "Petya won";
    }
    else if (strXO[i] == 'O' && strXO[(y + 3) + i] == 'O' && strXO[(y + 6) + i] == 'O')
    {
      check = "Vanya won";
    }
  }

  for (size_t i = 0; i <= 6; i += 3)  // Цыкл проверки победителя по горизонтали
  {
    size_t y = i;

    if (strXO[i] == 'X' && strXO[(y + 1) + i] == 'X' && strXO[(y + 2) + i] == 'X')
    {
      check = "Petya won";
    }
    else if (strXO[i] == 'O' && strXO[(y + 1) + i] == 'O' && strXO[(y + 2) + i] == 'O')
    {
      check = "Vanya won";
    }
  }

  for (size_t i = 0; i <= 2; i += 2)  // Цыкл проверки победителя по диагонали
  {
    if (strXO[i] == 'X' && strXO[4] == 'X' && strXO[8 - i] == 'X')
    {
      check = "Petya won";
    }
    else if (strXO[i] == 'O' && strXO[4] == 'O' && strXO[8 - i] == 'O')
    {
      check = "Vanya won";
    }
  }

  int countX = 0;
  int countO = 0;
  for (size_t i = 0; i < strXO.length(); i++) // Цикл подсчета количества символов Х и О
  {
    if (strXO[i] == 'X')
    {
      countX++;
    }
    else if (strXO[i] == 'O')
    {
      countO++;
    }
  }
  if (check == "Petya won")    // Условие проверки ошибок если победил Петя
  {
    if (countX == countO || countX < countO || countX - 1 > countO)
    {
      check = "Incorrect-1";
    }
  }
  else if (check == "Vanya won") // Условие проверки ошибок если победил Ваня
  {
    if (countX == countO || countX > countO || countO - 1 > countX)
    {
      check = "Incorrect-2";
    }
  }
  else if (check == "Petya won" && check == "Vanya won")  // Условие проверки ошибок если есть два победителя
  {
    check = "Incorrect-3";
  }

  return check;
}

std::string checkIncorrect(std::string strXO)  // Функция проверки неккректности символов в полях и вызов функции chekWon для проверки победителя
{
  std::string check = "";
  for (size_t i = 0; i < strXO.length(); i++)
  {
    if (strXO[i] != 'X' && strXO[i] != 'O' && strXO[i] != '.')
    {
      return check = "Incorrect-0";
    }
  }
  return chekWon(strXO);
}

std::string mergingString(std::string str0, std::string str1, std::string str2)  // функция объединеня строк и вызов функции проверки checkIncorrect()
{
  return checkIncorrect(str0 + str1 + str2);
}

int main()
{
  std::string text_user_str0 = "";
  std::string text_user_str1 = "";
  std::string text_user_str2 = "";
  std::string check_str;
  cout << "Checking Game: tic-tac-toe" << endl << endl;
  cout << "Enter the results of the game in three lines X and O:" << endl;
  std::getline(cin, text_user_str0);
  std::getline(cin, text_user_str1);
  std::getline(cin, text_user_str2);
  check_str = mergingString (text_user_str0, text_user_str1, text_user_str2);
  cout << "\nAnswer: " + check_str;

  std::cin.ignore(10000,'\n');
  std::cin.get();
  return 0;
}

