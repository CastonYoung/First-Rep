#include<iostream>
#include"Array_Template.h"
using namespace std;

extern void Display_Board(Array<char> &DB_2D);

inline void Fill(Array<char>& F_2D, char c)
{	int i, j;
	FOR(F_2D.getRow())
		for(j=0; j < F_2D.getCol(); j++){
			if ( i == 3 && j == 0)
				{ void* break_point; }
			F_2D[i][j] = c;			//Code breaks upon assignment of F_D2[3][0]
			if (j==0) cout<< endl;
			cout<< F_2D[i][j];
		}
}	//D2[i][j] = '\n';				//Not needed for current display method.

int main()
{try{
	int M_row = WIDTH, M_col = HEIGH;
	int i, j;//Index numbers
	Array<char> M_2D(M_row, M_col);

	//cin >> M_row >> M_col;
	Fill(M_2D, '#');
	Display_Board(M_2D);
	Array<char> M_2D2(M_2D);

	//cout<< "Re-enter:";
	//cin >> M_row >> M_col;
	M_row = 5;	M_col = 3;
	M_2D.setRow(M_row);		M_2D.setCol(M_col);
	Fill(M_2D, '$');

	Display_Board(M_2D2);
	cout<< endl;
	Display_Board(M_2D);

	system("pause");
	return 0;
}catch(Exception* exe){cout<< exe;}}