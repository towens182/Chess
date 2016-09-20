#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	~Bishop();

	void Move();
	std::string getPieceName();
};

