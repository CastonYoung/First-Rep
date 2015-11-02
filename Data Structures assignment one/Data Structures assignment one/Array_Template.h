#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment if I spelled that right and it's a real word.

/************************************************************************
* Class: cArray
*
* Constructors:
*	 Array();									//Primary Const
*	 Array(int length, int start_index = 0);	//Seeded array Const
*	 Array(const Array& copy);					//Copy Const
*
* Mutators:
*	Array&	operator= (const Array& rhs);		//merge two arrays.
*	void SetLength(int length);					//Sets the length.
*	void SetStartIndex(int start_index);		//Sets start index.
*
* Methods:
	~Array();									//No additional functionality
	 T&		operator[](int index);				//Return value from array
	 int GetStartIndex();						//access start index
	 int GetLength();							//access length
*************************************************************************/

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

/**************************************************************
*   Entry:  Nothing
*
*    Exit:  A dynamic array with 2 cells is created inside the class,
*			and member variables are initialized.
*
* Purpose:  Initialize variables so methods will work.
*
**************************************************************/
template<typename T>
Array<T>::Array()//Primary Const
{	m_array = new T [2];												//make dynamic, set to 2 to allow terminating char
	m_start_index = 0;													//set start index
	m_length = 2;														//set length
	m_array[0]=' ';														//a space
	m_array[1]=NULL;													//break line
}


/**************************************************************
*   Entry:  A length, and maybe a start index. 
*
*    Exit:  A dynamic array is created inside the class,
*			and member variables are initialized.
*
* Purpose:  Initialize variables so methods will work.
*
**************************************************************/
template<typename T>
Array<T>::Array(int length, int start_index = 0)//Seeded array Const
	: m_length(length), m_start_index(start_index)						//initialize
		{ m_array = new T [m_length]; }									//make dynamic

/**************************************************************
*	Entry:  Another Array
*
*    Exit:  An exact copy of an Array is created.
*
* Purpose:  Initialize variables so methods will work.
*
**************************************************************/
template<typename T>
Array<T>::Array(const Array& copy)
{	m_length = copy.m_length;											//copy length
	m_start_index = copy.m_start_index;									//copy start index
	m_array = new T [m_length];											//make dynamic
	memcpy(m_array, copy.m_array, m_length);							//copy array
}

/**************************************************************
*	Entry:  None
*
*    Exit:  Deallocation of the object.
*
* Purpose:  Deallocation of the array.
*
**************************************************************/
template<typename T>
Array<T>::~Array()	{  }

/**************************************************************
*	Entry:  An array address
*
*    Exit:  All data has been copied to this Array
*
* Purpose:  Do a deep copy
*
**************************************************************/
template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{	m_array = rhs.m_array;
	m_length = rhs.m_length;
	m_start_index = rhs.m_start_index;
	return *this;
}

/**************************************************************
*	Entry:  an index
*
*    Exit:  returns a member of the array, by address
*
* Purpose:  Access members of the array
*
**************************************************************/
template<typename T>//Return value from array
T& Array<T>::operator[]		(int index)
{	if(index >= m_start_index && index < m_start_index + m_length)	return m_array[index - m_start_index];
	else throw new Exception("Error Out of Bounds.\n");
}

/**************************************************************
*	Entry:  an integer
*
*    Exit:  a new start_index is set for the array
*
* Purpose:  set a different start index.
*
**************************************************************/
template<typename T>
 void Array<T>::SetStartIndex	(int start_index)//Sets start index
{	if (-ALOT<start_index && start_index<ALOT) m_start_index =	start_index;//Check size and set start_index
	else throw new Exception( "Error: Start Index too large.\n" );
}

/**************************************************************
*	Entry:  
*
*    Exit:  
*
* Purpose:  
*
**************************************************************/
template<typename T>
void Array<T>::SetLength		(int length		)//Sets the length
{	if (0<length && length<2*ALOT)	m_length = length;					//Checks bounds	and sets length
	else throw new Exception("Error: Length too long, or non existant.\n");
}

/**************************************************************
*	Entry:  None
*
*    Exit:  returns m_start_index.
*
* Purpose:  a getter for m_start_index.
*
**************************************************************/
template<typename T>
 int Array<T>::GetStartIndex(){ return m_start_index; }			//access start index

/**************************************************************
*	Entry:  None
*
*    Exit:  returns m_length
*
* Purpose:  a getter for m_length.
*
**************************************************************/
template<typename T>
int Array<T>::GetLength	(){ return m_length; }					//access length