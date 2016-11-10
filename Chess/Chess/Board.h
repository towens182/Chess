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

	Board();
	~Board();
	void move(std::string piece, int oldX, int oldY, int newX, int newY, Stack stack);
	bool Undo(Stack stack);
	bool validPiece(std::string piece, int oldX, int oldY);
	bool validDestination(int oldX, int oldY, int newX, int newY);
};


