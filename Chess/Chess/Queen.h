#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen();
	Queen(char color);
	~Queen();


	bool Move();
	std::string getPieceName();
};

