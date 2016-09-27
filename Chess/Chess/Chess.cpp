// Chess.cpp 
//Tyler Owens
//September 20, 2016

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	using namespace std;

	startMenu();
	




    return 0;
}

void startMenu()
{
	using namespace std;

	char command;

	cout << "User Commands:" << endl << endl
		<< "S - Start Game" << endl
		<< "M - Move Piece" << endl
		<< "E - End Game" << endl << endl
		<< "USER: ";
	try
	{
		cin >> command;
		
		if (command == 'S' || command == 's')
		{
			return;
		}
		else
		{
			throw string("Not a valid input!");
		}
	}
	catch (string message)
	{
		cout << endl << message << endl;
		startMenu();
	}
}

void createObjects()
{

	Board * board = new Board();



}
void drawBoard()
{

}