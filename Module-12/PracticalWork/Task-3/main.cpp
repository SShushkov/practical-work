#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

float travelTime(float distance, float speed)
{
  assert(speed > 0 && "Скорость не может быть равна или ниже нуля" ); // Скорость не может быть равна или ниже нуля
  assert(distance > 0 && "расстояние не может быть равно или ниже нуля" );
  return distance * speed;
}


int main()
{
  std::string text_user;
  float traveledKM = 0;
  float speedKmh = 0;
  cout << "\"TIME-TRAVEL\"" << endl;
  cout << "Enter the distance traveled in km:"  << endl;
  cin >> traveledKM;
  cout << "Enter the speed km/h:"  << endl;
  cin >> speedKmh;

 cout << "Distance: " << travelTime(traveledKM, speedKmh);

  std::cin.ignore();
  std::cin.get();
  return 0;
}
