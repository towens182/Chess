#pragma once
#include "Piece.h"
class StoredMove
{
public:
	StoredMove();
	~StoredMove();
	bool remFirst();
	
	StoredMove * getNext();
	void addMoves(int, int, int, int);
	

	int getValue();
	void setValues(int, int, int, int);

private:
	
	Piece * pieceMoved;
	Piece * capturedPiece;

	StoredMove * nextStoredMove;
	StoredMove * prevStoredMove;
	
	int oldRow;
	int oldCol;
	int newRow;
	int newCol;
protected:
	StoredMove * listhead;
};

