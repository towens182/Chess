#include "Knight.h"



Knight::Knight()
{
}

Knight::Knight(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WN";
	}
	else
	{
		this->player = BLACK;
		this->name = "BN";
	}
}


Knight::~Knight()
{
}
//Check if the desired move is possible for Knight
bool Knight::Move()
{
	std::cout << std::endl;
	if (this->player == WHITE)
	{
		std::cout << "WHITE";
	}
	else
	{
		std::cout << "BLACK";
	}
	std::cout << " KNIGHT MOVED"
		      << std::endl;
	return true;
}