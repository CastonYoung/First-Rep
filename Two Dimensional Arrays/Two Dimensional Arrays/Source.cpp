/*		  Two Dimensional Arrays
 *		Caston Young	10/11/2015
 *				  CST 211
 *		Files: Array_Template.h
 *				Exceptions.h
 *				Source.cpp
 *				Board.cpp
 *		Input: None.	Output: None.
 */

/*Source.cpp contains main function, and Fill, both of  which
  are designed to test the code from the other files*/

#include<iostream>
#include"Array_Template.h"
using namespace std;

extern void Display_Board(cArray<char> &DB_2D);

//Fills a 2D character array with a given character
inline void Fill(cArray<char>& F_2D, char c)
{	int i, j;
	FOR(F_2D.getRow(), F_2D.getCol();){
		if ( i == 3 && j == 0){	//<V Stops for break point.
			 int insert_break_point;
		}F_2D[i][j] = c;		//Problematic assignment of F_D2[F_D2+1][0]
	}
}

//Test Classes
int main()
{try{
	int M_row = WIDTH, M_col = HEIGH;
	int i, j;//Index numbers
	cArray<char> M_2D(M_row, M_col);

	//cin >> M_row >> M_col;
	Fill(M_2D, '#');
	Display_Board(M_2D);
	cArray<char> M_2D2(M_2D);

	//cout<< "Re-enter:";
	//cin >> M_row >> M_col;
	M_row = 5;			M_col = 5;
	M_2D.setRow(M_row);	M_2D.setCol(M_col);
	Fill(M_2D, '$');

	Display_Board(M_2D2);
	cout<< endl;
	Display_Board(M_2D);

	system("pause");
	return 0;
}catch(Exception* exe){cout<< exe;}}