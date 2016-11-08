#pragma once
#include "Piece.h"
class StoredMove
{
public:
	StoredMove();
	~StoredMove();
	
	void setValues(int, int, int, int);

	int getOldRow();
	int getOldCol();
	int getNewRow();
	int getNewCol();
	Piece * getCaptured();
	Piece * getMoved();


private:
	int oldRow;
	int oldCol;
	int newRow;
	int newCol;
	Piece * pieceCaptured;
	Piece * pieceMoved;

};

