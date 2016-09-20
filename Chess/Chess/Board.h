#pragma once

class Board
{
public:

	Board *Piece[8][8];
	enum turn { white, black };

	Board();
	~Board();

};

Board::Board()
{

}

Board::~Board()
{
}
