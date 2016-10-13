#pragma once
#include <string>
class Piece
{
public:

	Piece();
	~Piece();

	enum player { white, black };
	player player;


	virtual bool Move() =0;
	std::string getPieceName();
	bool isWhite();

protected:
	std::string name;
};


