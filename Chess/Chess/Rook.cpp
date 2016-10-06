#include "Rook.h"

Rook::Rook()
{
}

Rook::Rook(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WR";
	}
	else
	{
		this->player = black;
		this->name = "BR";
	}
}


Rook::~Rook()
{
}


bool Rook::Move()
{
	return false;
}

std::string Rook::getPieceName()
{
	return this->name;
}
