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
	if (this->player == WHITE)
	{
		std::cout << "WHITE";
	}
	else
	{
		std::cout << "BLACK";
	}
		std::cout << " PAWN MOVED"
				  << std::endl;
	return true;
}

