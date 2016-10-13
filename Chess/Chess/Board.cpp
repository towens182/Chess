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
		pieces[newX][newY] = NULL;
		pieces[newX][newY] = pieces[oldX][oldY];
		pieces[oldX][oldY] = NULL;
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
	if ((piece == pieces[oldX][oldY]->getPieceName()) && (turn == pieces[oldX][oldY]->player))
	{
		return true;
	}
	else
	{
		std::cout << "Not a Valid Piece";
		return false;
	}
}
//Makes sure the new desination is a valid square on the board
//and is either empty or opposite piece
bool Board::validDestination(int oldX, int oldY, int newX, int newY)
{
	if ((oldX < 8) && (oldY < 8) && (newX >= 0) && (newY >= 0))
	{
		if ((pieces[newX][newY] == NULL) || (pieces[oldX][oldY]->player != pieces[newX][newY]->player))
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

