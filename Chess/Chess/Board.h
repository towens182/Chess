#pragma once
#include <string>
#include <iostream>
#include "Piece.h"
#include "StoredMove.h"
#include "Stack.h"

class Board
{
public:
	Piece * pieces[8][8];
	std::string getTurn();
	enum Turn { WHITE, BLACK };
	Board::Turn turn;
	void newTurn();

	bool Undo(Stack * stack);

	Board();
	~Board();
	void Move(std::string piece, int oldX, int oldY, int newX, int newY, Stack& stack);
	bool Undo(Stack& stack);
	void WriteGame();
	void setTurn(int);
};


