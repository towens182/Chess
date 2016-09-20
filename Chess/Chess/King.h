#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King();
	~King();

	void Move();
	std::string getPieceName();
};

