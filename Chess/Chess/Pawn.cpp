#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color)
{
	if (color == 'W')
	{
		player = WHITE;
		name = "WP";
	}
	else
	{
		player = BLACK;
		name = "BP";
	}
}


Pawn::~Pawn()
{
}
//Check if the desired move is possible for Pawn
bool Pawn::Move()
{
	return true;
}

