#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook();
	Rook(char color);
	~Rook();

	bool Move();
	std::string getPieceName();
};

