#include "Rook.h"

Rook::Rook()
{
}

Rook::Rook(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WR";
	}
	else
	{
		this->player = BLACK;
		this->name = "BR";
	}
}


Rook::~Rook()
{
}

//Check if the desired move is possible for Rook
bool Rook::Move()
{
	if (this->player == WHITE)
	{
		std::cout << "WHITE";
	}
	else
	{
		std::cout << "BLACK";
	}
	std::cout << " ROOK MOVED"
		      << std::endl;
	return true;
}
