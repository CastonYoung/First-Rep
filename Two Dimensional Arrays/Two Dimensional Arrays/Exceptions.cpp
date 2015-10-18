#include<iostream>
#include"Exceptions.h"
using namespace std;

/*ostream operator overload,
  overloads the << operator to output msg, by passing in the Exception itself
Enter	: an Exception, presumably one that has just been caught.
Return	: stream (basically Nothing)
AlsoExit: The msg is outputed.*/
ostream& operator<<(ostream& stream, Exception& except){//Out put message.
	const char *msg = except.getMessage();
	int message_length = sizeof( *msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) stream<< msg << ' ';  return stream;
}

#ifdef FALSE
ostream& Exception::operator<<(ostream& stream, Exception& except)
	{ for(int n(0); n < sizeof(*m_msg)/sizeof(char); n++) stream<< m_msg[n] << ' ';  return stream; }

ostream& Exception::operator<<(const Exception& except){//Out put message.
	int message_length = sizeof( m_msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) cout<< m_msg << ' ';  return ;
}
#endif

/*Because I apparently need to have a default constructor
Enter	: Nothing
Return	: Nothing*/
Exception::Exception(){ m_msg = "Error, Undefined exception thrown."; }

/*Creats an exception by message being passed.
Enter	: string/character array
Return	: Nothing*/
Exception::Exception(char* msg) : m_msg(msg){}

/*A copy constructor (does a deep copy)
Enter	: an Exception
Return	: Nothing*/
Exception::Exception(const Exception& copy)
{	m_msg = new char [strlen(copy.m_msg)+1];
	strcpy_s(m_msg, strlen(copy.m_msg)+1, copy.m_msg);
}

/*Destructor, takes and returns nothing*/
Exception::~Exception()	{/*delete [] m_msg;*/ /*delptr(m_array);*/}

/*Assignment operator, does a deep copy
Enter	: another Exception
Return	: *this*/
Exception& Exception::operator =(const Exception& rhs){ m_msg = rhs.m_msg;	return *this; }

/*Getter for message (returns message)
Enter	: Nothing
Return	: m_msg*/
const char* Exception::getMessage(		){return m_msg;}

/*Setter for message (sets message)
Enter	: string/character array
Return	: Nothing*/
void		Exception::setMessage(char* msg){m_msg=msg;}