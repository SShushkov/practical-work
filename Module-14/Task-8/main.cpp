#include <iostream>
#include <string>
#include "user_input.hpp"
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;


void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hConsole, coord);
}

/////////////////////////////////////////////////// Установка кораблей

void InitBoardStart(size_t playaerId, char board[2][10][10])
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			board[playaerId][i][j] = '~';
		}
	}
}


void DisplayingBoardScreen(char board[2][10][10], unsigned playaerId)
{
	unsigned id_1 = ((playaerId == 0) ? 0 : 1);
	unsigned id_2 = ((playaerId == 1) ? 0 : 1);
	cout << "     Board " << "Player-" << id_1+1  << "\t\t\t" << "     Board " << "Player-" << id_2+1 << endl << endl;

	cout << "  0 1 2 3 4 5 6 7 8 9 \t\t\t  0 1 2 3 4 5 6 7 8 9"<< endl;
	for (size_t i = 0; i <= 9; i++)
	{
		// cout  <<i<<"|"<<board[id_1][i][0]<<" "<<board[id_1][i][1]<<" "<<board[id_1][i][2]<<" "<<board[id_1][i][3]<<" "<<board[id_1][i][4]<<" "<<board[id_1][i][5]<<" "<<board[id_1][i][6]<<" "<<board[id_1][i][7]<<" "<<board[id_1][i][8]<<" "<<board[id_1][i][9]<<"|\t\t\t"
		// 	  <<i<<"|"<<board[id_2][i][0]<<" "<<board[id_2][i][1]<<" "<<board[id_2][i][2]<<" "<<board[id_2][i][3]<<" "<<board[id_2][i][4]<<" "<<board[id_2][i][5]<<" "<<board[id_2][i][6]<<" "<<board[id_2][i][7]<<" "<<board[id_2][i][8]<<" "<<board[id_2][i][9]<<"|"<< endl;

		cout  <<i<<"|"<<board[id_1][i][0]<<" "<<board[id_1][i][1]<<" "<<board[id_1][i][2]<<" "<<board[id_1][i][3]<<" "<<board[id_1][i][4]<<" "<<board[id_1][i][5]<<" "<<board[id_1][i][6]<<" "<<board[id_1][i][7]<<" "<<board[id_1][i][8]<<" "<<board[id_1][i][9]<<"|\t\t\t"
			  <<i<<"|"<<((board[id_2][i][0] == 'O') ? '~' : board[id_2][i][0])<<" "<<((board[id_2][i][1] == 'O') ? '~' : board[id_2][i][1])<<" "<<((board[id_2][i][2] == 'O') ? '~' : board[id_2][i][2])<<" "<<((board[id_2][i][3] == 'O') ? '~' : board[id_2][i][3])<<" "<<((board[id_2][i][4] == 'O') ? '~' : board[id_2][i][4])<<" "<<((board[id_2][i][5] == 'O') ? '~' : board[id_2][i][5])<<" "<<((board[id_2][i][6] == 'O') ? '~' : board[id_2][i][6])<<" "<<((board[id_2][i][7] == 'O') ? '~' : board[id_2][i][7])<<" "<<((board[id_2][i][8] == 'O') ? '~' : board[id_2][i][8])<<" "<<((board[id_2][i][9] == 'O') ? '~' : board[id_2][i][9])<<"|"<< endl;
	}
}



unsigned getTypeShip(const unsigned location[][2])
{
    return location[1][0] - location[0][0] + location[1][1] - location[0][1] + 1;  // x2 - x1 + y2 - y1 + 1
};


bool ValidLocationShip (unsigned location[][2], unsigned shipId)            // Функция проверки ввод 2-x 3-х 4-х палуб не по диагонали
{    
	if((shipId <= 3)){
		if((location[0][0] != location[1][0]) || (location[0][1] != location[1][1]) )
		return false; 
	}
	else {
		if((location[0][1] != location[1][1]) && (location[0][0] != location[1][0]))
		{
			return false;
		}
	}
	return true;
}




void placeShipOnBoard(char board[][10][10], const unsigned location[][2], const unsigned playerId)
{
    for (size_t i = location[0][0]; i <= location[1][0]; i++)
        for (size_t j = location[0][1]; j <= location[1][1]; j++)
            board[playerId][i][j] = 'O';  // Set the ship's mark.
};


