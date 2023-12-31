#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

std::string userName = "Player-1";
std::string winer = "";
char symbol_XO = 'X';
unsigned inputUser[2];
bool endGame = false;
int prov = 0;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};


void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hConsole, coord);
}

void chekInput()
{
	while (true)
	{
		getPositiveNumericArrayOfUserInput("Enter numbers from 1 to 3, X and Y coordinates: ", inputUser, 2, 1, 3);
		if (board[inputUser[0] - 1][inputUser[1]-1] != ' ')
		{
			cout << endl
				 << "Error!! The field is occupied, please enter again!" << endl;
			continue;
		}
		else if (board[inputUser[0]-1][inputUser[1]-1] == ' ')
		{
			if (userName == "Player-1")
			{
				symbol_XO = 'X';
			}
			if (userName == "Player-2")
			{
				symbol_XO = 'O';
			}
			break;
		}
		break;
	}
}

bool chekWiner()
{
	// Проверка по горизонтали
	for (size_t i = 0; i < 3; i++)
	{
		 if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) && board[i][0]!= ' ')
		 {
			 winer = userName;
			 return true;
		}
	}

	// for (size_t i = 0; i < 3; i++)
	// {
	// 	int numberRepitX = 0;
	// 	int numberRepitO = 0;
	// 	for (size_t y = 0; y < 3; y++)
	// 	{
	// 		if (board[i][y] == 'X')
	// 		{
	// 			++numberRepitX;
	// 		}
	// 		else if (board[i][y] == 'O')
	// 			++numberRepitO;
	// 	}
	// 	if (numberRepitX == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// 	else if (numberRepitO == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// }

	// Проверка по вертикали

	for (size_t i = 0; i < 3; i++)
	{
		 if (((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) && board[0][i]!= ' ')
		 {
			 winer = userName;
			 return true;
		}
	}
    
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	int numberRepitX = 0;
	// 	int numberRepitO = 0;
	// 	for (size_t y = 0; y < 3; y++)
	// 	{
	// 		if (board[y][i] == 'X')
	// 		{
	// 			++numberRepitX;
	// 		}
	// 		else if (board[y][i] == 'O')
	// 			++numberRepitO;
	// 	}
	// 	if (numberRepitX == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// 	else if (numberRepitO == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// }

    // Проверка по диагонали

	if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) && board[0][0]!= ' ')
	{
			 winer = userName;
			 return true;
	}
	
	if (((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) && board[0][2]!= ' ')
	{
			 winer = userName;
			 return true;
	}



	// for (size_t i = 0; i < 2; i++)
	// {
	// 	int numberRepitX = 0;
	// 	int numberRepitO = 0;
	// 	for (size_t y = 0; y < 3; y++)
	// 	{

	// 		if (board[y][(i == 0) ? y : 2 - y] == 'X')      
	// 		{
	// 			++numberRepitX;
	// 		}
	// 		else if (board[y][(i == 0) ? y : 2 - y] == 'O')
	// 			++numberRepitO;
	// 	}
	// 	if (numberRepitX == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// 	else if (numberRepitO == 3)
	// 	{
	// 		winer = userName;
	// 		return true;
	// 	}
	// }
	
	return false;
}

int main()
{
	while (!endGame)
	{
		char gameBoard[5][11] = {{' ',board[0][0],' ','|',' ',board[0][1],' ','|',' ',board[0][2],' '},
						{'-','-','-','|','-','-','-','|','-','-','-'},
						{' ',board[1][0],' ','|',' ',board[1][1],' ','|',' ',board[1][2],' '},
						{'-','-','-','|','-','-','-','|','-','-','-'},
						{' ',board[2][0],' ','|',' ',board[2][1],' ','|',' ',board[2][2],' '}};

		cout << "Game Tic Tac Toe!!" << endl
			 << endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t y = 0; y < 11; y++)
			{
				cout << gameBoard[i][y];
			}
			cout << endl;
		}

		cout << endl
			 << "Current " << userName << endl;
		chekInput();                                                       // Функция ввода и проверки что поле не занято
		board[inputUser[0] - 1][inputUser[1] - 1] = symbol_XO;             // Добавление Х или О в массив
		endGame = chekWiner();                                             // Функция проверки победы
		userName = (userName == "Player-1") ? "Player-2" : "Player-1";     // Смена игрока
        if(!endGame) clearConsole();
	}
	if(endGame){
		cout << "WINER: " << winer;
	}
	preventConsoleClosing();
	return 0;
}