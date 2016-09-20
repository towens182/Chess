#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	~Bishop();

	void Move();
	bool canMove();
	std::string getPieceName();
};

