#ifndef NODE
#define NODE


template<typename T>
class cNode
{public:
	//Canonical members
	cNode()			{ throw new Exception("node default constructor called.\n"); }//Default constructor do not call
	cNode(cNode* err)
	{	m_data = err->m_data;	m_next = err->m_next;	m_prev = err->m_prev;
		throw new Exception("node copy constructor called.\n");					} //copy	constructor do not call
   ~cNode(){}

	//Members that should be used
	cNode(T data)	{ m_data = new T(data); }//cNode constructor, creates a new cCell, with data.
	void display()	{ m_data->display();	}//Display conduit, calls the display function for the cell.

private:
	cNode<T>* m_next;
	cNode<T>* m_prev;
	T* m_data;

template<typename T>
friend class cLL;

template<typename T>
friend class Iterator;
};

#endif