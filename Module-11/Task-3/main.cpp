#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

std::string get_address_part(std::string textPart, int okta)
{
  if (textPart.length() > 4 && okta < 3)
  {
    return "Invalid-0";
  }
  else if (textPart.length() > 3 && okta == 3)
  {
    return "Invalid-0";
  }
  if (textPart[textPart.length() - 1] == '.' && okta == 3)
  {
    return "Invalid-1";
  }
  if (textPart[0] == '.')
  {
    return "Invalid-1";
  }

  for (size_t i = 0; i < textPart.length(); i++)
  {
    if ((textPart[i] < '0' || textPart[i] > '9') && textPart[i] != '.')
    {
      return "Invalid-2";
    }
    if ((textPart[0] == '0' && textPart[1] != '.') && okta <= 2)
    {
      return "Invalid-3";
    }
  }
  if (okta < 3)
  {
    textPart.pop_back();
    int number = std::stoi(textPart);
    if (number < 0 || number > 255)
    {
      return "Invalid-4";
    }
  }
  else
  {
    int number = std::stoi(textPart);
    if (number < 0 || number > 255)
    {
      return "Invalid-4";
    }
  }
  return "Valid";
}

std::string sendPart(std::string ipAdress)
{
  std::string textPart = "";
  std::string result = "";
  int numOkta = 0;
  for (size_t i = 0; i < ipAdress.length(); i++)
  {
    textPart += ipAdress[i];
    if (ipAdress[i] == '.' && numOkta < 3)
    {
      result = get_address_part(textPart, numOkta);
      numOkta++;
      textPart.clear();
      if (result == "Invalid-0" || result == "Invalid-1" || result == "Invalid-2" || result == "Invalid-3" || result == "Invalid-4" || result == "Invalid-222")
      {
        return result;
      }
    }
    else if (i == ipAdress.length() - 1)
    {
      result = get_address_part(textPart, numOkta);
      if (result == "Invalid-0" || result == "Invalid-1" || result == "Invalid-2" || result == "Invalid-3" || result == "Invalid-4" || result == "Invalid-222")
      {
        return result;
      }
    }
  }
  return result;
}

int main()
{
  std::string text_user = "";
  std::string checkIP_str;
  cout << "Checking the IP address" << endl << endl;
  cout << "Enter the IP address:";
  std::getline(cin, text_user);
  checkIP_str = sendPart(text_user);
  cout << "\nYour IP adress: " + checkIP_str;

  std::cin.ignore(10000,'\n');
  std::cin.get();
  return 0;
}

