#pragma once
#include "Piece.h"
class StoredMove
{
public:
	StoredMove();
	~StoredMove();
	StoredMove * getNext();
	void setValues(int, int, int, int);
	void setPieces(Piece * captured, Piece * moved);
	void setNext(StoredMove *);

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
	StoredMove * nextMove;
};

