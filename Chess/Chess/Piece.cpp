#include "Piece.h"

Piece::Piece()
{
}

Piece::~Piece()
{
}

std::string Piece::getPieceName()
{
	return name;
}

bool Piece::isWhite()
{
	if (player == white)
	{
		return true;
	}
	else
	{
		return false;
	}
}
