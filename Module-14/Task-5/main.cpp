#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

int countPopit = 144;

void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hConsole, coord);
}

void initPopit (bool pop [][12]){
	for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < 12; j++)
		{
			pop[i][j] = true;
		}
	}
}

bool outputPopit (bool pop[][12])
{
	cout << "  X 1  2  3  4  5  6  7  8  9  10 11 12" << endl;
	cout << "    |  |  |  |  |  |  |  |  |  |  |  | " << endl;
	cout << "Y   ___________________________________" << endl;
	for (size_t i = 0; i < 12; i++)
	{
		if(i < 9) cout << i + 1 << "--|";
		else if( i >= 9)cout << i + 1 << "-|";

		for (size_t j = 0; j < 12; j++)
		{
			
			if(pop[i][j]){
				cout << "O"
					 << "  ";
			}
			else if(!pop[i][j]){
				countPopit--;
				cout << "X"
					 << "  ";
			}
		}
		cout << endl;
	}
	if(countPopit <= 0)
		return true;
	return false;
}

void crashPopit (bool pop [][12])
{
	unsigned coordFirst[2];
	unsigned coordSecond[2];
	while(true){
		getPositiveNumericArrayOfUserInput("Enter the X Y coordinates of the first corner: ", coordFirst, 2, 1, 12);
		getPositiveNumericArrayOfUserInput("Enter the X Y coordinates of the second corner: ", coordSecond,2, 1, 12);
		if(coordFirst[0] > coordSecond[0] || coordFirst[1] > coordSecond[1]){
			cout << "Error!! Please enter the correct range..." << endl;
			continue;
		}
		break;
	}
	for (size_t i = coordFirst[1]-1; i < coordSecond[1]; i++)
	{
		for (size_t j = coordFirst[0]-1; j < coordSecond[0]; j++)
		{
			pop[i][j] = false;
		}
		
	}
}

int main()
{
	bool endGame = false;
	bool popit[12][12];
	initPopit(popit);
    
	while(!endGame){
		clearConsole();
		cout << countPopit << endl;
		cout << "POP IT!" << endl
			 << endl;
		cout << endl;
		endGame = outputPopit(popit);
		cout << endl;
		if(endGame) {
			break;
		}
		crashPopit(popit);
	}
	if (endGame) {
		cout << endl
			 << "END GAME!!" << endl;
	}

	preventConsoleClosing();
	return 0;
}