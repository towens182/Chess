#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King();
	~King();

	bool Move();
	std::string getPieceName();
};

