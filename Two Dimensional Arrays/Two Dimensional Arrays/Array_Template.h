#ifndef ARRAY_TEMPLATE
#define ARRAY_TEMPLATE
#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment if I spelled that right and it's a real word.
#define WALL '|'
#define FLOR '_'
#define WIDTH 3
#define HEIGH 5
#define FOR(x)    for(i=0; i < x; i++)
#define FOR(x, y) for(i=0; i < x; i++)for(j=0; i < x; i++)
#define TP template<typename T>
#include"Exceptions.h"

TP
class cRow;//forward declaration

TP/*A Dynamic Two Dimensional Array handler,
  Allows you to use dynamic 2D arrays, just like regular 2D arrays,
  also allows assignment, and copying by constructor.
Enter	: Nothing | a row and collumn length | another cArray
Exit	: One possible exception, and one allowocation error, I failed to get rid of in time.*/
class cArray
{public:
	 cArray();									//Primary Const
	 cArray(int row, int col = 0);				//Seeded array Const
	 cArray(const cArray& copy);				//Copy Const
	~cArray();
	 cArray&operator= (const cArray& rhs);		//merge two arrays.
	 cRow<T>	operator[](int index);			//Return value from array
	 T&   getCel(int row, int col);				//return address of a var from the array
	 int  getRow()			{ return m_row; }
	 int  getCol()			{ return m_col; }
	 void setRow(int rows);//	{ m_row = rows; }
	 void setCol(int cols);//	{ m_col = cols; }
	 void setDim(int rows, int cols);
private:
	T**	m_array;			//The Array
	T** m_array2;
	const T DEFAULT = ' ';
	int m_row, m_col, i, j;	//the length of a row, the length of a column, and an index.
};

TP/*A class made to support dual brace operators, it is only used once by cArray*/
class cRow
{public:
	cRow(cArray<T>& array_, int row) : Row_array(array_), Row_row(row){}	//Initialization
	T& operator[](int column){	return Row_array.getCel(Row_row, column);	}//secondary brace op.
private:
	cArray<T>& Row_array;
	int Row_row;
};

TP/*Default Constructor
Enter	: Nothing
Return	: Nothing*/
cArray<T>::cArray()//Primary Const
{	m_array		= new T*[1];											//make dynamic,
	m_array[0]	= new T [1];											//set to 2 to allow terminating char
	m_array[0][0] = DEFAULT;											//Terminate
}

TP/*"seeded" (not default or copy) constructor
  Creates a new cArray with a row and column length as specified
Enter	: row, and possibly column length.
		  (if no column length is specified it defaults to 0)
Return	: Nothing*/
cArray<T>::cArray(int row, int col = 0) : m_row(row), m_col(col)		//initialization
{	m_array = new T*[m_row];											//make dynamic
	FOR(m_row)
	{	m_array[i] = new T[m_col];										//copy data
		FOR(m_col) m_array[i][j] = DEFAULT;
	}
}

TP/*A copy constructor (creates a deep copy of another cArray)
Enter	: ranother cArray
Return	: Nothing*/
cArray<T>::cArray(const cArray& copy)
{	m_row = copy.m_row;
	m_col = copy.m_col;
	m_array = new T*[m_row];
	FOR(m_row)
	{	m_array[i] = new T[m_col];										//make dynamic
		memcpy(m_array[i], copy.m_array[i], m_col); 					//copy array
	}
}

TP/*Destructor, takes and returns nothing*/
cArray<T>::~cArray()	{  }

TP/*Required by the lab guy, he said no points would because of it.
Enter	: row, and column coordinate.
Return	: the address of said slot.*/
T& cArray<T>::getCel(int row, int col)	{ return m_array[row][col]; }

TP/*Assignment operator, does a deep copy
Enter	: another cArray
		  m_row, m_col, and all data will be copied.
Return	: *this*/
cArray<T>& cArray<T>::operator=(const cArray& rhs)
{	m_row = rhs.m_row;
	m_col = rhs.m_col;
	FOR(m_row) memcpy(m_array[i], rhs.m_array[i], m_col); 				//copy array
	return *this;
}

TP/*Return a value from the array cArray (X[i])[j]
Enter	: an index
Return	: a_row
Exit	: this will cause cArray[i][j] to become a_row[j]
		  If handled improprerly an exception might be thrown.*/
cRow<T> cArray<T>::operator[](int index)
{	if(index >= 0 && index <= m_row)
	{	cRow<T> a_row(*this, index);
		return a_row;
	}else throw new Exception("Error Out of Bounds.\n");	
}

TP
void cArray<T>::setRow(int rows)
{	m_array2 = new T*[rows];			
	FOR(rows)
	{	m_array2[i] = new T[m_col];
		FOR(m_col) m_array2[i][j] = DEFAULT;	}

	 if(m_row < rows)FOR(m_row) memcpy(m_array2[i], m_array[i], m_col);
else if(rows < m_row)FOR(rows ) memcpy(m_array2[i], m_array[i], m_col);
	m_row = rows;
}

TP
void cArray<T>::setCol(int cols)
{	m_array2 = new T*[m_row];			
	FOR(m_row)
	{	m_array2[i] = new T[cols];
		FOR(cols) m_array2[i][j] = DEFAULT;	}

	 if(m_col < cols)FOR(m_row) memcpy(m_array2[i], m_array[i], m_col);
else if(cols < m_col)FOR(m_row) memcpy(m_array2[i], m_array[i],  cols);
	m_col = cols; 
}

TP
void cArray<T>::setDim(int rows, int cols)
{	m_array2 = new T*[rows];			
	FOR(rows)
	{	m_array2[i] = new T[cols];
		FOR(cols) m_array2[i][j] = DEFAULT;	}

	 if(m_row < rows && m_col < cols)FOR(m_row) memcpy(m_array2[i], m_array[i], m_col);
else if(m_row < rows && cols < m_col)FOR(m_row) memcpy(m_array2[i], m_array[i],  cols);
else if(rows < m_row && m_col < cols)FOR(rows ) memcpy(m_array2[i], m_array[i], m_col);
else if(rows < m_row && cols < m_col)FOR(rows ) memcpy(m_array2[i], m_array[i],  cols);
	m_row = rows;	m_col = cols; 
}
#endif