#include "Stack.h"



Stack::Stack()
{
	listhead = nullptr;
}


Stack::~Stack()
{
}

void Stack::push(StoredMove)
{

}

bool Stack::pop(StoredMove)
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
