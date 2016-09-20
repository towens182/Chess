#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn();
	~Pawn();

	void move();
	std::string getPieceName();
};

