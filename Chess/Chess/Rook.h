#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook();
	~Rook();

	void Move();
	bool canMove();
	std::string getPieceName();
};

