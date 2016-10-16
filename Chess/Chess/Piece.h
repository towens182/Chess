#pragma once
#include <string>
#include <iostream>
class Piece
{
public:

	Piece();
	~Piece();

	enum Player { WHITE, BLACK };
	Player player;


	virtual bool Move() =0;
	std::string getPieceName();

protected:
	std::string name;
};


