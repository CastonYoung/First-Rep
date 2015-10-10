#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment if I spelled that right and it's a real word.

/**/
template<typename T>
class Array
{public:
	 Array();									//Primary Const
	 Array(int length, int start_index = 0);	//Seeded array Const
	 Array(const Array& copy);					//Copy Const
	~Array();
	 Array&	operator= (const Array& rhs);		//merge two arrays.
	 T&		operator[](int index);				//Return value from array
	 int GetStartIndex();						//access start index
	void SetStartIndex(int start_index);		//Sets start index
	 int GetLength();							//access length
	void SetLength(int length);					//Sets the length
private:
	T*	  m_array;
	short m_length/*length of array*/, m_start_index/*Offset of subscript operator*/;
};


template<typename T>
Array<T>::Array()//Primary Const
{	m_array = new T [2];												//make dynamic, set to 2 to allow terminating char
	m_start_index = 0;													//set start index
	m_length = 2;														//set length
	m_array[0]=' ';														//a space
	m_array[1]=NULL;													//break line
}

template<typename T>
Array<T>::Array(int length, int start_index = 0)//Seeded array Const
	: m_length(length), m_start_index(start_index)						//initialize
		{ m_array = new T [m_length]; }									//make dynamic

template<typename T>//Copy Const
Array<T>::Array(const Array& copy)
{	m_length = copy.m_length;											//copy length
	m_start_index = copy.m_start_index;									//copy start index
	m_array = new T [m_length];											//make dynamic
	memcpy(m_array, copy.m_array, m_length);							//copy array
}

template<typename T>
Array<T>::~Array()	{  }

template<typename T>//create merge operator.
Array<T>& Array<T>::operator=(const Array& rhs)
{	m_array = rhs.m_array;
	m_length = rhs.m_length;
	m_start_index = rhs.m_start_index;
	return *this;
}

template<typename T>//Return value from array
T& Array<T>::operator[]		(int index)
{	if(index >= m_start_index && index < m_start_index + m_length)	return m_array[index - m_start_index];
	else throw new Exception("Error Out of Bounds.\n");
}

template<typename T>
 void Array<T>::SetStartIndex	(int start_index)//Sets start index
{	if (-ALOT<start_index && start_index<ALOT) m_start_index =	start_index;//Check size and set start_index
	else throw new Exception( "Error: Start Index too large.\n" );
}

template<typename T>
void Array<T>::SetLength		(int length		)//Sets the length
{	if (0<length && length<2*ALOT)	m_length = length;					//Checks bounds	and sets length
	else throw new Exception("Error: Length too long, or non existant.\n");
}

template<typename T>
 int Array<T>::GetStartIndex(){ return m_start_index; }					//access start index
template<typename T>
 int Array<T>::GetLength	(){ return m_length		; }					//access length