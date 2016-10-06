#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	Bishop(char color);
	~Bishop();

	
	bool Move();
	std::string getPieceName();
};

