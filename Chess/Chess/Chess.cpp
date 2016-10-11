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

void Menu(GameStatus& gameStatus, Board *gameBoard);
void drawBoard(Board *gameBoard);
void createPieces(Board *gameBoard);
void Move(Board *gameBoard);


int main()
{
	using namespace std;

	Board * gameBoard = new Board();

	cout << "\t\t*****WELCOME TO CHESS*****" << endl << endl;
	Menu(gameStatus, gameBoard);
	do {
		drawBoard(gameBoard);
		Move(gameBoard);
		
	} while (gameStatus != END);


	delete gameBoard;
	

    return 0;
}

void Menu(GameStatus& gameStatus, Board *gameBoard)
{
	using namespace std;

	char command;
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
				createPieces(gameBoard);
				gameStatus = INPROGRESS;
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
				cout << "\t\t*****PLEASE START THE GAME FIRST*****" << endl << endl;

				Menu(gameStatus, gameBoard);
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
			Menu(gameStatus, gameBoard);
		}
}
void drawBoard(Board *gameBoard)
{
	using namespace std;
	system("CLS");
	cout << "\t\t*****"
		<< gameBoard->getTurn()
		<< "'S TURN*****"
		<< endl 
		<< endl;
	
	for (int x = 7; x >= 0; x--)
	{
		cout << x << "| ";
		for (int y = 0; y < 8; y++)
		{
			if (gameBoard->pieces[x][y] == NULL)
			{
				cout << "  ";
			}
			else
			{
				cout << gameBoard->pieces[x][y]->getPieceName()
					 << "  ";
			}
		}
		cout << endl
			 << endl;
	}
	cout << " ";
	for(int y = 0; y < 8; y++)
	{
		cout << "| " << y << " ";
	}
	cout << endl;
}

void createPieces(Board *gameBoard)
{
	//Initialize all array locations to NULL
	for(int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			gameBoard->pieces[x][y] = NULL;
		}

	//Create White Pieces
	gameBoard->pieces[0][0] = new Rook('W');
	gameBoard->pieces[0][1] = new Knight('W');
	gameBoard->pieces[0][2] = new Bishop('W');
	gameBoard->pieces[0][3] = new Queen('W');
	gameBoard->pieces[0][4] = new King('W');
	gameBoard->pieces[0][5] = new Bishop('W');
	gameBoard->pieces[0][6] = new Knight('W');
	gameBoard->pieces[0][7] = new Rook('W');
	
	//Create White Pawns
	for (int y = 0; y < 8; y++)
	{
		gameBoard->pieces[1][y] = new Pawn('W');
	}

	//Create Black Pieces
	gameBoard->pieces[7][0] = new Rook('B');
	gameBoard->pieces[7][1] = new Knight('B');
	gameBoard->pieces[7][2] = new Bishop('B');
	gameBoard->pieces[7][3] = new Queen('B');
	gameBoard->pieces[7][4] = new King('B');
	gameBoard->pieces[7][5] = new Bishop('B');
	gameBoard->pieces[7][6] = new Knight('B');
	gameBoard->pieces[7][7] = new Rook('B');
	
	//Create Black Pawns
	for (int y = 0; y < 8; y++)
	{
		gameBoard->pieces[6][y] = new Pawn('B');
	}
}

void Move(Board * gameBoard)
{
	using namespace std;
	char command;
	cout << endl
		 << "M - Move Piece"
		 << endl
		 << "E - End Game"
		 << endl
		 << gameBoard->getTurn()
		 << ": ";
	cin >> command;
	if (command == 'M' || command == 'm')
	{
		
	}
	else if (command == 'E' || command == 'e')
	{
		gameStatus = END;
	}
}
