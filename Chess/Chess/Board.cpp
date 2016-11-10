#include "Board.h"

Board::Board()
{
	this->turn = WHITE;
}

Board::~Board()
{
}
void Board::move(std::string piece, int oldRow, int oldCol, int newRow, int newCol, Stack& stack)
{
	if (validDestination(oldRow, oldCol, newRow, newCol) && validPiece(piece, oldRow, oldCol))
	{
		//Check if the selected piece can do the move (It's own unique move)
		if (pieces[oldRow][oldCol]->Move())
		{
			StoredMove * SM = new StoredMove();
			SM->setPieces(pieces[newRow][newCol], pieces[oldRow][oldCol]);
			SM->setValues(oldRow, oldCol, newRow, newCol);
			stack.push(SM);

			//pieces[newRow][newCol] = NULL;
			pieces[newRow][newCol] = pieces[oldRow][oldCol];
			pieces[oldRow][oldCol] = NULL;
			
			newTurn();
		}
	}
	else
	{
		return;
	}
}

//Makes sure the piece chosen belongs to the right player
//and in the chosen destination
bool Board::validPiece(std::string piece, int oldRow, int oldCol)
{
	using namespace std;
	if ((pieces[oldRow][oldCol] == NULL) || (this->turn != pieces[oldRow][oldCol]->player))
	{
		cout << "***** INCORRECT LOCATION CHOSEN ******"
			 << endl;
		return false;
	}
	else
	{
		if ((piece == pieces[oldRow][oldCol]->getPieceName()) && (this->turn == pieces[oldRow][oldCol]->player))
		{
			return true;
		}
		else
		{
			system("CLS");
			cout << "***** INCORRECT PIECE CHOSEN, TRY AGAIN "
				<< getTurn()
				<< " ******"
				<< endl;
			return false;
		}
	}
}
//Makes sure the new desination is a valid square on the board
//and is either empty or opposite piece
bool Board::validDestination(int oldRow, int oldCol, int newRow, int newCol)
{
	using namespace std;
	//Make sure locations are valid numbers between 0-7
	if ((oldRow < 8) && (oldCol < 8) && (newRow >= 0) && (newCol >= 0))
	{
		if ((pieces[newRow][newCol] == NULL) || (pieces[oldRow][oldCol]->player != pieces[newRow][newCol]->player))
		{
			return true;
		}
		else
		{
			system("CLS");
			cout << "***** INCORRECT DESINATION CHOSEN, TRY AGAIN "
				<< getTurn()
				<< " ******"
				<< endl;
			return false;
		}
	}
	else
	{
		system("CLS");
		cout << "***** ROW AND COL MUST BE BETWEEN 0 - 7 *****"
			 << endl;
		return false;
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
	else
	{
		//For debugging purposes
		return "ERROR WHO'S TURN?";
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
