#include "Knight.h"



Knight::Knight()
{
}

Knight::Knight(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WN";
	}
	else
	{
		this->player = BLACK;
		this->name = "BN";
	}
}


Knight::~Knight()
{
}

bool Knight::Move()
{
	return true;
}