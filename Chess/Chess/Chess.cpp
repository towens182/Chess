// Chess.cpp 
//Tyler Owens
//September 20, 2016

#include "stdafx.h"
#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <iostream>
#include <string>
#include <iomanip>

enum GameStatus { NONE, INPROGRESS, END };
GameStatus gameStatus = NONE;

void Menu(GameStatus& gameStatus);
void drawBoard();


int main()
{
	using namespace std;

	//for debugging purposes
	int x;
	

	cout << "\t\t*****WELCOME TO CHESS*****" << endl << endl;

	do {

		Menu(gameStatus);

		if (gameStatus == NONE)
		{
			cout << "GAME START";
			Board * board = new Board();
			gameStatus = INPROGRESS;
		}
		//For debugging purposes
		cin >> x;
	} while (gameStatus != END);




	delete board;

    return 0;
}

void Menu(GameStatus& gameStatus)
{
	using namespace std;

	char command;

	if (gameStatus == NONE)
	{
		cout
		     << "S - Start Game" << endl
			 << "M - Move Piece" << endl
			 << "E - End Game" << endl << endl
			 << "USER: ";
		try
		{
			cin >> command;

			if (command == 'S' || command == 's')
			{
				system("CLS");
				cout << "\t\t*****STARTING NEW GAME OF CHESS*****"
					 << endl
					 << "\t\t\t***WHITE BEGINS***"
					 << endl;
				
			}
			//If user tries to enter a command before starting a game
			//tell them and retry menu
			else if (command == 'E' || command == 'e' || command == 'M' || command == 'm')
			{
				system("CLS");
				cout << "\t\t*****PLEASE START THE GAME FIRST*****"
					 << endl
					 << endl;

				Menu(gameStatus);
			}
			else
			{
				throw string("\t\t*****NOT A VALID INPUT!!*****");
			}
		}
		catch (string message)
		{
			system("CLS");
			cout << message 
				 << endl 
				 << endl;
			Menu(gameStatus);
		}
	}
	else
	{
		cout << "M - Move Piece"
			<< endl
			<< "E - End Game"
			<< endl;
			//Function for move
	}
}
void drawBoard()
{
	//std::cout << board->getTurn(); //OBJECTS NOT BEING CREATED GLOBALLY??
}