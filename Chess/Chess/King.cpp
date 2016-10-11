#include "King.h"



King::King()
{
}

King::King(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WK";
	}
	else
	{
		this->player = black;
		this->name = "BK";
	}
}


King::~King()
{
}

bool King::Move()
{
	return false;
}
