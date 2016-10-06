#include "Bishop.h"



Bishop::Bishop()
{
}

Bishop::Bishop(char color)
{
	if (color == 'W')
	{
		this->player = white;
		this->name = "WB";
	}
	else
	{
		this->player = black;
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

std::string Bishop::getPieceName()
{
	return this->name;
}
