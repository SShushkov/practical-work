#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

std::string check_email2 (std::string str1, size_t y)
{
  std::string str2;
  int countWord = 0;

  for (size_t i = y; i < str1.length(); i++)
  {
    if ((str1[i] >= '0' && str1[i] <= '9') || (str1[i] >= 'a' && str1[i] <= '~') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == '!') || (str1[i] >= '#' && str1[i] <= '\'' ) ||
        (str1[i] == '*') || (str1[i] == '+') || (str1[i] == '-') || (str1[i] == '=') || (str1[i] == '?') || (str1[i] == '^') || (str1[i] == '_') ||
        (str1[i] == '`') || (str1[i] == '@') || (str1[i] == '.') ) 
    {
      countWord++;
      if (str1[i] == '@') 
      {
        return str2 = "No: Error-5 invalid character @";
      }
      if (str1[y] == '.') 
      {
        return str2 = "No: Error-6";
      }
      if (countWord > 63) 
      {
        return str2 = "No: Error-7 maximum domain length 63";
      }
      if (((str1[i] == '.') && (str1[i+1] == '.')) )
      {
        return str2 = "No: Error-8 it is not allowed to use a dot or a @" ;
      }
    }
    else 
    {
      return str2 = "No: Error-01 invalid character";
    }
  }
  return str1 = "\nYes, your email address: " + str1 +  " - is correct ";
}

std::string check_email1 (std::string str1)
{
  std::string str2;
  int countWord = 0;

  for (size_t i = 0; i < str1.length(); i++)
  {
    if ((str1[i] >= '0' && str1[i] <= '9') || (str1[i] >= 'a' && str1[i] <= '~') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == '!') || (str1[i] >= '#' && str1[i] <= '\'' ) ||
        (str1[i] == '*') || (str1[i] == '+') || (str1[i] == '-') || (str1[i] == '=') || (str1[i] == '?') || (str1[i] == '^') || (str1[i] == '_') ||
        (str1[i] == '`') || (str1[i] == '@') || (str1[i] == '.') ) 
    {
      countWord++;
      if (countWord > 64) 
      {
        return str2 = "No: Error-1 maximum address length 64";
      }
      if ((str1[0] == '.') || ((str1[i] == '.') && (str1[i+1] == '.')) || ((str1[i] == '@') && (str1[i+1] == '@')) || (str1[0] == '@') )
      {
        return str2 = "No: Error-2 it is not allowed to use a dot or a @";
      }
      if (str1[i] == '@') 
      {
        str2 = check_email2(str1, i+1); // Вызов функции проверки второй части адреса
        if (str2 == "No: Error-01" || str2 == "No: Error-5" || str2 == "No: Error-6" || str2 == "No: Error-7" || str2 == "No: Error-8")
        {
          return str2;
        }
        else 
        {
          return str2;
        }
      }
      if (str1[i+1] == '\0' && str1[i] != '@')
      {
        return str2 = "No: Error-3";
      }
    }
    else 
    {
      return str2 = "No: Error-0 invalid character";
    }
  }
  return str1 = "\nYes, your email address: " + str1 +  " - is correct ";
}

int main()
{

  std::string text_user;
  std::string checkEmail;
  cout << "Checking the email address" << endl << endl;
  cout << "Enter the email address:";
  std::getline(cin, text_user);
  checkEmail = check_email1(text_user); // Вызов функции проверки первой части адреса
  cout <<  checkEmail << std::endl;

  std::cin.ignore();
  std::cin.get();
  return 0;
}

