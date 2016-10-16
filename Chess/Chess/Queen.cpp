#include "Queen.h"



Queen::Queen()
{
}

Queen::Queen(char color)
{
	if (color == 'W')
	{
		this->player = WHITE;
		this->name = "WQ";
	}
	else
	{
		this->player = BLACK;
		this->name = "BQ";
	}
}


Queen::~Queen()
{
}

bool Queen::Move()
{
	return true;
}