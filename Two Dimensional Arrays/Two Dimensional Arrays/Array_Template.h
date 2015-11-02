#ifndef ARRAY_TEMPLATE
#define ARRAY_TEMPLATE
#define ALOT 63	//2^(8-1)/2 - 1 Stands for allotment.
#define WALL '|'
#define FLOR '_'
#define SMALL 5
#define MEDIM 10
#define LARGE 15
#define LOP(x)     for(i=0; i < x; i++)
#define LOOP(x, y) for(i=0; i < x; i++) for(j=0; j < y; j++)
#define TP template<typename T>
#include"Exceptions.h"

TP
class cRow;//forward declaration


/************************************************************************
* Class: cArray
*
* Constructors:	
*	cArray();									//Primary Const
*	cArray(int row, int col = 0);				//Seeded array Const
*	cArray(const cArray& copy);					//Copy Const
*
* Mutators://								All self explanatory
*	void setRow(int rows);
*	void setCol(int cols);
*	void setDim(int rows, int cols);
*
* Methods:		
*	cArray&operator= (const cArray& rhs);		//merge two arrays.
*	 cRow<T>	operator[](int index);			//Return value from array
*	 T&   getCel(int row, int col);				//return by address a T
*	 int  getRow();								//<-self explanatory
*	 int  getCol();								//<-J
*************************************************************************/
TP
class cArray
{public:
	 cArray();									//Primary Const
	 cArray(int row, int col = 0);				//Seeded array Const
	 cArray(const cArray& copy);				//Copy Const
	~cArray();
	 cArray&operator= (const cArray& rhs);		//merge two arrays.
	 cRow<T>	operator[](int index);			//Return value from array
	 T&   getCel(int row, int col);				//return by address a T
	 int  getRow()			{ return m_row; }
	 int  getCol()			{ return m_col; }
	 void setRow(int rows);
	 void setCol(int cols);
	 void setDim(int rows, int cols);
private:
	T**	m_array;			//The Array
	T** m_array2;
	const T DEFAULT = ' ' ;	//Default opt. I plan on making it NULL after this test program.
	int m_row, m_col, i, j;	//the length of a row, the length of a column, and an index.
};

/************************************************************************
* Class: cRow
*
* Constructor:	
*	cRow(cArray<T>& array_, int row)		//Canonocity not required
*											//See UML
*
* Mutators:	None other than the method.
*
* Method:
*	T& operator[](int column)
*
*************************************************************************/

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
	m_array[0]	= new T [1];											//
	m_array[0][0] = DEFAULT;											//Terminate
}

TP/*
  Parameterized Constructor
  Creates a new cArray with a row and column length as specified
Enter	: row, and possibly column length.
		  (if no column length is specified it defaults to 0)
Return	: Nothing*/
cArray<T>::cArray(int row, int col = 0) : m_row(row), m_col(col)		//initialization
{	m_array = new T*[m_row];											//make dynamic
	LOP(m_row) m_array[i] = new T[m_col];	
	LOOP(m_row, m_col) m_array[i][j] = DEFAULT;
}

TP/*Copy Const
  A copy constructor (creates a deep copy of another cArray)
Enter	: another cArray
Exit	: A copy of the above is made.*/
cArray<T>::cArray(const cArray& copy)
{	
	m_row = copy.m_row;
	m_col = copy.m_col;
	m_array = new T*[m_row];
	LOP(m_row)	m_array[i] = new T[m_col];								//make dynamic
	LOOP(m_row, m_col)	memcpy_s(m_array[i], m_col * sizeof(T), copy.m_array[i], m_col);//copy array
}

TP//Destructor. No special functionality.
cArray<T>::~cArray()	{  }

TP/*Required by the lab guy, he said no points would because of it.
Enter	: row, and column coordinate.
Return	: the address of said slot.*/
T& cArray<T>::getCel(int row, int col)	{ return m_array[row][col]; }

TP/*Assignment operator, does a deep copy
Enter	: another cArray
Exit	: return *this
		  m_row, m_col, and all data will be copied.*/
cArray<T>& cArray<T>::operator=(const cArray& rhs)
{	m_row = rhs.m_row;
	m_col = rhs.m_col;
	LOP(m_row) memcpy_s(m_array[i], rhs.m_array[i], m_col); 				//copy array
	return *this;
}

TP/*Return a value from the array cArray (X[i])[j]
Enter	: an index
Exit	: reutrn a_row
			this will cause cArray[i][j] to become a_row[j]
		  If handled improprerly an exception might be thrown.*/
cRow<T> cArray<T>::operator[](int index)
{	if(index >= 0 && index <= m_row)
	{	cRow<T> a_row(*this, index);
		return a_row;
	}else throw new Exception("Error Out of Bounds.\n");	
}

TP/*
  Changes the height of the 2D array.
Enter	: a height
Exit	: an enitrely new 2D_array is produced
		  and all the data copied. Then the original
		  is deleted (deallocated), and is reassigned
		  to the copy.*/
void cArray<T>::setRow(int rows)
{	m_array2 = new T*[rows];			
	LOP(rows)	m_array2[i] = new T[m_col];
	LOOP(rows, m_col) m_array2[i][j] = DEFAULT;

	 if(m_row < rows)LOP(m_row) memcpy_s(m_array2[i], m_col * sizeof(T), m_array[i], m_col);
else if(rows < m_row)LOP(rows ) memcpy_s(m_array2[i], m_col * sizeof(T), m_array[i], m_col);
	m_row = rows;
	delete [] m_array;
	m_array = m_array2;
}

TP/*
  Changes the width of the 2D array.
Enter	: a width
Exit	: an enitrely new 2D_array is produced
		  and all the data copied. Then the original
		  is deleted (deallocated), and is reassigned
		  to the copy.*/
void cArray<T>::setCol(int cols)
{	m_array2 = new T*[m_row];			
	LOP(m_row)	m_array2[i] = new T[cols];
	LOOP(m_row, cols) m_array2[i][j] = DEFAULT;

	 if(m_col < cols)LOP(m_row) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i], m_col);
else if(cols < m_col)LOP(m_row) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i],  cols);
	m_col = cols;
	delete [] m_array;
	m_array = m_array2;
}

TP/*
  Changes the height of the 2D array.
Enter	: a width
Exit	: an enitrely new 2D_array is produced
		  and all the data copied. Then the original
		  is deleted (deallocated), and is reassigned
		  to the copy.*/
void cArray<T>::setDim(int rows, int cols)
{	m_array2 = new T*[rows];			
	LOP(rows)	m_array2[i] = new T[cols];
	LOOP(rows, cols) m_array2[i][j] = DEFAULT;

	 if(m_row < rows && m_col < cols)LOP(m_row) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i], m_col);
else if(m_row < rows && cols < m_col)LOP(m_row) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i],  cols);
else if(rows < m_row && m_col < cols)LOP(rows ) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i], m_col);
else if(rows < m_row && cols < m_col)LOP(rows ) memcpy_s(m_array2[i], cols * sizeof(T), m_array[i],  cols);
	m_row = rows;	m_col = cols;
	delete [] m_array;
	m_array = m_array2;
}
#endif