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

bool Stack::pop(StoredMove * storedMove)
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
