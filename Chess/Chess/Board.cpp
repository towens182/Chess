#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
	delete[] *pieces;
}
void Board::move(std::string piece, int x, int y, int newX, int newY)
{
	if (this->turn == WHITE)
	{
		this->turn = BLACK;
	}
	else if (this->turn == BLACK)
	{
		this->turn = WHITE;
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

