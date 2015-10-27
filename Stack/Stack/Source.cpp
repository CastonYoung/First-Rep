#include "stdafx.h"
#include <string>
#include <iomanip>//For setting width
using namespace std;
/*	Stack.snl
	Create and edit, a stack of integers,
	(for the purpose of testing the stack code).
	For CST 211, Joshua Kimball
	Completed 10/27/15	Last modified 10/27/2015
	by Caston DT. Young
	v1.0

	In put: By user during execution. (Integers only, example provided at the bottom)
	Output: returns 0, saves nothing.
*/

		void Clear_Screen();/*Geer, M. T. Nov 27, 2011*/

inline  void Dump(cStack<int/*, string*/>& pl_stack)//Displays the whole stack on screen
	{ while(pl_stack.Size() != 0) cout<< pl_stack.Pull() <<endl; }


int main()
{	int mn_opt(5);
	int s_item;
	cStack<int/*, string*/> the_stack;//Linked List construct

	while (true){
	try{
		cout<<"1:	Push"	<< endl
			<<"2:	Pop"	<< endl
			<<"3:	Peek"	<< endl
			<<"4:	Size"	<< endl
			<<"5:	Dump"	<< endl
			<<"X:	Quit."	<< endl;

		switch(mn_opt){
			case 1:
				cout<< "Enter: ";
				cin >> s_item;
				the_stack.Push( s_item );
				break;

			case 2:	cout<< the_stack.Pull() <<endl;	break;
			case 3: cout<< the_stack.Peek() <<endl;	break;
			case 4: cout<< the_stack.Size() <<endl;	break;
			case 5:	Dump(the_stack);				break;
			default: return 0;			//Exit loop (End program).
		}
		cin >> mn_opt;
		Clear_Screen();
	}catch(Exception exe){ cout<< exe <<endl; } }
	return 0;
}

/* Inputs
1 45
1 -100
1 44
1 578
3
1 456
1 922
4
5
2
3
6

*/