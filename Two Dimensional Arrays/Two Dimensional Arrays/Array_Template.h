#ifndef ARRAY_TEMPLATE
#define ARRAY_TEMPLATE
#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment if I spelled that right and it's a real word.
#define WALL '|'
#define FLOR '_'
#define WIDTH 10
#define HEIGH 10
#define FOR(x) for(i=0; i < x; i++)
#define TP template<typename T>
#include"Exceptions.h"

TP
class Row;

/*A Two Dimensional Array handler*/
TP
class Array
{public:
	 Array();									//Primary Const
	 Array(int row, int col = 0);				//Seeded array Const
	 Array(const Array& copy);					//Copy Const
	~Array();
	 Array&	operator= (const Array& rhs);		//merge two arrays.
	 Row<T>	operator[](int index);				//Return value from array
	 T&   getCel(int row, int col);				//The lab over seer said I wouldn't loose points for this
	 int  getRow()			{ return m_row; }
	 int  getCol()			{ return m_col; }
	 void setRow(int rows)	{ m_row = rows; }
	 void setCol(int cols)	{ m_col = cols; }
private:
	T**	m_array;								//The Array
	int m_row, m_col, i;
};

TP/*A class made to support dual brace operators*/
class Row
{public:
	Row(Array<T>& array_, int row) : Row_array(array_), Row_row(row){}	//Initialization
	T& operator[](int column){	return Row_array.getCel(Row_row, column);	}//secondary brace op.
private:
	Array<T>& Row_array;
	int Row_row;
};

TP//default constructor.
Array<T>::Array()//Primary Const
{	m_array		= new T*[1];											//make dynamic,
	m_array[0]	= new T [1];											//set to 2 to allow terminating char
	m_array[0][0] = NULL;												//Terminate
}

TP//Seeded array Const
Array<T>::Array(int row, int col = 0) : m_row(row), m_col(col)			//initialize
{	m_array = new T*[m_row];											//make dynamic
	FOR(m_row) m_array[i] = new T[m_col];
}

TP//Copy Const
Array<T>::Array(const Array& copy)
{	m_row = copy.m_row;
	m_col = copy.m_col;
	m_array = new T*[m_row];
	FOR(m_row)
	{	m_array[i] = new T[m_col];										//make dynamic
		memcpy(m_array[i], copy.m_array[i], m_col); 					//copy array
	}
}

TP
Array<T>::~Array()	{  }

TP
T& Array<T>::getCel(int row, int col)	{ return m_array[row][col]; }

TP//copy
Array<T>& Array<T>::operator=(const Array& rhs)
{	m_row = rhs.m_row;
	m_col = rhs.m_col;
	FOR(m_row) memcpy(m_array[i], rhs.m_array[i], m_col); 				//copy array
	return *this;
}

TP//Return value from array
Row<T> Array<T>::operator[](int index)
{	if(index >= 0 && index <= m_row)
	{	
		Row<T> a_row(*this, index);
		return a_row;
	}
	else throw new Exception("Error Out of Bounds.\n");	
}
//I'd put more comments in but I lack the time.
#endif