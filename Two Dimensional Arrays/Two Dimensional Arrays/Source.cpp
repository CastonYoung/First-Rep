/****************************************************************
* Author:				Caston Young
* Date Created:			10/11/15
* Last Mod. Date:		10/30/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Two Dimensional Arrays.snl
*
* Overview: This program tests the dynamic 2D_Array code (within it),
*			so that it may be used in future programs.
*
*    Input: None, except for the keypress to close it.
*
*   Output: Three dynamic 2D arrays produced by the cArray, and cRow
*			classes.
*
* ||
* ||
* cRow size:0
* Col size:0
* ||
* ||
* ||
* ||
* ||
* ||
* ||
* cRow size:5
* Col size:0
* |_______________|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |&&&&&&&&&&&&&&&|
* |_______________|
* cRow size:15
* Col size:15
*
* |_____|
* |$$$$$|
* |$$$$$|
* |$$$$$|
* |$$$$$|
* |$$$$$|
* |_____|
* cRow size:5
* Col size:5
* Press any key to continue . . . 
*****************************************************************/


#include<iostream>
#include"Array_Template.h"
using namespace std;
/*Source.cpp contains main function, and Fill, both of  which
  are designed to test the code from the other files*/

extern void Display_Board(cArray<char> &DB_2D);

//Fills a 2D character array with a given character
inline void Fill(cArray<char>& F_2D, char c)
{	int i, j;
	LOOP(F_2D.getRow(), F_2D.getCol())  F_2D[i][j] = c;		
}

//Test Classes
int main()
{
	try{
		int M_row = SMALL, M_col = SMALL;//Initiate
		int i, j;						//Index numbers
		cArray<char> M_2D0, M_2D(M_row);//Test default and secondary constructor

		Display_Board(M_2D0);			//Test Array made by default

		Fill(M_2D, '#');				//<Test Array made by one parameter
		Display_Board(M_2D);			//<J (NOTE: these will output borders only.)

		M_row = LARGE;		M_2D.setRow(M_row);	//Test width  assignment to a higher value
		M_col = LARGE;		M_2D.setCol(M_col);	//Test height assignment to a higher value
		Fill(M_2D, '&');				//Retest the array after reassignment.

		cArray<char> M_2D2(M_2D);		//Test copy constructor

		M_row = SMALL;		M_2D.setRow(M_row);	//Test width  assignment to a lower value
		M_col = SMALL;		M_2D.setCol(M_col);	//Test height assignment to a lower value
		Fill(M_2D, '$');				//Retest the array after reassignment.

		Display_Board(M_2D2);			//<--------Prove success/failure of above tests.--------7
		cout<< endl;					//<Add vertical white (actually black) space, to prompt.|
		Display_Board(M_2D);			//<-----------------------------------------------------J

		system("pause");				//With hold ending the program until you see the output.
		return 0;						//End program.                             Y
	}catch(Exception* exe){ cout<< exe; system("pause"); }//Output exceptions, and J
}