#include "Bishop.h"



Bishop::Bishop()
{
}

Bishop::Bishop(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WB";
	}
	else
	{
		this->player = BLACK;
		this->name = "BB";
	}
}

Bishop::~Bishop()
{
}


bool Bishop::Move()
{
	return false;
}

