#pragma once
#include "StoredMove.h"

class Stack
{
public:
	Stack();
	~Stack();

	void push(StoredMove * storedMove);
	bool pop();
	bool isEmpty();
	
	int getOldRow();
	int getOldCol();
	int getNewRow();
	int getNewCol();
	Piece * getCaptured();
	Piece * getMoved();
private:
	StoredMove * listhead;
};

