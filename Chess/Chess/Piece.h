#pragma once
#include <string>
class Piece
{
public:

	//Identifies which player a piece belongs to
	enum player { white, black };

	Piece() {};
	~Piece() {};
	
	virtual void Move() {};
	virtual std::string getPieceName() { return "Piece";};

private:
	std::string name;
};


