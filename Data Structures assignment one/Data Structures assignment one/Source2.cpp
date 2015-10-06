#include<iostream>
#include<exception>
using namespace std;

enum Err { OoB, CNI };
inline	void Flush(){ cin.ignore(cin.rdbuf()->in_avail()); }
//template<typename T>
class Array
{public:
	 Array();
	 Array(int length, int start_index);
	 Array(const Array& copy);
	~Array();
	 Array&operator=(const Array& rhs);
	 char& operator[](int index);//T& operator[](int index);
	 int GetStartIndex();
	void SetStartIndex(int start_index);
	 int GetLength();
	void SetLength(int length);
private:
	char*m_array;//T* m_array;
	int  m_length, m_start_index;
};

class Exception: public exception
{	virtual const char* what() const throw()
		{ return "Error Out of Bounds.\n"; }
	
	/*Exception();
	Exception(char* msg);
	Exception(const Exception& copy);
   ~Exception();
	Exception&	operator =(const Exception& rhs);
	const char* getMessage();
	void		setMessage(char* msg);
	ostream& operator <<(ostream& stream);*/
private:
	char* m_msg;
} oOb;


Array::Array()
{	m_array = new char [2];
	m_start_index = 0;
	m_length = 2;
	m_array[0]=' ';
	m_array[1]=NULL;
}

Array::Array(int length, int start_index = 0)
	: m_length(length), m_start_index(start_index)
	{	m_array = new char [m_length];	}

Array::Array(const Array& copy)
{	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	m_array = new char [m_length];
	strcpy_s(m_array, m_length, copy.m_array);
}

Array::~Array()	{delete [] m_array;}

Array& Array::operator=(const Array& rhs)
{	m_array = rhs.m_array;	return *this;	}

char& Array::operator[]	(int index)
{	return m_array[index - m_start_index];	}

 void Array::SetStartIndex	(int start_index)
{	if (-32<start_index && start_index<32) m_start_index = start_index;
	else throw OoB;		}

void Array::SetLength		(int length		)
{	if (0<length && length<100) m_length = length;
	else throw OoB;		}

 int Array::GetStartIndex(){return m_start_index;}
 int Array::GetLength	 (){return m_length;}


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


void Display()
{	cout<< endl
		<< "0:Display\t1:Array();\t2:Array(len, ind);\t3:Array(copy)\n"
		<< "\t\t1:Index\t\t2:Length\t\t3:Set element."
		<< endl;
}
void Display2(Array &one, Array &two, Array &tre)
{	int i;
	cout<< "one: "<< one.GetStartIndex() <<' ';
	for(i=0; i<one.GetLength(); ++i) cout<<' '<< one[i+one.GetStartIndex()];
	cout<< endl;
	cout<< "two: "<< two.GetStartIndex() <<' ';
	for(i=0; i<two.GetLength(); ++i) cout<<' '<< two[i+two.GetStartIndex()];
	cout<< endl;
	cout<< "tre: "<< tre.GetStartIndex() <<' ';
	for(i=0; i<tre.GetLength(); ++i) cout<<' '<< tre[i+tre.GetStartIndex()];
	cout<< endl;
}


