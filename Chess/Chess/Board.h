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
private:
	enum Turn { WHITE, BLACK };
	Board::Turn turn;

};


