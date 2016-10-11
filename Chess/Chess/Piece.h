#pragma once
#include <string>
class Piece
{
public:

	//Identifies which player a piece belongs to
	

	Piece();
	~Piece();

	enum player { white, black };
	player player;


	virtual bool Move() =0;
	std::string getPieceName();
	//std::string getPieceName() { return "BP";};

protected:
	std::string name;
};


