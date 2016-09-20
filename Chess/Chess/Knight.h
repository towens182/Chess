#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight();
	~Knight();

	void Move();
	bool canMove();
	std::string getPieceName();
};

