#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
}
void Board::move(std::string piece, int oldX, int oldY, int newX, int newY)
{
	if (validPiece(piece, oldX, oldY) && validDestination(oldX, oldY, newX, newY))
	{
		if (pieces[oldY][oldX]->Move())
		{
			if (pieces[newY][newX] != NULL)
			{
				delete pieces[newY][newX];
			}
			std::cout << std::endl
					  //<< "\t"
					  << pieces[oldY][oldX]->getPieceName() 
					  << " MOVED"
					  << std::endl;
			pieces[newY][newX] = NULL;
			pieces[newY][newX] = pieces[oldY][oldX];
			pieces[oldY][oldX] = NULL;
			
			if (this->turn == WHITE)
			{
				this->turn = BLACK;
			}
			else if (this->turn == BLACK)
			{
				this->turn = WHITE;
			}
		}
	}
	else
	{
		return;
	}
}
//Makes sure the piece chosen belongs to the right player
//and in the chosen destination
bool Board::validPiece(std::string piece, int oldX, int oldY)
{
	using namespace std;

	if (piece == pieces[oldY][oldX]->getPieceName() && turn == pieces[oldY][oldX]->player)
	{
		return true;
	}
	else
	{
		system("CLS");
		cout << endl
			<< endl
			<< endl
			<< "\t***** INCORRECT PIECE CHOSEN, TRY AGAIN ******"
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
bool Board::validDestination(int oldX, int oldY, int newX, int newY)
{
	using namespace std;

	if ((oldX < 8) && (oldY < 8) && (newX >= 0) && (newY >= 0))
	{
		if ((pieces[newY][newX] == NULL) || (pieces[oldY][oldX]->player != pieces[newY][newX]->player))
		{
			return true;
		}
		else
		{
			system("CLS");
			cout << endl
				 << endl
				 << endl
				 << "\t***** INCORRECT DESINATION CHOSEN, TRY AGAIN ******"
				 << endl
				 << endl
				 << "Make sure the desination is either EMPTY or the opposing player's piece."
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
			 << "\t***** INCORRECT DESINATION CHOSEN, TRY AGAIN ******"
			 << endl
			 << endl
			 << "Make sure you pick valid x and y postitions between 0 - 7."
			 << endl;
		system("pause");
		system("CLS");
		return false;
	}
}
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

