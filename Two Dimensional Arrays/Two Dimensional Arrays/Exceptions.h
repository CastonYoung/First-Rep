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