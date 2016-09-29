#pragma once
#include <string>

class Board
{
public:

	Board * Piece[8][8];
	enum Turn { WHITE, BLACK };
	Board::Turn turn;

	std::string getTurn();

	Board();
	~Board();
	
};

inline std::string Board::getTurn()
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

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
}

