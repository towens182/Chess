#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
}
void Board::move(std::string piece, int oldRow, int oldCol, int newRow, int newCol)
{
	if (validDestination(oldRow, oldCol, newRow, newCol) && validPiece(piece, oldRow, oldCol))
	{
		//Check if the selected piece can do the move (It's own unique move)
		if (pieces[oldRow][oldCol]->Move())
		{
			//Delete the opposing piece if it is in the target location
			if (pieces[newRow][newCol] != NULL)
			{
				delete pieces[newRow][newCol];
			}


			//Move into each piece in move function/////////////////
			/*std::cout << std::endl
					  << pieces[oldRow][oldCol]->getPieceName() 
					  << " MOVED"
					  << std::endl;*/
			////////////////////////////////////////
			pieces[newRow][newCol] = NULL;
			pieces[newRow][newCol] = pieces[oldRow][oldCol];
			pieces[oldRow][oldCol] = NULL;
			
			newTurn();
		}
	}
	else
	{
		return;
	}
}
//Makes sure the piece chosen belongs to the right player
//and in the chosen destination
bool Board::validPiece(std::string piece, int oldRow, int oldCol)
{
	using namespace std;

	if (piece == pieces[oldRow][oldCol]->getPieceName() && turn == pieces[oldRow][oldCol]->player)
	{
		return true;
	}
	else
	{
		system("CLS");
		cout << endl
			 << endl
			 << endl
			 << "\t***** INCORRECT PIECE CHOSEN, TRY AGAIN "
			 << getTurn()
			 << " ******"
			 << endl
			 << endl
		 	 << "Make sure you select your own piece and the correct position for it."
			 << endl;
		system("pause");
		system("CLS");
		return false;
	}
}
//Makes sure the new desination is a valid square on the board
//and is either empty or opposite piece
bool Board::validDestination(int oldRow, int oldCol, int newRow, int newCol)
{
	using namespace std;
	//Make sure locations are valid numbers between 0-7
	if ((oldRow < 8) && (oldCol < 8) && (newRow >= 0) && (newCol >= 0))
	{
		if ((pieces[newRow][newCol] == NULL) || (pieces[oldRow][oldCol]->player != pieces[newRow][newCol]->player))
		{
			return true;
		}
		else
		{
			system("CLS");
			cout << endl
				 << endl
				 << endl
				 << "\t***** INCORRECT DESINATION CHOSEN, TRY AGAIN "
				 << getTurn()
				 << " ******"
				 << endl
				 << endl
				 << "Make sure the desination is either EMPTY"
				 << endl
				 << "or contains the opposing player's piece."
				 << endl;
			system("pause");
			system("CLS");
			return false;
		}
	}
	else
	{
		system("CLS");
		cout << endl
			 << endl
			 << endl
			 << "\t***** INCORRECT DESINATION CHOSEN, TRY AGAIN "
			 << getTurn()
		 	 << " ******"
			 << endl
			 << endl
			 << "Make sure you pick valid ROW and COL postitions between 0 - 7."
			 << endl;
		system("pause");
		system("CLS");
		return false;
	}
}
//Returns who has the current turn
std::string Board::getTurn()
{
	if (this->turn == WHITE)
	{
		return "WHITE";
	}
	else if (this->turn == BLACK)
	{
		return "BLACK";
	}
	else
	{
		//For debugging purposes
		return "ERROR WHO'S TURN?";
	}
}
//When a successful move has been made newTurn switches to the opposing player
void Board::newTurn()
{
	if (this->turn == WHITE)
	{
		this->turn = BLACK;
	}
	else
	{
		this->turn = WHITE;
	}
}

