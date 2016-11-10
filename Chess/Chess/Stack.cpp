#include "Stack.h"



Stack::Stack()
{
	listhead = nullptr;
}


Stack::~Stack()
{
}

void Stack::push(StoredMove * storedMove)
{
	storedMove->setNext(listhead);			//point to the previous first, could be NULL
	listhead = storedMove;
}

bool Stack::pop()
{
	if (listhead == nullptr)
	{
		return false;
	}
	StoredMove * first = listhead;
	listhead = first->getNext();
	delete first;
	return true;
}

bool Stack::isEmpty()
{
	if (listhead == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int Stack::getOldRow()
{
	return listhead->getOldRow();
}

int Stack::getOldCol()
{
	return listhead->getOldCol();
}

int Stack::getNewRow()
{
	return listhead->getNewRow();
}

int Stack::getNewCol()
{
	return listhead->getNewCol();
}

Piece * Stack::getCaptured()
{
	return listhead->getCaptured();
}

Piece * Stack::getMoved()
{
	return listhead->getMoved();
}
