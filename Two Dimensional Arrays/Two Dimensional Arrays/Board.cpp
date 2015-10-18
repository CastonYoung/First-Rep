#include <iostream>
#include"Array_Template.h"
using namespace std;

//Outputs a top/bottom border.
void Display_BotTop(int wide)
{	cout << WALL;
	for (int col=0; col < wide; ++col) cout << FLOR;
	cout << WALL << endl;
}

//Displays the array, called Display_Board, because it was originally made for a board game.
void Display_Board(cArray<char> &DB_2D)
{	
	Display_BotTop(DB_2D.getCol());

	for (int row=0; row < DB_2D.getRow(); row++)
	{	
		cout << WALL;
		for (int col = 0; col < DB_2D.getCol(); col++) cout << DB_2D[row][col];
		cout << WALL <<endl;
	}

	Display_BotTop(DB_2D.getCol());
	cout<< "cRow size:" << DB_2D.getRow() << endl
		<< "Col size:" << DB_2D.getCol() << endl;
}