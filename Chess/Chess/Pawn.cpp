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

bool Pawn::Move(/*gameBoard, x, y, newX, newY*/)
{
	
	return true;
}

