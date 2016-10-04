#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
	//Debug
	std::cout << "CREATED BOARD";

	/*for (int y = 0; y < 8; y++)
	{
	pieces[0][y] = new Pawn();
	}
	*/

}

Board::~Board()
{
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

