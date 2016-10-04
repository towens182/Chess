#pragma once
#include <string>
class Piece
{
public:

	//Identifies which player a piece belongs to
	

	Piece();
	~Piece();
	
	virtual bool Move() =0;
	virtual std::string getPieceName() =0;


private:
	enum player { white, black };
	player player;
	std::string name;
	int row, col;
	

};


