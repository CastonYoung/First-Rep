//#include <iomanip>//For setting width
#include "Header.h"
#include "Linked List.h"
#include "Exceptions.h"

using namespace std;
/*	Create and edit, a list of air-ports, organized by the city and state which they reside.
	CST 126 & 211,	Completed 10/13/15	v2:1.0												*/

inline  void Flush(){ cin.ignore(cin.rdbuf()->in_avail()); }
		void Clear_Screen();/*Geer, M. T. Nov 27, 2011*/
inline  void Cannot_find(string city){ cout<< "Cannot find \""<<city<<"\"in list.\n"; }

void Print_list(LL<Cell/*, string*/> & Cities);

int main()
{try{
	string city;
	int opt;
	bool repeat(true);
	sub input;
	Cell* coed;
	node<Cell>* noed;
	LL<Cell/*, string*/> Cities;//Linked List construct

	cout<<"Running AIRPORT MANAGER"<< endl;
	while (repeat == true){

		cout<<"1.	Append city.\n"
			<<"2.	Delete city.\n"
			<<"3.	Append airport to city.\n"
			<<"4.	Delete airport.\n"
			<<"5.	Print the full list of cities.\n"
			<<"6.	Quit."			<< endl;

		if( 0 < Cities.Get_size() && Cities.Get_size()< MSIZE ) Print_list(Cities);

		cin >> opt;
		switch(opt){
		case 1://--------------------------Adds an aditional city.
			cout<< "Enter City(Name ST number code1 code2 ...)\n";
			cin >> input.name >> input.state >> input.N_ports;
			Cities.Append( input );
			break;
		case 2://------------------------Deletes a city.
			cout<< "\nEnter the name of the city: ";
			cin >> city;
			noed = Cities.Find(city);
			if(noed!=0) Cities.Extract(noed);
			else{ Cannot_find(city); continue; }
			break;
		case 3://---------------------------------Adds an airport to an existing city.
			cout<< "\nEnter the name of the city to add an airport to: ";
			cin >> city;
			coed = Cities[city];
			if(coed==0){ Cannot_find(city); continue; }
			else {
				cout<< "\nEnter the code of the new airport: ";
				cin >> city;
				coed->Add_Airport(city);
			}break;
		case 4://---------------------------------Deletes an airport from a city.
			cout<< "\nEnter the name of the city of the airport to be deleted: ";
			cin >> city;
			coed = Cities[city];
			if(coed==0){ Cannot_find(city); continue; }
			else {
				cout<< "\nEnter the airport code: ";
				cin >> city;//Yes I realize it is called city, but I'm using it for a specific airport.
				if(coed->Delete_Airport(city)) { Cannot_find(city); continue; }//if (function fails to execute) /*see Delete_Airport*/
			}break;

		case 5:
			Print_list(Cities);
			system("pause");
			break;	//Print the list of cities.
		
		default: repeat = false;			//Exit loop (End program).

		}Clear_Screen();
	}return 0;
}catch(Exception exe){ cout<< exe <<endl; } }


void Print_list(LL<Cell/*, string*/> & Cities)
{try{	
	cout<< /*std::fixed << setiosflags(ios::left) <<*/ endl;
	cout<< /*setw(12) <<*/ "  City" << "St." /*<< setw(3)*/ << "# " << "Codes"<< endl;//Table header
	Cities.Display_all();
	cout<<endl;
}catch(Exception exe){ cout<< exe <<endl; } }


void Cell::Display(){//-----------------Displays one city's airports
	cout<< /*setw(12) <<*/ cell_ID.name /*<< setw(3)*/ << cell_ID.state /*<< setw(3)*/ << cell_ID.N_ports << ": ";
	for(int N=0; N < cell_ID.N_ports; N++) cout<< airport[N] << ' ';
	cout << endl;
}

/*					//Copy and paste input list.
1 Atlanta GA 1 ATL
1 Boston MA 1 BOS
1 Chicago IL 2 MDW ORD
1 Denver CO 2 DEN QWM
1 Fargo ND 1 FAR
1 Honolulu HI 1 HNL
1 LosAngeles CA 1 LAX
1 Medford OR 1 MFR
1 NewYork NY 2 JFK LGA
1 Orlando FL 2 ORL MCO
1 Portland OR 1 PDX
1 SanFrancisco CA 1 SFO
1 Seattle WA 1 SEA
1 Washington DC 2 IAD DCA
5

*/