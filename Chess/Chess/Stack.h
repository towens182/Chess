#pragma once
#include "StoredMove.h"

class Stack
{
public:
	Stack();
	~Stack();

	void push(StoredMove * storedMove);
	bool pop(StoredMove * storedMove);
private:
	StoredMove * listhead;
};

