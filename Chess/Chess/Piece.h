#pragma once
#include <string>
class Piece
{
public:

	//Identifies which player a piece belongs to
	enum player { white, black };

	Piece() {};
	~Piece() {};
	
	virtual bool Move() =0;
	virtual std::string getPieceName() =0;
	void setLocation(int x, int y);

private:
	std::string name;
	int row, col;
};


