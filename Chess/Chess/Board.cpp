#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
	delete[] *pieces;
}
void Board::move(std::string piece, int oldX, int oldY, int newX, int newY)
{
	if (validPiece(piece, oldX, oldY) && validDestination(oldX, oldY, newX, newY))
	{
		delete pieces[newY][newX];
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
//Makes sure the piece chosen belongs to the right player
//and in the chosen destination
bool Board::validPiece(std::string piece, int oldX, int oldY)
{
	if ((piece == pieces[oldY][oldX]->getPieceName()) && (turn == pieces[oldY][oldX]->player))
	{
		return true;
	}
	else
	{
		
		return false;
	}
}
//Makes sure the new desination is a valid square on the board
//and is either empty or opposite piece
bool Board::validDestination(int oldX, int oldY, int newX, int newY)
{
	if ((oldX < 8) && (oldY < 8) && (newX >= 0) && (newY >= 0))
	{
		if ((pieces[newY][newX] == NULL) || (pieces[oldY][oldX]->player != pieces[newY][newX]->player))
		{
			return true;
		}
		else
		{
			std::cout << "Not a valid desitination";
			return false;
		}
	}
	else
	{
		std::cout << "Not a valid destination";
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

