#include "Board.h"
#include <fstream>
Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
}
void Board::move(std::string piece, int oldRow, int oldCol, int newRow, int newCol, Stack& stack)
{
	using namespace std;

		if ((pieces[oldRow][oldCol] == nullptr) || (this->turn != pieces[oldRow][oldCol]->player))
		{
			throw string("***** INCORRECT LOCATION CHOSEN, TRY AGAIN ******");
		}

		if ((piece != pieces[oldRow][oldCol]->getPieceName()) || (this->turn != pieces[oldRow][oldCol]->player))
		{
			throw string("***** INCORRECT PIECE CHOSEN, TRY AGAIN ******");
		}
		//Make sure locations are valid numbers between 0-7
		if ((oldRow < 8) && (oldCol < 8) && (newRow >= 0) && (newCol >= 0))
		{
			if ((pieces[newRow][newCol] != nullptr) && (pieces[oldRow][oldCol]->player == pieces[newRow][newCol]->player))
			{
				throw string("***** INCORRECT DESINATION CHOSEN, TRY AGAIN ******");
			}
		}
		else
		{
			throw string("***** ROW AND COL MUST BE BETWEEN 0 - 7 *****");
		}

		//Check if the selected piece can do the move (It's own unique move)
		if (pieces[oldRow][oldCol]->Move())
		{
			StoredMove * SM = new StoredMove();
			SM->setPieces(pieces[newRow][newCol], pieces[oldRow][oldCol]);
			SM->setValues(oldRow, oldCol, newRow, newCol);
			stack.push(SM);

			//pieces[newRow][newCol] = NULL;
			pieces[newRow][newCol] = pieces[oldRow][oldCol];
			pieces[oldRow][oldCol] = nullptr;
			
			newTurn();
		}
	}
void Board::WriteGame()
{
	using namespace std;
	
	ofstream saveGame;
	saveGame.open("C:/chessfolder/chessgame.txt");

	if (saveGame.fail())
	{
		throw string("\t\t***** FILE OPENING FAILED *****");
	}
	saveGame << turn << endl;

	for(int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (pieces[i][j] != nullptr)
			{
				saveGame << pieces[i][j]->getPieceName()
					<< " " << i << "," << j << endl;
			}
		}
	saveGame << 'X';
	saveGame.close();

}
void Board::setTurn(int whoseTurn)
{
	if (whoseTurn == 0)
	{
		this->turn = WHITE;
	}
	else if (whoseTurn == 1)
	{
		this->turn = BLACK;
	}
}
//Returns who has the current turn
std::string Board::getTurn()
{
	if (this->turn == WHITE)
	{
		return "WHITE";
	}
	else if (this->turn == BLACK)
	{
		return "BLACK";
	}
}
//When a successful move has been made newTurn switches to the opposing player
void Board::newTurn()
{
	if (this->turn == WHITE)
	{
		this->turn = BLACK;
	}
	else
	{
		this->turn = WHITE;
	}
}

bool Board::Undo(Stack& stack)
{
	if (!stack.isEmpty())
	{
		pieces[stack.getOldRow()][stack.getOldCol()] = stack.getMoved();
		pieces[stack.getNewRow()][stack.getNewCol()] = stack.getCaptured();
		stack.pop();
		return true;
	}
	else
	{
		return false;
	}
}