void getAreaAroundShip(const unsigned ship[][2], unsigned area[][2])
{
    for (size_t i = 0; i < 2; i++)
    {
        area[0][i] = (ship[0][i] != 0) ? ship[0][i] - 1 : ship[0][i];
        area[1][i] = (ship[1][i] != 9) ? ship[1][i] + 1 : ship[1][i];
    }
};
bool isShipsIntersect(const char board[][10][10], const char mark, const unsigned location[][2], const unsigned playerId)
{
    for (size_t i = location[0][0]; i <= location[1][0]; i++)
        for (size_t j = location[0][1]; j <= location[1][1]; j++)
            if (board[playerId][i][j] == 'O')  // Equal to the ship's mark.
                return true;

    return false;
}
bool isShipsTouch(const char board[][10][10], const unsigned location[][2], const unsigned playerId)
{
    unsigned area[2][2];  // Coordinates of the area around the ship.
    getAreaAroundShip(location, area);
    return isShipsIntersect(board, 'O', area, playerId);
};

unsigned typeDeck (unsigned i)
{
	if (i == 9)
		return 4;
	if (i >=  7)
		return 3;
	if (i >= 4)
		return 2;
	if (i < 4)
		return 1;
	return 0;
}

void EnterLocationShips(char board[2][10][10], unsigned locationOfShips[2][10][2][2], unsigned playerId)   //Функция ввода кораблей
{     
	for (unsigned i = 0; i < 10; i++ )
	{

		unsigned cord[4]{};
		unsigned location[2][2]{};
		cout << endl << "Enter Ships!! Plaer-" << playerId+1 << endl;
		getPositiveNumericArrayOfUserInput("Enter START - END the coordinates of the ship " + std::to_string(typeDeck(i)) + "-deck from 0 to 9: ", cord, 4, 0, 9);
		location[0][0] = cord[0];
		location[0][1] = cord[1];
		location[1][0] = cord[2];
		location[1][1] = cord[3];
		// Sort the coordinates so that the ship's coordinates start at the top left corner and end at the bottom right corner.
        if (location[0][0] > location[1][0]) std::swap(location[0][0], location[1][0]);
        if (location[0][1] > location[1][1]) std::swap(location[0][1], location[1][1]);


		if(ValidLocationShip(location, i)) {
			if(i <= 3){
				if(getTypeShip(location) != 1)
				{
					--i;
	 				cout << "Error: The number of decks is incorrect!" << endl
	 				<< endl;
	 				continue;
				}
			}
			if(i >= 4 && i <= 6){
				if(getTypeShip(location) != 2)
				{
					--i;
	 				cout << "Error: The number of decks is incorrect!" << endl
	 				<< endl;
	 				continue;
				}
			}
			if(i >= 7 && i <= 8){
				if(getTypeShip(location) != 3)
				{
					--i;
	 				cout << "Error: The number of decks is incorrect!" << endl
	 				<< endl;
	 				continue;
				}
			}
			if(i == 9){
				if(getTypeShip(location) != 4)
				{
					--i;
	 				cout << "Error: The number of decks is incorrect!" << endl
	 				<< endl;
	 				continue;
				}
			}
			if(isShipsTouch(board, location, playerId)){
				--i;
	 			cout << "Error: The ship is crossing or in an area!" << endl
	 			<< endl;
	 			continue;
			}

			locationOfShips[playerId][i][0][0] = cord[0];
			locationOfShips[playerId][i][0][1] = cord[1];
			locationOfShips[playerId][i][1][0] = cord[0];
			locationOfShips[playerId][i][1][1] = cord[1];
			placeShipOnBoard(board,location, playerId);
			clearConsole();
			cout << endl << "\t\t\t  SEA BATTLE!!!" << endl << endl;
			DisplayingBoardScreen(board, playerId);
		}
		else {
	 		--i;
	 		cout << "Error: Diagonal input is prohibited!" << endl
	 			<< endl;
	 		continue;	
		}
	}
}

void initNumberOfShips (unsigned numberOfShips[2][4])
{
	unsigned num = 5;
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t y = 0; y < 4; y++)
		{
			numberOfShips[i][y] = num - y -1;
		}
	}
}

/////////////////////////////////////////////////// Стрельба

int takeShot(char board[][10][10], const unsigned playerId, unsigned shot[])
{
    cout << "Enter shot coordinates (y x):\n\n";
    getPositiveNumericArrayOfUserInput("Target: ", shot, 2, 0, 9);

    char shotResult = board[playerId][shot[0]][shot[1]];

    if (shotResult == 'O')  // Hit.
    {
        board[playerId][shot[0]][shot[1]] = 'X';  // Set the hit mark.
        return 1;
    }

    if (shotResult == '~')  // Miss.
    {
        board[playerId][shot[0]][shot[1]] = '.';  // Set the miss mark.
        return 0;
    }

    return -1;  // This square has already been shot.
};

