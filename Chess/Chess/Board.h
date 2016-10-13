#pragma once
#include <string>
#include <iostream>
#include "Piece.h"

class Board
{
public:
	Piece * pieces[8][8];
	std::string getTurn();
	void newTurn();

	Board();
	~Board();
	void move(std::string piece, int x, int y, int newX, int newY);

private:
	enum Turn { WHITE, BLACK };
	Board::Turn turn;

};


