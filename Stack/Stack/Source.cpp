#include "stdafx.h"
#include <string>
#include <iomanip>//For setting width
using namespace std;

/***********************************************************
* Author:				Caston DT. Young
* Date Completed:			10/27/15
* Last Modification Date:	10/29/15
* Lab Number:			CST 211 Lab 1
* Filename:				Stack.snl
* v1.0
*
* Overview:
*	Create and edit, a stack of integers,
*	(for the purpose of testing the stack code).
*
* Input:
*	By user during execution. Integers only
*	Example:
*	1 45
*	1 -100
*	1 44
*	1 578
*	3
*	1 456
*	1 922
*	4
*	5
*	2
*	3
*	6
*
* Output:
*	The output of this program will be a menu of options.
*	At which point either a prompt to enter a new number, 
*	a number from the stack, the dump of the whole stack,
*	or an error message	will be output depending on the
*	option chosen.  Example shown below.
*	1:	Push
*	2:	Pop
*	3:	Peek
*	4:	Size
*	5:	Dump
*	X:	Quit.
*	Enter: 
************************************************************/

		//No input conditions, clears the inside of the console window at exit (might move mouse as a side effect)
		void Clear_Screen();/*Geer, M. T. Nov 27, 2011*/

inline  void Dump(cStack<int/*, string*/>& pl_stack)//Displays the whole stack on screen
	{ while(pl_stack.Size() != 0) cout<< pl_stack.Pull() <<endl; }


int main()
{	int mn_opt(5);	//Menu option
	int s_item;		//Stack Item, a variable that stores data once or to be on the stack
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
			default: return 0;			//End program.
		}
		cin >> mn_opt;
		Clear_Screen();
	}catch(Exception exe){ cout<< exe <<endl; }
	}
	return 0;
}