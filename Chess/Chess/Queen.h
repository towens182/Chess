#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen();
	~Queen();

	void Move();
	std::string getPieceName();
};