int main(){try{
	int eger;
	char acter;
	Array one, two(5);
	Array tre(one);
	Array* aray;
	Exception uno, dos;
	while(true)
	{	Display();
		cin >> eger;//For what ever reason cin.get() wasn't working for me.
		switch (eger){
			case 0: Display2(one, two, tre);  continue;
			case 1:	aray = &one; break;
			case 2:	aray = &two; break;
			case 3: aray = &tre; break;
			default: return 0;
		}
		cin >> eger;
		switch (eger){
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
		case 3:
			cout<< "[_]=_: ";
			cin >> eger >> acter;
			(*aray)[eger] = acter;
			break;
		default: return 0;
		}
	}system("pause");
	return 0;
}catch(Err x)
	{	 if(x==OoB) cout<< "Error Out of Bounds.\n";
	else if(x==CNI) cout<< "Error Copy Constructor not initiated.\n";
	system("pause");
	return 0;
	}
}
/*
#include<iostream>
using namespace std;

enum Err { OoB, CNI };
inline	void Flush(){ cin.ignore(cin.rdbuf()->in_avail()); }
//template<typename T>
class Array
{public:
	 Array();
	 Array(int length, int start_index);
	 Array(const Array& copy);
	~Array();
	 Array&operator=(const Array& rhs);
	 char& operator[](int index);//T& operator[](int index);
	 int GetStartIndex();
	void SetStartIndex(int start_index);
	 int GetLength();
	void SetLength(int length);
private:
	char*m_array;//T* m_array;
	int  m_length, m_start_index;
};

class Exception
{public:
	Exception();
	Exception(char* msg);
	Exception(const Exception& copy);
   ~Exception();
	Exception&	operator =(const Exception& rhs);
	const char* getMessage();
	void		setMessage(char* msg);
	ostream& operator <<(ostream& stream);
private:
	char* m_msg;
};


Array::Array()
{	m_array = new char [1];
	m_start_index = 0;
	m_length = 0;
}

Array::Array(int length, int start_index = 0)
	: m_length(length), m_start_index(start_index)
	{	m_array = new char [m_length];	}

Array::Array(const Array& copy)
{	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	m_array = new char [m_length];
	strcpy_s(m_array, m_length, copy.m_array);
}

Array::~Array()	{delete [] m_array;}

Array& Array::operator=(const Array& rhs)
{	m_array = rhs.m_array;	return *this;	}//{	rhs.m_array = m_array;	return *this;	}


char& Array::operator[]	(int index)
{	return m_array[index - m_start_index];	}

 void Array::SetStartIndex	(int start_index)
{	if (-32<start_index && start_index<32) m_start_index = start_index;
	else throw OoB;		}

void Array::SetLength		(int length		)
{	if (0<length && length<100) m_length = length;
	else throw OoB;		}

 int Array::GetStartIndex(){return m_start_index;}
 int Array::GetLength	 (){return m_length;}



Exception::Exception(){}

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
void		Exception::setMessage(char* msg){m_msg=msg;}


void Display()
{	cout<< endl
		<< "0:Display\t1:Array();\t2:Array(len, ind);\t3:Array(copy)\n"
		<< "0:Set copy\t1:Index\t\t2:Length\t\t3:Set element."
		<< endl;
}
void Display2(Array one, Array two, Array tre, bool if_copy)
{	int i;
	cout<< "one: "<< one.GetStartIndex() <<' ';
	for(i=0; i<one.GetLength(); ++i) cout<<' '<< one[i+one.GetStartIndex()];
	cout<< endl;

	cout<< "two: "<< two.GetStartIndex() <<' ';
	for(i=0; i<two.GetLength(); ++i) cout<<' '<< two[i+two.GetStartIndex()];
	cout<< endl;
if(if_copy){
	cout<< "tre: "<< tre.GetStartIndex() <<' ';
	for(i=0; i<tre.GetLength(); ++i) cout<<' '<< tre[i+tre.GetStartIndex()];
	cout<< endl;
}}


int main(){try{
	bool if_copy(0);
	int eger;
	char acter;
	Array one, two(5), tre;//tre will temporarily be declared for Display2
	Array* aray;
	Exception uno, dos;
	while(true)
	{	Display();
		cin >> eger;//For what ever reason cin.get() wasn't working for me.
		switch (eger){
			case 0: Display2(one, two, tre, if_copy);  continue;
			case 1:	aray = &one; break;
			case 2:	aray = &two; break;
			case 3:
				if(if_copy) aray = &tre;
				else throw CNI;
				break;
			default: return 0;
		}
		cin >> eger;
		switch (eger){
		case 0:
			if_copy = true;
			tre.~Array();
			if(eger==0)Array tre(*aray);//if statement needed for some reason.//This is probably a bad coding practice, but since the whole point of the program is to test the class...
			continue;
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
		case 3:
			cout<< "[_]=_: ";
			cin >> eger >> acter;
			(*aray)[eger] = acter;
			break;
		default: return 0;
		}
	}system("pause");
	return 0;
}catch(Err x)
{	 if(x==OoB) cout<< "Error Out of Bounds.\n";
else if(x==CNI) cout<< "Error Copy Constructor not initiated.\n";
system("pause");
return 0;
}}
*/