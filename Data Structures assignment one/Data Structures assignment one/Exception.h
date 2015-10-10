using namespace std;

/*A class to be thrown as an acception*/
class Exception
{public:
	Exception();//Create empty message.
	Exception(char* msg);						//Pass message, and copy. 
	Exception(const Exception& copy);			//Deep Copy
   ~Exception();								//Delete char* msg array
	Exception& operator =(const Exception& rhs);//Set var equal to exception
	const char* getMessage();					//return char* msg
	void		setMessage(char* msg);			//Set message.
	friend ostream& operator<<(ostream& stream, const Exception& except);
private:
	char* m_msg;
};

ostream& operator<<(ostream& stream, Exception& except){//Out put message.
	const char *msg = except.getMessage();
	int message_length = sizeof( *msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) stream<< msg << ' ';  return stream;
}
//ostream& Exception::operator<<(ostream& stream, Exception& except)
	//{ for(int n(0); n < sizeof(*m_msg)/sizeof(char); n++) stream<< m_msg[n] << ' ';  return stream; }

/*ostream& Exception::operator<<(const Exception& except){//Out put message.
	int message_length = sizeof( m_msg ) / sizeof(char);
	for(int n(0); n < message_length; n++) cout<< m_msg << ' ';  return ;
}*/

Exception::Exception(){ m_msg = "Error, Undefined exception thrown."; }

Exception::Exception(char* msg) : m_msg(msg){}

Exception::Exception(const Exception& copy)
{	m_msg = new char [strlen(copy.m_msg)+1];
	strcpy_s(m_msg, strlen(copy.m_msg)+1, copy.m_msg);
}

Exception::~Exception()	{/*delete [] m_msg;*/ /*delptr(m_array);*/}

Exception& Exception::operator =(const Exception& rhs){ m_msg = rhs.m_msg;	return *this; }

const char* Exception::getMessage(		){return m_msg;}
void		Exception::setMessage(char* msg){m_msg=msg;}