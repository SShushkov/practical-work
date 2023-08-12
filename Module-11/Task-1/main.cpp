#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;


int enter_user_shift () 
{
  int numberShift;
  while (true)
  {
    cout << "Enter a shift integer:";
    cin >> numberShift;
    if (cin.fail() || cin.peek() != '\n')
    {
      std::cerr << "Data entry error!\n\n";
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
      break;
  }
  return numberShift;
}

char shift(char simvol, int dev)
{
  char result = simvol;
  if (simvol >= 'A' && simvol <= 'Z')
  {
    if (dev < 0)
    {
      result = char(int('Z') - (((int('Z') - int(simvol)) - dev) % 26));
    }
    else
    {
      result = char((((int(simvol) - int('A')) + dev) % 26) + int('A'));
    }
  }
  else if (simvol >= 'a' && simvol <= 'z')
  {
    if (dev < 0)
    {
      result = char(int('z') - (((int('z') - int(simvol)) - dev) % 26));
    }
    else
    {
      result = char((((int(simvol) - int('a')) + dev) % 26) + int('a'));
    }
  }
  return result;
}

std::string encrypt_caesar(std::string str1, int dev)
{
  std::string str2;
  for (size_t i = 0; i < str1.length(); i++)
  {
    str2 += shift(char(str1[i]), dev);
  }
  return str2;
}

std::string decrypt_caesar(std::string str1, int dev)
{
  std::string str2;
  for (size_t i = 0; i < str1.length(); i++) {
    str2 += shift(char(str1[i]), dev * -1);
  }
  return str2;
}

int main()
{
  std::string text_user;
  std::string text_encrypted;
  std::string text_decrypted;
  int count_shift;
  cout << "Text encryption program \"Caesar Encrypt\"" << endl;
  cout << "Enter the encryption text:";
  std::getline(cin, text_user);
  count_shift = enter_user_shift(); // Вызов функции ввода числа сдвига и присваивания значения
  text_encrypted = encrypt_caesar(text_user, count_shift); // Вызовы функци шифрования encrypt_caesar()
  cout << "\nYour source text: " << text_user << std::endl;
  cout << "Your shift number: " << count_shift << std::endl;
  cout << "Your encrypted text: " << text_encrypted << std::endl;
  text_decrypted = decrypt_caesar(text_encrypted, count_shift); // Вызовы функци дешифровки decrypt_caesar()
  cout << "Your decrypted text: " << text_decrypted;

  std::cin.ignore();
  std::cin.get();
  return 0;
}
