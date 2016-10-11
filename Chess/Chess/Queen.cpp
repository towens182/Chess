#include "Queen.h"



Queen::Queen()
{
}

Queen::Queen(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WQ";
	}
	else
	{
		this->player = black;
		this->name = "BQ";
	}
}


Queen::~Queen()
{
}

bool Queen::Move()
{
	return false;
}