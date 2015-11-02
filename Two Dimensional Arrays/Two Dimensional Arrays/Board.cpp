#include <iostream>
#include"Array_Template.h"
using namespace std;

/*********************************************************************
*   Entry:  wide, the width of the board/table.
*
*    Exit:  The top or bottom border of the board/table is displayed.
*
* Purpose:  Display the top and bottom border of the board/table.
*
*********************************************************************/

void Display_BotTop(int wide)
{	cout << WALL;
	for (int col=0; col < wide; ++col) cout << FLOR;
	cout << WALL << endl;
}

/*********************************************************************
*   Entry:  The 2D array
*
*    Exit:  The 2D array is displayed, surrounded by a border.
*			Additionally the height and width is displayed,
*			this is a program specific requirement.
*
* Purpose:  Display the 2D array contents within a border.
*
*********************************************************************/

void Display_Board(cArray<char> &DB_2D)//Called Display_Board, because it was originally made for a board game.
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