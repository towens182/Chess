#pragma once
class Board
{
public:

	Board *Piece[8][8];
	enum Turn { white, black };
	Board::Turn turn;

	Board();
	~Board();
	
};

Board::Board()
{
	this->turn = white;
}

Board::~Board()
{
}

