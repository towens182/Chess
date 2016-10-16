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


bool Rook::Move()
{
	return true;
}
