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
#include "StoredMove.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <exception>


enum GameStatus { NONE, INPROGRESS, END };
enum Winner {NOBODY, WHITE, BLACK};
void Menu(GameStatus& gameStatus, Board *gameBoard);
void DrawBoard(GameStatus& gameStatus, Board *gameBoard);
void CreatePieces(Board *gameBoard);
void LoadGame(Board *gameBoard);
void Move(GameStatus& gameStatus, Board *gameBoard);
void Cleanup(Board *gameBoard, Winner gameWinner);
bool GetInput(int& oldRow, int& oldCol, int& newRow, int& newCol);
Stack stack;

int main()
{
	using namespace std;

	GameStatus gameStatus = NONE;
	Winner gameWinner = NOBODY;
	Board * gameBoard = new Board();
	

	cout << "\t\t***** WELCOME TO CHESS *****" << endl << endl;
	Menu(gameStatus, gameBoard);
	do {
		DrawBoard(gameStatus, gameBoard);
		Move(gameStatus, gameBoard);
		
	} while (gameStatus != END);
		
	Cleanup(gameBoard, gameWinner);
	return 0;
}

void Menu(GameStatus& gameStatus, Board *gameBoard)
{
	using namespace std;

	char command;
	cout << "S - Start Game" << endl
		 << "M - Move Piece" << endl
		 << "U - Undo Move" << endl
		 << "E - End Game" << endl << endl
		 << "USER: ";
		try
		{
			cin >> command;

			if (command == 'S' || command == 's')
			{
				char ans;
				gameStatus = INPROGRESS;
					system("CLS");
					cout << "\t\t***** WELCOME TO CHESS *****" << endl << endl
						 << "Would you like to load a saved game"
						 << endl
						 << "from C:/chessfolder/chessgame.txt? (Y/N) ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y')
					{
							LoadGame(gameBoard);
							system("CLS");
							cout << "\t\t***** CHESS GAME LOADED *****"
								 << endl;
					}
					else if (ans == 'n' || ans == 'N')
					{
						CreatePieces(gameBoard);
						system("CLS");
						cout << "\t\t***** NEW CHESS GAME STARTED *****"
							 << endl;
					}
					else
					{
						throw string("\t\t***** NOT A VALID INPUT!! *****");
					}
				
			}
			//If user tries to enter a command before starting a game
			//tell them and retry menu
			else if (command == 'E' || command == 'e' || command == 'M' || command == 'm' || command == 'U' || command == 'u')
			{
				throw string("\t\t***** PLEASE START THE GAME FIRST *****");
			}
			//Reject anything else that isn't a valid command
			else
			{
				throw string("\t\t***** NOT A VALID INPUT!! *****");
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
void DrawBoard(GameStatus& gameStatus, Board *gameBoard)
{
	using namespace std;

	char *StatusTypes[] =
	{
		"NONE",
		"IN PROGRESS",
		"END"
	};
	//Display turn and game status for user
	cout << "\t  Turn: "
		 << gameBoard->getTurn()
		 << "\tGame Status: "
		 << StatusTypes[gameStatus]
		 << endl
		 << endl;
	cout << "\t  -----------------------------------------"
		 <<endl;
	for (int x = 7; x >= 0; x--)
	{
		cout << "\t" << x << " | ";
		for (int y = 0; y < 8; y++)
		{
			//Just print spaces for square if there is no piece occupying it
			if (gameBoard->pieces[x][y] == nullptr)
			{
				cout << "   | ";
			}
			else
			{
				cout << gameBoard->pieces[x][y]->getPieceName()
					 << " | ";
			}
		}
		cout << endl
			 << "\t  -----------------------------------------" 
			 << endl;
	}
	cout << "\t ";
	for(int y = 0; y < 8; y++)
	{
		cout << "    " << y;
	}
	cout << "  "
		 << endl;
}

void CreatePieces(Board *gameBoard)
{
	//Initialize all array locations to NULL
	for(int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			gameBoard->pieces[x][y] = nullptr;
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
void LoadGame(Board * gameBoard)
{
	using namespace std;

	ifstream saveGame;
	saveGame.open("C:/chessfolder/chessgame.txt");
	if (saveGame.fail())
	{
		throw string("\t\t****** NO SAVED GAME AVAILABLE *****");
	}
	char turn;
	char color;
	char piece;
	int row;
	int col;
	char line;

	//Initialize all array locations to NULL
	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			gameBoard->pieces[x][y] = nullptr;
		}
	if (saveGame.peek() == '0' || saveGame.peek() == '1')
	{
		turn = (saveGame.get() - '0');
		saveGame.ignore();
		gameBoard->setTurn(turn);

		while (saveGame.peek() != 'X')
		{
			line = ' ';
			while (line != '\n')
			{
				color = saveGame.get();
				piece = saveGame.get();
				if (saveGame.peek() == ' ' || saveGame.peek() == ',')
				{
					saveGame.ignore();
				}
				row = (saveGame.get() - '0');
				if (saveGame.peek() == ' ' || saveGame.peek() == ',')
				{
					saveGame.ignore();
				}
				col = (saveGame.get() - '0');
				line = saveGame.get();
			}

			switch (piece)
			{
			case ('B'):
				gameBoard->pieces[row][col] = new Bishop(color);
				break;
			case ('K'):
				gameBoard->pieces[row][col] = new King(color);
				break;
			case ('N'):
				gameBoard->pieces[row][col] = new Knight(color);
				break;
			case ('P'):
				gameBoard->pieces[row][col] = new Pawn(color);
				break;
			case ('Q'):
				gameBoard->pieces[row][col] = new Queen(color);
				break;
			case ('R'):
				gameBoard->pieces[row][col] = new Rook(color);
				break;
			default:
				break;
			}
		}
	}
	else
	{
		saveGame.close();
		throw string("\t\t****** NO SAVED GAME AVAILABLE *****");
	}
	saveGame.close();
}
//Get user's input, do they want to move or end the game
void Move(GameStatus& gameStatus, Board * gameBoard)
{
	using namespace std;

	char command;
	string piece;
	int oldRow, oldCol, newRow, newCol;

	cout << "M - Move Piece"
		 << "\t\t\t           "
		 << "U - Undo Move"
	 	 << endl
		 << "W - Write C:/chessfolder/chessgame.txt"
		 << "\t   "
		 << "E - End Game"
		 << endl
		 << gameBoard->getTurn()
		 << "'S TURN: ";
	try
	{
		cin >> command;
		if (command == 'M' || command == 'm')
		{
			system("CLS");
			DrawBoard(gameStatus, gameBoard);
			
			cout << endl
				 << "Piece: ";
			cin >> piece;
			transform(piece.begin(), piece.end(), piece.begin(), ::toupper);
			
			if (GetInput(oldRow, oldCol, newRow, newCol))
			{
				system("CLS");
				gameBoard->move(piece, oldRow, oldCol, newRow, newCol, stack);
			}
		}
		else if (command == 'E' || command == 'e')
		{
			gameStatus = END;
		}
		else if (command == 'W' || command == 'w')
		{
			gameBoard->WriteGame();
			system("CLS");
			cout << "\t\t***** GAME WRITTEN TO FILE *****"
				 << endl;
		}
		else if (command == 'U' || command == 'u')
		{
			
			if (gameBoard->Undo(stack))
			{
				system("CLS");
				cout << "UNDO SUCCESSFUL"
					 << endl;
			}
			else 
			{
				throw string("\t\t****** NO TURNS TO UNDO ******");
			}

		}
		else
		{
			throw string("\t\t***** NOT A VALID INPUT!! *****");
		}
	}
	catch (string message)
	{
		system("CLS");
		cout << message
			 << endl;
	}
}
//Delete objects and prompt the winner of the game
void Cleanup(Board * gameBoard, Winner gameWinner)
{
	using namespace std;

	char *WinnerTypes[] =
	{
		"NOBODY",
		"WHITE",
		"BLACK"
	};
	//Delete pieces on gameboard
	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			delete gameBoard->pieces[x][y];
			gameBoard->pieces[x][y] = nullptr;
		}
	//Delete contents of stack
	while (!stack.isEmpty())
	{
		stack.pop();
	}
	delete gameBoard;
	system("CLS");
	cout << "\t\t***** GAME OVER *****"
		 << endl
		 << endl
		 << endl
		 << "\t\t     "
		 << WinnerTypes[gameWinner]
		 << " WON"
		 << endl
		 << endl
		 << endl;
}
//Gets line of current locations and source destinations
bool GetInput(int& oldRow, int& oldCol, int& newRow, int& newCol)
{
	using namespace std;

	char input[15];
	cout << "Enter Currrent ROW Current COL New ROW New COL"
	 	 << endl
		 << "Example: 1030 ENTER"
		 << endl
		 << " Player: ";
	cin.ignore();
	cin.getline(input, 15);
	
	if (isdigit(input[0]))
	{
		oldRow = (input[0] - '0');
	}
	else
	{
		system("CLS");
		cout << "***** INCORRECT LOCATION - MUST BE INTEGERS 0 - 7 *****"
			 << endl;
		return false;
	}

	if (isdigit(input[1]))
	{
		oldCol = (input[1] - '0');
	}
	else
	{
		system("CLS");
		cout << "***** INCORRECT LOCATION - MUST BE INTEGERS 0 - 7 *****"
			<< endl;
		return false;
	}

	if (isdigit(input[2]))
	{
		newRow = (input[2] - '0');
	}
	else
	{
		system("CLS");
		cout << "***** INCORRECT LOCATION - MUST BE INTEGERS 0 - 7 *****"
			<< endl;
		return false;
	}

	if (isdigit(input[3]))
	{
		newCol = (input[3] - '0');
	}
	else
	{
		system("CLS");
		cout << "***** INCORRECT LOCATION - MUST BE INTEGERS 0 - 7 *****"
			<< endl;
		return false;
	}

	return true;
}
