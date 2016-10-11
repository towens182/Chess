#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn();
	Pawn(char color);
	~Pawn();

	bool Move();
	//std::string getPieceName();
};

