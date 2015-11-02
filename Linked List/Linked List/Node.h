#ifndef NODE
#define NODE

/************************************************************************
* Class: cNode
*
* Constructors:	
*	cNode()
*		Default constructor, do not use.
*
*	cNode(cNode* err)
*		Copy constructor, do not use.
*
*	cNode(T data)
*		True Constructor, creates a new cCell, with data.
*
* Mutators:
*
* Methods:
*	void display()
*		Display conduit, calls the display function for the cell.
*
*	T& Get_data()
*		Getter for <m_data>.
*
*	~cNode()
*		Destructor, no specified functionality.
*
*	friend class cLL
*		("Linked List class")
*
*	friend class Iterator
*		("the iterator class")
*
*************************************************************************/
template<typename T>
class cNode
{public:
	//Canonical members
	cNode()
	{	throw new Exception("node's default constructor called.\n");	}		//Default Constructor do not call
	
	cNode(cNode* err)
	{	m_data = err->m_data;	m_next = err->m_next;	m_prev = err->m_prev;
		throw new Exception("node's copy constructor called.\n");		}		//Copy Constructor do not call

   ~cNode(){}

	//Members that should be used
	cNode(T data)	{ m_data = new T(data); }//cNode constructor, creates a new cCell, with data.
	void display()	{ m_data->display();	}//Display conduit, calls the display function for the cell.
	T& Get_data()	{ return *m_data;		}//Getter for m_data.

private:
	cNode<T>* m_next;//the next node
	cNode<T>* m_prev;//the previous node
	T* m_data;		 //this node (haven't I already typed this?)

template<typename T>
friend class cLL;

template<typename T>
friend class Iterator;
};

#endif