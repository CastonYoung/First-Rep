#include <iostream>
#include <string>
#include <math.h>
//#include "Linked List.h"
using namespace std;

#define CELL_ID

struct sub
{	string name;
	string state;
	int N_ports;	};
bool operator==(sub d1, sub d2)		{ if(d1.name == d2.name)return true; }
bool operator==(sub d1, string s2)	{ if(d1.name == s2)		return true; }

class Cell
{public:
	sub cell_ID;//Pound define this.
	string* airport;
	int m_data;

	Cell()
	{	cout<< "Enter City(Name ST number code1 code2 ...)\n";
		cin >> cell_ID.name >> cell_ID.state >> cell_ID.N_ports;
		airport = new string[/*N_ports*/ 10];
		for(int N=0; N < cell_ID.N_ports; N++) cin >> airport[N];//Ask for airport codes
	}
	Cell(sub cell) : cell_ID(cell)
	{	airport = new string[/*N_ports*/ 10];
		for(int N=0; N < cell_ID.N_ports; N++) cin >> airport[N];//Ask for airport codes
	}

	void Add_Airport(string cOd)//Adds an airport
	{	airport[++cell_ID.N_ports-1] = cOd;
		/*new_code = new string[N_ports+1];
		for(int N=0; N < N_ports; N++) new_code[N] = airport[N];
		new_code[++N_ports-1] = cOd;
		airport = new_code;
		//delete [] new_code;//Will this erase the data?*/
	}

	bool Delete_Airport(string cOd)//Deletes an airport.
	{	/*int N;
		new_code = new string[N_ports-1];
		for(N=0; N < N_ports; N++)	{ if(cOd!=airport[N]) new_code[N] = airport[N]; else break; }
		if(N < N_ports){
			while(++N < N_ports) new_code[N-1] = airport[N];
			--N_ports;
			airport = new_code;
			//delete [] new_code;//<Will this erase the data?
		} else { return true;	/*delete [] new_code;*/ //}//<J
		int N;
		for(N=0; N < cell_ID.N_ports; N++)	if (cOd==airport[N]) break;	//	If the bad airport is found stop this loop 
		if(N < cell_ID.N_ports){											//	,and
			while(++N < cell_ID.N_ports) airport[N-1] = airport[N];		//	Start this loop, which shifts the data.
			--cell_ID.N_ports;//					<-Negate # of airports
		} else return true;//						<-Return an error bit if cOd was not found.
		return false;
	}

	//void display();

	~Cell(){ delete [] airport;}
};