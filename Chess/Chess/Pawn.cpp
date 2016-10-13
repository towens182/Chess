#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color)
{
	if (color == 'W')
	{
		player = white;
		name = "WP";
	}
	else
	{
		player = black;
		name = "BP";
	}
}


Pawn::~Pawn()
{
}

bool Pawn::Move(/*gameBoard, x, y, newX, newY*/)
{
	
	return true;
}

