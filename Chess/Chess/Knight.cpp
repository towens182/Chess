#include "Knight.h"



Knight::Knight()
{
}

Knight::Knight(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WN";
	}
	else
	{
		this->player = black;
		this->name = "BN";
	}
}


Knight::~Knight()
{
}

bool Knight::Move()
{
	return false;
}