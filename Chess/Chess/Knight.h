#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight();
	~Knight();

	bool Move();
	std::string getPieceName();
};

