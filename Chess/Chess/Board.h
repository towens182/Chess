#pragma once
#include <string>

class Board
{
public:

	Board * Piece[8][8];
	enum Turn { WHITE, BLACK };
	Board::Turn turn;

	std::string getTurn();

	Board();
	~Board();
	
};

inline std::string Board::getTurn()
{
	if (this->turn == WHITE)
	{
		return "WHITE";
	}
	else if (this->turn == BLACK)
	{
		return "BLACK";
	}
	else
	{
		//For debugging purposes
		return "ERROR WHO'S TURN?";
	}
}

Board::Board()
{
	this->turn = WHITE;
	std::cout << "CREATED OBJECTS";









	//Initialize BLACK Pawns
	for (int y = 0; y <= 7; y++)
	{
		//board->Piece[7][y] = new Pawn();
	}

	/*Piece * whitePieces[16];
	whitePieces[1] = new Pawn();
	whitePieces[2] = new Pawn();
	whitePieces[3] = new Pawn();
	whitePieces[4] = new Pawn();
	whitePieces[5] = new Pawn();
	whitePieces[6] = new Pawn();
	whitePieces[7] = new Pawn();
	whitePieces[8] = new Pawn();
	whitePieces[9] = new Rook();
	whitePieces[10] = new Knight();
	whitePieces[11] = new Bishop();
	whitePieces[12] = new Queen();
	whitePieces[13] = new King();
	whitePieces[14] = new Bishop();
	whitePieces[15] = new Knight();
	whitePieces[16] = new Rook();

	Piece * blackPieces[16];
	blackPieces[1] = new Pawn();
	blackPieces[2] = new Pawn();
	blackPieces[3] = new Pawn();
	blackPieces[4] = new Pawn();
	blackPieces[5] = new Pawn();
	blackPieces[6] = new Pawn();
	blackPieces[7] = new Pawn();
	blackPieces[8] = new Pawn();
	blackPieces[9] = new Rook();
	blackPieces[10] = new Knight();
	blackPieces[11] = new Bishop();
	blackPieces[12] = new Queen();
	blackPieces[13] = new King();
	blackPieces[14] = new Bishop();
	blackPieces[15] = new Knight();
	blackPieces[16] = new Rook();*/


}

Board::~Board()
{
}

