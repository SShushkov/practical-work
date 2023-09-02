#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool checText (std::string textUser) // Функция проверки что введена фамилия буквами без цифр и символов
{
  for (size_t i = 0; i < textUser.length(); i++)
  {
    if (isalpha(textUser[i]) == 0)
    {
      return false;
    }
  }
  return true;
}

bool checTextNum (std::string textUser) // Функция проверки что номер квартир от 1 до 10 и не буква
{
  for (size_t i = 0; i < textUser.length(); i++)
  {
    if (isdigit(textUser[i]) == 0)
    {
      return false;
    }
    int num1 = std::stoi(textUser);

    if (num1 < 1 || num1 > 10) 
    {
      return false;
    }
  }
  return true;
}

void residentsOut (std::string namesResidents[]) // Функция для вывода фамилий согласно номерам квартир
{
  std::string text_user;
  cout << endl << "Options:" << endl;
  cout << "1. To exit the program, enter: \"Exit\"" << endl;
  cout << "2. Enter the apartment number from 1st to 10th: " << endl;
  while (true)
  {
    cin >> text_user;
    if (text_user == " Exit" || text_user == "exit") 
    {
      cout << "Exiting the program...";
      break;
    }
    else if (checTextNum(text_user) == false)
    {
      cout << "Input error, you must enter only numbers from 1 to 10." << endl;
      continue;
    }
    else if (checTextNum(text_user) == true)
    {
      cout << "In apartment number " << text_user << ", the tenant lives: " << namesResidents[std::stoi(text_user) - 1] << endl;
    }
  }
}

int main()
{
  std::string text_user;
  std::string namesResidents[10];
  cout << "\"Apartment house\"" << endl;
  cout << "It is necessary to write down the names of residents from the 1st to the 10th apartment:"  << endl;

  for (int i = 0; i < 10; )   // Цикл для ввода фамилий жильцов квартир
  {
    int y = i;
    cout << "Enter the last name of the tenant in the apartment #" << y + 1 << ": ";
    //cout << "int i = " << i << endl;
    cin >> text_user;
    if (checText(text_user) == false) 
    {
      cout << "Input error, only letters" << endl;
      continue;
    }
    else 
    {
      namesResidents[i] = text_user;
      i++;
    }
  }

  residentsOut(namesResidents); // Вызов функции для вывода фамилий жильцов квартир

  std::cin.ignore();
  std::cin.get();
  return 0;
}
