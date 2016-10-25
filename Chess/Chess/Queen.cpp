#include "Queen.h"



Queen::Queen()
{
}

Queen::Queen(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WQ";
	}
	else
	{
		this->player = BLACK;
		this->name = "BQ";
	}
}


Queen::~Queen()
{
}
//Check if the desired move is possible for Queen
bool Queen::Move()
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
	std::cout << " QUEEN MOVED"
		      << std::endl;
	return true;
}