unsigned getShipId(const unsigned locationOfShips[][10][2][2], const unsigned x, const unsigned y, const unsigned playerId)
{
    unsigned id;  // Index of the locationOfShips in which the coordinates (x, y) match one of the ships.
    for (id = 0; id < 10; id++)
        if ((x <= locationOfShips[playerId][id][1][0]) && (x >= locationOfShips[playerId][id][0][0]) &&
            (y <= locationOfShips[playerId][id][1][1]) && (y >= locationOfShips[playerId][id][0][1]))
            break;

    return id;
};

bool isShipSunk(const char board[][10][10], const unsigned locationOfShips[][10][2][2], const unsigned shipId, const unsigned playerId)
{
    unsigned x1 = locationOfShips[playerId][shipId][0][0];
    unsigned y1 = locationOfShips[playerId][shipId][0][1];
    unsigned x2 = locationOfShips[playerId][shipId][1][0];
    unsigned y2 = locationOfShips[playerId][shipId][1][1];

    for (size_t i = x1; i <= x2; i++)
        for (size_t j = y1; j <= y2; j++)
            if (board[playerId][i][j] != board[playerId][x2][y2])
                return false;

    return true;
};

unsigned getNumberOfShips(const unsigned numberOfShips[][4], const unsigned playerId)
{
    return numberOfShips[playerId][0] + numberOfShips[playerId][1] + numberOfShips[playerId][2] + numberOfShips[playerId][3]; // deck1 + deck2 + deck3 + deck4
};

bool hasWinner(const unsigned numberOfShips[][4])
{
    return (getNumberOfShips(numberOfShips, 0) == 0) || (getNumberOfShips(numberOfShips, 1) == 0);
};

void printGameEnd(const unsigned winner)
{
	cout << "\n\t\t\t\t      GAME OVER"
		 << "\n\t\t\t\t  Player " + std::to_string(winner) + " wins!\n"
		 << "\t\t\t    You destroyed the enemy fleet!\n\n"
		 << "\t\t\t   Press enter to exit the game ...";
};

int main()
{
	unsigned playerId = 0;
	char board[2][10][10];
	unsigned locationOfShips[2][10][2][2]{};	
	unsigned numberOfShips[2][4]{};

	std::string player;

	InitBoardStart(0,board);
	InitBoardStart(1,board);
	initNumberOfShips(numberOfShips);

	for (size_t i = 0; i < 2; i++)
	{
		cout << endl << "\t\t\t  SEA BATTLE!!!" << endl << endl;
		playerId = i;
		cout << endl << "Player---" << playerId << endl;
		DisplayingBoardScreen(board, playerId );
		EnterLocationShips(board, locationOfShips, playerId);
		clearConsole();
	}
	playerId = 0;
	// The core gameplay loop.
	while (!hasWinner(numberOfShips))
	{
		//playerId = (playerId == 1) ? 0 : 1;
		cout << endl << "\t\t\t  SEA BATTLE!!!" << endl << endl;
		DisplayingBoardScreen(board, playerId );
		cout << endl
			 << "Shooting Player-" << playerId + 1 << endl;
		std::string msg;
        unsigned   shot[2];
        int   shotResult = takeShot(board, ((playerId == 0) ? 1 : 0), shot);

		if (shotResult == 1)  // Hit
        {
            unsigned shipId = getShipId(locationOfShips, shot[0], shot[1], ((playerId == 0) ? 1 : 0));

            if (isShipSunk(board, locationOfShips, shipId, ((playerId == 0) ? 1 : 0)))
            {
                unsigned type = getTypeShip(locationOfShips[((playerId == 0) ? 1 : 0)][shipId]) - 1;  // Find out what kind of ship sank (one-deck, double-deck, etc.).
                numberOfShips[((playerId == 0) ? 1 : 0)][type]--;                                 // Reducing the number of ships by one.
                msg = "You have sunk the! Your turn again.";
            }
            else
                msg = "You hit the ship! You may shoot again.";
        }
        else if (shotResult == 0)  // Miss
            msg = "You missed!";
        else
            msg = "You've already shot at that square!";


		DisplayingBoardScreen(board, playerId);
        cout <<  msg;

        if (shotResult == 0)
        {
            playerId = ((playerId == 0) ? 1 : 0);  // Set the next player's turn.
			cout << endl << "Shooting Player-" << playerId << endl;
			DisplayingBoardScreen(board, playerId);
        }
    }
	printGameEnd(playerId);

	preventConsoleClosing();
	return 0;
}