#include<iostream>
#include<exception>
using namespace std;

template<typename T>
class Array
{public:
	 Array();											//Primary Const
	 Array(int length, int start_index = 0);			//Seeded array Const
	 Array(const Array& copy);							//Copy Const
	~Array();
	 Array&	operator= (const Array& rhs);				//merge two arrays.
	 T&		operator[](int index);						//Return value from array
	 int GetStartIndex();								//access start index
	void SetStartIndex(int start_index);				//Sets start index
	 int GetLength();									//access length
	void SetLength(int length);							//Sets the length
private:
	T	*m_array;
	int  m_length/*length of array*/, m_start_index/*Offset of subscript operator*/;
};

class Exception: public exception										//This is all I needed.
{	virtual const char* what() const throw()							//I didn't know what to do
		{ return "Error Out of Bounds.\n"; }							//with all that other junk.
	/*Exception();
	Exception(char* msg);
	Exception(const Exception& copy);
   ~Exception();
	Exception&	operator =(const Exception& rhs);
	const char* getMessage();
	void		setMessage(char* msg);
	ostream& operator <<(ostream& stream);
private:
	char* m_msg;*/
} oOb;


template<typename T>
Array<T>::Array()//Primary Const
{	m_array = new T [2];												//make dynamic
	m_start_index = 0;													//set start index
	m_length = 2;														//set length
	m_array[0]=32;														//a space
	m_array[1]=NULL;													//break line
}

template<typename T>
Array<T>::Array(int length, int start_index = 0)//Seeded array Const
	: m_length(length), m_start_index(start_index)						//initialize
		{ m_array = new T [m_length]; }									//make dynamic

template<typename T>
Array<T>::Array(const Array& copy)//Copy Const
{	m_length = copy.m_length;											//copy length
	m_start_index = copy.m_start_index;									//copy start index
	m_array = new T [m_length];											//make dynamic
	memcpy(m_array, copy.m_array, m_length);							//copy array
}

template<typename T>
Array<T>::~Array()	{ delptr(m_array); }

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
	{ m_array = rhs.m_array;	return *this; }							//create merge operator.

template<typename T>
T& Array<T>::operator[]		(int index)
	{ return m_array[index - m_start_index]; }							//Return value from array

template<typename T>
 void Array<T>::SetStartIndex	(int start_index)//Sets start index
{	if (-32<start_index && start_index<32) m_start_index = start_index;	//Check and set
	else throw oOb;		}

template<typename T>
void Array<T>::SetLength		(int length		)//Sets the length
{	if (0<length && length<100)											//Checks bounds
	{	if (length < m_length) for(int i=0; i<length; i++)m_array[m_length-i] = 0;//clean up.
		m_length = length;
	}else throw oOb;
}
template<typename T>
 int Array<T>::GetStartIndex(){ return m_start_index; }					//access start index
template<typename T>
 int Array<T>::GetLength	(){ return m_length		; }					//access length


 /*Exception::Exception(){}

Exception::Exception(char* msg) : m_msg(msg){}

Exception::Exception(const Exception& copy)/////////////////
{	m_msg = new char [strlen(copy.m_msg)+1];
	strcpy_s(m_msg, strlen(copy.m_msg)+1, copy.m_msg);
}

Exception::~Exception()	{delete [] m_msg;}

Exception& Exception::operator =(const Exception& rhs){m_msg = rhs.m_msg;	return *this;}//{	rhs->m_msg = m_msg;	}

ostream& Exception::operator <<(ostream& stream)
	{ for(int n(0); n < sizeof(*m_msg)/sizeof(char); n++) stream<< m_msg[n] << ' ';  return stream; }

#ifdef FALSE
ostream& operator<<(ostream& os, const Date& dt)
{   os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;										}
#endif

const char* Exception::getMessage(		){return m_msg;}
void		Exception::setMessage(char* msg){m_msg=msg;}*/


 void delptr(void * ptr)//attempt  at surpressing heap corruption
{	if (ptr != 0 )
	{	delete [] ptr;
		ptr = 0;
	}
}

void Display()//Display menu
{	cout<< endl
		<< "0:Display\t1:Array();\t2:Array(len, ind);\t3:Array(copy)\n"
		<< "0:Set tre\t1:Index\t\t2:Length\t\t3:Set element.\nElse: Quit."
		<< endl;
}

void Display2(Array<char> &one, Array<char> &two, Array<char> &tre)//Out-put arrays
{	int i;																	//for for-loops 
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
	Array<char> one;														//Test primary Const.
	Array<char>	two(1);														//Test Seeded Const
	Array<char> tre(one);													//Test Copy Const
	Array<char>* aray;
	Exception uno, dos;
	while(true)
	{	Display();															//Displays menu
		cin >> eger;									//For what ever reason cin.get() wasn't working for me.
		switch (eger){														//Choose which array to use or...
			case 0: Display2(one, two, tre);  continue;						//Displays data
			case 1:	aray = &one; break;										
			case 2:	aray = &two; break;
			case 3: aray = &tre; break;
			default: return 0;
		}
		cin >> eger;
		switch (eger){														//Choose what operation to do or...
		case 0: tre = *aray; break;											//Test = operator
		case 1:
			cout<< "Set start index: ";
			cin >> eger;
			aray->SetStartIndex( eger );
			break;
		case 2:
			cout<< "Set length: ";
			cin >> eger;
			aray->SetLength( eger );
			break;
		case 3://Set an element
			cout<< "[_]=_: ";
			cin >> eger >> acter;											//Input
			if(eger >= aray->GetStartIndex() && eger < aray->GetStartIndex()+aray->GetLength())//Bounderies
				(*aray)[eger] = acter;										//Set
			else throw oOb;
			break;
		default: return 0;
		}
	}system("pause");
	return 0;
 }catch(exception& e)
   { cout<< e.what();
     system("pause"); }
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