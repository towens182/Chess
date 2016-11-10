#include "StoredMove.h"



StoredMove::StoredMove()
{
	pieceCaptured = nullptr;
	pieceMoved = nullptr;
	nextMove = nullptr;
}


StoredMove::~StoredMove()
{
}

StoredMove * StoredMove::getNext()
{
	return nextMove;
}

void StoredMove::setValues(int srcRow, int srcCol, int trgRow, int trgCol)
{
	oldRow = srcRow;
	oldCol = srcCol;
	newRow = trgRow;
	newCol = trgCol;
}

void StoredMove::setPieces(Piece * captured, Piece * moved)
{
	pieceCaptured = captured;
	pieceMoved = moved;
}

void StoredMove::setNext(StoredMove * dataObj)
{
	nextMove = dataObj;
}

int StoredMove::getOldRow()
{
	return oldRow;
}

int StoredMove::getOldCol()
{
	return oldCol;
}

int StoredMove::getNewRow()
{
	return newRow;
}

int StoredMove::getNewCol()
{
	return newCol;
}

Piece * StoredMove::getCaptured()
{
	return pieceCaptured;
}

Piece * StoredMove::getMoved()
{
	return pieceMoved;
}

