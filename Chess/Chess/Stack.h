#pragma once
#include "StoredMove.h"
class Stack
{
public:
	Stack();
	~Stack();

	void push(StoredMove);
	bool pop(StoredMove);
	bool isEmpty();
private:
	Stack * listhead;
};

