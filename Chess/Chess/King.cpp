#include "King.h"



King::King()
{
}

King::King(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WK";
	}
	else
	{
		this->player = BLACK;
		this->name = "BK";
	}
}


King::~King()
{
}

bool King::Move()
{
	return true;
}
