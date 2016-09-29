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

enum GameStatus { NONE, INPROGRESS, END };
GameStatus gameStatus = NONE;

void Menu(GameStatus& gameStatus);
void createObjects();
void drawBoard();


int main()
{
	using namespace std;

	

	cout << "\t\t-----WELCOME TO CHESS-----" << endl << endl;

	do {

		Menu(gameStatus);
	} while (gameStatus != END);
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
				gameStatus = INPROGRESS;
				createObjects();
				cout << string(10, '\n')
					 << "\t\t-----STARTING NEW GAME OF CHESS------"
					 << endl
					 << "\t\t-----WHITE BEGINS-----"
					 << endl;

				return;
			}
			//If user tries to enter a command before starting a game
			//tell them and retry menu
			else if (command == 'E' || command == 'e' || command == 'M' || command == 'm')
			{
				cout << string(20, '\n')
				 	 << "\t-----PLEASE START THE GAME FIRST-----!"
					 << endl;

				Menu(gameStatus);
			}
			else
			{
				throw string("Not a valid input!");
			}
		}
		catch (string message)
		{
			cout << endl << message << endl;
			Menu(gameStatus);
		}
	}
	else
	{
		cout << "M - Move Piece"
			<< endl
			<< "E - End Game"
			<< endl;
			
	}
}
void createObjects()
{

	Board * board = new Board();

	//Initialize BLACK Pawns
	for (int y = 0; y <= 7; y++)
	{
		board->Piece[7][y] = new Pawn();
	}

	/*Piece * whitePieces[16];
		whitePieces[1] = new Pawn();
		whitePieces[2] = new Pawn();
		whitePieces[3] = new Pawn();
		whitePieces[4] = new Pawn();
		whitePieces[5] = new Pawn();
		whitePieces[6] = new Pawn();
		whitePieces[7] = new Pawn();
		whitePieces[8] = new Pawn();
		whitePieces[9] = new Rook();
		whitePieces[10] = new Knight();
		whitePieces[11] = new Bishop();
		whitePieces[12] = new Queen();
		whitePieces[13] = new King();
		whitePieces[14] = new Bishop();
		whitePieces[15] = new Knight();
		whitePieces[16] = new Rook();

	Piece * blackPieces[16];
	blackPieces[1] = new Pawn();
	blackPieces[2] = new Pawn();
	blackPieces[3] = new Pawn();
	blackPieces[4] = new Pawn();
	blackPieces[5] = new Pawn();
	blackPieces[6] = new Pawn();
	blackPieces[7] = new Pawn();
	blackPieces[8] = new Pawn();
	blackPieces[9] = new Rook();
	blackPieces[10] = new Knight();
	blackPieces[11] = new Bishop();
	blackPieces[12] = new Queen();
	blackPieces[13] = new King();
	blackPieces[14] = new Bishop();
	blackPieces[15] = new Knight();
	blackPieces[16] = new Rook();*/



}
void drawBoard()
{
	std::cout << board->getTurn(); //OBJECTS NOT BEING CREATED GLOBALLY??
}