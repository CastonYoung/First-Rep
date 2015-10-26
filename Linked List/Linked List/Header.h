#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define CELL_ID
#define DISPLAY_METHOD

#define MSIZE 15 //Max size of auto display.

struct sub		//Used to package multiple parameters into one.
{	string name;
	string state;
	int N_ports;	};
//bool operator==(sub &d1, sub &d2)		{ return (d1.name == d2.name); }	Will not link here where it should
//bool operator==(sub &d1, string &s2)	{ return (d1.name == s2)	 ; }	Will not link here where it should



/*The data contained within the linked list.
  In this case a list of Airports			*/
class cCell
{public://class functions, are self explanatory
	cCell();
	cCell(sub cell);

	sub GetID()			{ return cell_ID; }
	string* Get_port()	{ return airport; }
	int Get_data()		{ return m_data;  }

	void Add_Airport	(string cOd);
	bool Delete_Airport (string cOd);
	void Display();

	/*~cCell()
	{	if (airport)  {
			delete [] airport;
			airport = 0;
	} /*deceptive*/ //}
	//But looks nice
private:
	sub cell_ID;//Pound define this.
	string* airport;
	int m_data;
};

#endif