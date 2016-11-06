#include "StoredMove.h"



StoredMove::StoredMove()
{
	listhead = NULL;
}


StoredMove::~StoredMove()
{
}



bool StoredMove::remFirst()
{
	if (listHead == NULL)
	{
		return false;
	}
	StoredMove * first = listHead;
	listHead = first->getNext();		//unlink first element in list
	delete first;
	return true;
}

StoredMove * StoredMove::getNext()
{
	return nextStoredMove;
}

void StoredMove::addMoves(int oldRow, int oldCol, int newRow, int newCol)
{
	StoredMove * newData = new StoredMove();
	newData->setValues(oldCol, oldCol, newRow, newCol);
	newData->setNext(listHead);			//point to the previous first, could be NULL
	listHead = newData;					//make this the new first element
}

void StoredMove::setValues(int oldRow2, int oldCol2, int newRow2, int newCol2)
{
	oldRow = oldRow2;
	oldCol = oldCol2;
	newRow = newRow2;
	newCol = newCol2;

}
