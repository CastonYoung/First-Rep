#include<iostream>
#include"Array_Template.h"
//#include"Exceptions.h"
using namespace std;

extern void Display_Board(Array<char> &twoD);

int main()
{try{
	int s_row, s_col, i, j;
	Array<char> D2(WIDTH, HEIGH);
	for(i=0; i <= WIDTH; i++)
	{	for(j=0; j <= HEIGH; j++) D2[i][j] = '#';
		D2[i][j] = '\n';						//Not needed for current display method.
	}
	Display_Board(D2);
	cout<< "Row size:" << D2.getRow() << endl
		<< "Col size:" << D2.getCol() << endl
		<< "Re-enter:";
	cin >> s_row >> s_col;
	D2.setRow(s_row);
	D2.setCol(s_col);
	Display_Board(D2);
	cout<< "Row size:" << D2.getRow() << endl
		<< "Col size:" << D2.getCol() << endl
		<< "Re-enter:";
	system("pause");
	return 0;
}catch(Exception* exe){cout<< exe;}}