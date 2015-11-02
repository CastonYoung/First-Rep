//#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

/************************************************************************
* Class: cLL ("Linked List")
*
* Constructors:
*	cCell::cCell()	Default Constructor
*	Asks for the inputs that it failed to get as parameters,
*	and creates a new array of airport codes for the city,
*	at which point the city data is complete, no other
*	functions need to be called
*
*
*	cCell::cCell(sub cell)	(Used) Constructor
*	this is the constructor the program actually uses,
*	it takes a sub and produces the list or airports from the string array,
*	at which point all city data has been created,
*	and no other functions need to be called
*
* Mutators:
*	cLL<T>& operator=(const cLL<T>& rhs)	Performs a deep copy.
*
* Methods:
*	void cCell::Add_Airport(string cOd)	Adds an airport,
*	takes the code as a parameter, returns nothing.
*
*	bool cCell::Delete_Airport(string cOd)	Deletes an airport,
*	takes the code as a parameter, returns nothing.
*
*	void cCell::Display()
*	Displays one city's airports in a set width display.
*	Takes and returns nothing.
*
*************************************************************************/

	/*Default Constructor
	Asks for the inputs that it failed to get as parameters,
	and creates a new array of airport codes for the city,
	at which point the city data is complete, no other
	functions need to be called*/
	cCell::cCell()
	{	cout<< "Enter City(Name ST number code1 code2 ...)\n";
		cin >> cell_ID.name >> cell_ID.state >> cell_ID.N_ports;
		airport = new string[/*N_ports*/ 10];
		for(int N=0; N < cell_ID.N_ports; N++) cin >> airport[N];//Ask for airport codes
	}

	/*(Used) Constructor
	this is the constructor the program actually uses,
	it takes a sub and produces the list or airports from the string array,
	at which point all city data has been created,
	and no other functions need to be called*/
	cCell::cCell(sub cell) : cell_ID(cell)
	{	airport = new string[/*N_ports*/ 10];
		for(int N=0; N < cell_ID.N_ports; N++) cin >> airport[N];//Ask for airport codes
	}

	/*Adds	  an airport, takes the code as a parameter, returns nothing.*/
	void cCell::Add_Airport(string cOd)
	{	airport[++cell_ID.N_ports-1] = cOd;	}

	/*Deletes an airport, takes the code as a parameter, returns nothing.*/
	bool cCell::Delete_Airport(string cOd)//Deletes an airport.
	{	int N;
		for(N=0; N < cell_ID.N_ports; N++)	if (cOd==airport[N]) break;	//	If the bad airport is found stop this loop 
		if(N < cell_ID.N_ports){										//	,and
			while(++N < cell_ID.N_ports) airport[N-1] = airport[N];		//	Start this loop, which shifts the data.
			--cell_ID.N_ports;
		} else return true;							//Return an error flag if cOd was not found.
		return false;
	}

	/*Displays one city's airports in a set width display.
	Takes and returns nothing.*/
	void cCell::Display(){
		cout<< setw(12) << cell_ID.name << setw(3) << cell_ID.state << setw(3) << cell_ID.N_ports << ": ";
		for(int N=0; N < cell_ID.N_ports; N++) cout<< airport[N] << ' ';
		cout << endl;
	}