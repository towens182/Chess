#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WP";
	}
	else
	{
		this->player = black;
		this->name = "BP";
	}
}


Pawn::~Pawn()
{
}


bool Pawn::Move()
{
	return false;
}

std::string Pawn::getPieceName()
{
	return this->name;
}
