#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment if I spelled that right and it's a real word.
#define FOR(x) for(i=0; i < x; i++)
#define TP template<typename T>

TP
class Row;

/**/
TP
class Array
{public:
	 Array();									//Primary Const
	 Array(int row = 0, int col = 0);			//Seeded array Const
	 Array(const Array& copy);					//Copy Const
	~Array();
	 Array&	operator= (const Array& rhs);		//merge two arrays.
	 Row<T>	operator[](int index);				//Return value from array
	 int  getRow()			{ return m_row; }
	 int  getCol()			{ return m_col; }
	 void setRow(int rows)	{ m_row = rows; }
	 void setCol(int cols)	{ m_col = cols; }

//	 int GetStartIndex();						//access start index
//	void SetStartIndex(int start_index);		//Sets start index
//	 int GetLength();							//access length
//	void SetLength(int length);					//Sets the length
private:
	T**	  m_array;
	int m_row, m_col, i;
	short m_length, m_start_index;
};

TP
class Row
{public:
	Row(Array<int>& array_, int row);
	T& operator[](int column);
};

TP
Array<T>::Array()//Primary Const
{	m_array		= new T*[1];											//make dynamic,
	m_array[0]	= new T [1];											//set to 2 to allow terminating char
	m_array[0][0] = NULL;												//Terminate

	m_start_index = 0;													//set start index
	m_length = 2;														//set length
}

TP//Seeded array Const
Array<T>::Array(int row = 0, int col = 0) : m_row(row+1), m_col(col+1)	//initialize
{	m_array = new T*[m_row];											//make dynamic
	FOR(m_row) m_array[i] = new T[m_col];
}

TP//Copy Const
Array<T>::Array(const Array& copy)
{	m_row = rhs.m_row;
	m_col = rhs.m_col;
	m_array = new T*[m_row];
	FOR(m_row) m_array[i] = new T[m_col]								//make dynamic
	memcpy(m_array, copy.m_array, m_row*m_col/*m_length*/);				//copy array

	m_length = copy.m_length;											//copy length
	m_start_index = copy.m_start_index;									//copy start index
}

TP
Array<T>::~Array()	{  }

TP//create merge operator.
Array<T>& Array<T>::operator=(const Array& rhs)
{	m_row = rhs.m_row;
	m_col = rhs.m_col;
	memcpy(m_array, rhs.m_array, m_row*m_col/*m_length*/);				//copy array

	m_length = rhs.m_length;
	m_start_index = rhs.m_start_index;
	return *this;
}

TP//Return value from array
T& Array<T>::operator[]		(int index)
{	if(index >= m_start_index && index < m_start_index + m_length)	return m_array[index - m_start_index];
	else throw new Exception("Error Out of Bounds.\n");
}

/*
TP
 void Array<T>::SetStartIndex	(int start_index)//Sets start index
{	if (-ALOT<start_index && start_index<ALOT) m_start_index =	start_index;//Check size and set start_index
	else throw new Exception( "Error: Start Index too large.\n" );
}

TP
void Array<T>::SetLength		(int length		)//Sets the length
{	if (0<length && length<2*ALOT)	m_length = length;					//Checks bounds	and sets length
	else throw new Exception("Error: Length too long, or non existant.\n");
}

TP
 int Array<T>::GetStartIndex(){ return m_start_index; }					//access start index
TP
 int Array<T>::GetLength	(){ return m_length		; }					//access length
 */