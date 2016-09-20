#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn();
	~Pawn();

	void move();
	bool canMove();
	std::string getPieceName();
};

