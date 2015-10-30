#ifndef EXCEPTIONS
#define EXCEPTIONS

#include<iostream>
using namespace std;

/************************************************************************
* Class: Exception
*
* Constructors:	
*	Exception()
*		Default Constructor, initializes <m_msg>.
*
*	Exception(char* msg)
*		Creates an exception by message being passed.
*
*	Exception(const Exception& copy)
*		Copy Constructor, a required but un-used function.
*
* Mutators:
*	Exception& operator =(const Exception& rhs)
*		Assignment over load, does a deep copy
*
*	Exception& operator =(char* rhs)
*		Assignment over load, does a deep copy
*
*	void setMessage(char* msg)
*		Setter for message (sets message)
*
* Methods:
*   ~Exception()
*		Destructor, takes and returns nothing
*
*	const char* getMessage(		)
*		Getter for message (returns message)
*
*	friend ostream& operator<<(ostream& stream, const Exception& except);
*		
*
*Private:
*	char* m_msg		The (error) message.
*************************************************************************/
class Exception
{public:

	/*Because I apparently need to have a default constructor
	Enter	: Nothing
	Return	: Nothing*/
	Exception(){ m_msg = "Error, Undefined exception thrown."; }
	

	/*Creats an exception by message being passed.
	Enter	: string/character array
	Return	: Nothing*/
	Exception(char* msg) : m_msg(msg){} 

	
	/*A copy constructor (does a deep copy)
	Enter	: an Exception
	Return	: Nothing*/
	Exception(const Exception& copy)
	{	m_msg = new char [strlen(copy.m_msg)+1];
		strcpy_s(m_msg, strlen(copy.m_msg)+1, copy.m_msg);
	}


	/*Destructor, takes and returns nothing*/
   ~Exception()	{/*delete [] m_msg;*/ /*delptr(m_array);*/}
	

	/*Assignment operator, does a deep copy
	Enter	: another Exception
	Return	: *this*/
	Exception& operator =(const Exception& rhs)	{ m_msg = rhs.m_msg;return *this; }
	

	/*Assignment operator
	Enter	: a string;
	Return	: *this*/
	Exception& operator =(char* rhs)			{ m_msg = rhs;		return *this; }

	/*Setter for message (sets message)
	Enter	: string/character array
	Return	: Nothing*/
	void setMessage(char* msg){m_msg=msg;}


	/*Getter for message (returns message)
	Enter	: Nothing
	Return	: m_msg*/
	const char* getMessage(		){return m_msg;}


	friend ostream& operator<<(ostream& stream, const Exception& except);

private:
	char* m_msg;
};



/*ostream operator overload,
  overloads the << operator to output msg, by passing in the Exception itself
Enter	: an Exception, presumably one that has just been caught.
Return	: stream (basically Nothing)
AlsoExit: The msg is outputed.*/
ostream& operator<<(ostream& stream, Exception& except){//Out put message.
	const char *msg = except.getMessage();
	int message_length = sizeof( *msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) stream<< msg << ' ';  return stream;
};

#ifdef FALSE
ostream& Exception::operator<<(ostream& stream, Exception& except)
	{ for(int n(0); n < sizeof(*m_msg)/sizeof(char); n++) stream<< m_msg[n] << ' ';  return stream; }

ostream& Exception::operator<<(const Exception& except){//Out put message.
	int message_length = sizeof( m_msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) cout<< m_msg << ' ';  return ;
}
#endif

#endif