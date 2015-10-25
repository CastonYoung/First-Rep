#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define CELL_ID
#define DISPLAY_METHOD

#define MSIZE 15 //Max size of auto display.

struct sub
{	string name;
	string state;
	int N_ports;	};
bool operator==(sub d1, sub d2)		{ return (d1.name == d2.name); }
bool operator==(sub d1, string s2)	{ return (d1.name == s2)	 ; }

class Cell
{public:
	Cell();
	Cell(sub cell);

	sub GetID()			{ return cell_ID; }
	string* Get_port()	{ return airport; }
	int Get_data()		{ return m_data;  }

	void Add_Airport	(string cOd);
	bool Delete_Airport (string cOd);
	void Display();

	/*~Cell()
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