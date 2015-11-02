#include<iostream>
#include<exception>
#include"Exceptions.h"
#include"Array_Template.h"
using namespace std;


/*
	Purpose	: Displays a list of menu options.
	Enter	: three (all) arrays
	Exit	: Displays a list of menu options.
*/
void Disp_menu()
{	cout<< endl
		<< "0:Display\t1:Array();\t2:Array(len, ind);\t3:Array(copy)\n"
		<< "0:Set tre\t1:Index\t\t2:Length\t\t3:Set element.\nElse: Quit."
		<< endl;
}

/*
	Purpose	: Out puts all the arrays.
	Enter	: three (all) arrays
	Exit	: all three array contents are displayed on screen.
*/
void Out_put(Array<char> &one, Array<char> &two, Array<char> &tre)//Out-put arrays
{	int i;
	cout<< "one: "<< one.GetStartIndex() <<' ';
	for(i=0; i<one.GetLength(); ++i) cout<<' '<< one[i+one.GetStartIndex()];//Out put 1st array
	cout<< endl;
	cout<< "two: "<< two.GetStartIndex() <<' ';
	for(i=0; i<two.GetLength(); ++i) cout<<' '<< two[i+two.GetStartIndex()];//Out put 2nd array
	cout<< endl;
	cout<< "tre: "<< tre.GetStartIndex() <<' ';
	for(i=0; i<tre.GetLength(); ++i) cout<<' '<< tre[i+tre.GetStartIndex()];//Out put 3rd array
	cout<< endl;
}


int main(){try{
	int eger;
	char acter; 
	Array<char> one;									//Test primary Const.
	Array<char>	two(1);									//Test Seeded Const
	Array<char> tre(one);								//Test Copy Const
	Array<char>* aray;
	Exception uno;
	Exception dos(uno);
	uno=dos;
	while(true)
	{	Disp_menu();									//Displays menu
		cin >> eger;
		switch (eger){									//Choose which array to use or...
			case 0: Out_put(one, two, tre);  continue;	//Display data
			case 1:	aray = &one; break;
			case 2:	aray = &two; break;
			case 3: aray = &tre; break;
			default: return 0;							//EXIT
		}
		cin >> eger;
		switch (eger){									//Choose what operation to do or...
		case 0: tre = *aray; break;						//Test = operator
		case 1:											//Set start index
			cout<< "Set start index: ";
			cin >> eger;
			aray->SetStartIndex( eger );
			break;
		case 2:											//Set length
			cout<< "Set length: ";
			cin >> eger;
			aray->SetLength( eger );
			break;
		case 3:											//Set an element
			cout<< "[_]=_: ";
			cin >> eger >> acter;
			(*aray)[eger] = acter;
			break;
		default: return 0;								//EXIT
		}
	}system("pause");									//\Should not execute
	return 0;											///but pauses and quits if it does
 }catch(Exception* exe)									//Catch
   { cout<< *exe; }										//out put exception
}

/*1:	What are the considerations you had to include in your operator= function
	I origninally had my variables on the wrong side of the =,
	but realizing the object that I was trying to assign was protected by a const, I figured things might need to be flipped around.

//2:	What is the similarity and difference between copy constructor and operator= functions
	the copy constructor can be used to make a seperate array with all the same data,
	where as the assignment overload, points them to the same array, it essentially is one array with two accesses.
	Also my assignment overload doesn't copy the start_index or the length.
	They are similar in that when it comes to looking at the data, they are functionally congruent,
	it is only when you change the data that you realize you don't have a spare copy.

//3:	What steps did you take to ensure no memory leaks
	I forget.  Well I did create a destructor that should deallocate my arrays, but that's standard procedure.
	After reading this I also set everything that didn't fit in an array length change to 0;
	however, that won't actually do anything with allocation, it just ensures that if a memory leak does occur in that area,
	nothing but zeros will be leaked.  Prehaps memory leaks are what keeps causing heap corruption at exit.

//4:	In terms of big O how long would it take to find an element of this array?
		How could this be improved? What would the expression become?
	The number of times my program repeats is entirely user dependent, and since I have a "while(true)"
	it could be said that it is O(infinity); however, my output of my arrays is defined by m_length,
	so taking that into consideration my program should be either O(i) or O(m_length) AKA O(n).
*/