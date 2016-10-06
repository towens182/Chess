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
	std::string name;

	virtual bool Move() =0;
	//virtual std::string getPieceName() =0;
	std::string getPieceName() { return "BP";};

	
};


