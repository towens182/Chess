#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen();
	~Queen();


	bool Move();
	std::string getPieceName();
};

