#include"Exceptions.h"
#define STRING string//find_
#define IT Iterator<T>
#define CAST(x) reinterpret_cast< x > 
using namespace std;

template<typename T/*, typename find_*/>
		class LL;

template<typename T>
		class node;

template<typename T>
		class Iterator;

template<typename T>
class node
{public:
	node(T data)	{ m_data = new T(data); }
	void display()	{ m_data->display(); }

private:
	node<T>* m_next;
	node<T>* m_prev;
	T* m_data;

friend class LL<T>;
};


template<typename T/*, typename find_*/>
class LL
{public:
	LL(){	m_head = 0;	m_tail = 0;	N_items = 0;
			LNI ="Error: list not initialized.";	}//-----Constructor


	int Get_size()		  { return N_items;			}
	const node<T>& First(){ return m_head;			}
	const node<T>& Last (){ return m_tail;			}
	bool isEmpty()		  { return (N_items == 0);	}
	Iterator<T> Begin()	  { return Iterator(m_head);}
	Iterator<T>   End()	  { return Iterator(m_tail);}

	
#ifdef DISPLAY_METHOD
	void Display_all()//--Calls Cell.Display once for each city. Shares many elements with search routine.
	{	node<T>* nptr = m_head;			//Create a temporary node 

		do{	nptr->m_data->Display();	//Call display
			nptr = nptr->m_next;		//Go to the next node.
		} while( nptr != m_head );		//While not at end.
	}
#endif


	void Append(T data)//----------------------------------Adds a new City
	{	++N_items;
		node<T>* temp = new node<T>(data);	//Allocate and create a new node.
		if (m_head == 0) { m_head = temp; }	//If first list item, set m_head to temp.
		else{ m_tail->m_next = temp;		// /Move the new node 
			  temp->m_prev = m_tail; }		// \pointer to the end.
		m_tail = temp;						//Declare this to be the tail
		temp->m_next = m_head;				//Reattach tail to head
		m_head->m_prev = m_tail;			//Reattach head to tail
	}

	void Preppend(T data)//----------------------------------Adds a new City
	{	++N_items;
		node<T>* temp = new node<T>(data);	//Allocate and create a new node.
		if (m_tail == 0) { m_tail = temp; }	//If first list item, set m_tail to temp.
		else{ m_head->m_prev = temp;		// /Move the new node 
			  temp->m_next = m_head; }		// \pointer to the end.
		m_head = temp;						//Declare this to be the tail
		temp->m_prev = m_tail;				//Reattach tail to head
		m_tail->m_next = m_head;			//Reattach head to tail
	}


#ifdef CELL_ID
	node<T>* Find(STRING tag)//--------------------Returns a specific node
	{if(isEmpty()){
		for(Iterator<T> i = (Begin()); i != End(); i++;)
		{	if ( (*i).m_data->cell_ID == tag) return i.Get();	}
		return 0;									//if never found
	}else throw LNI;}							//if there is no list //return 0;}

	T* operator[](STRING index){ return (Find(index))->m_data; }
#endif

	node<T>* Find(int index)//--------------------Returns a specific node
	{if(isEmpty()){
		for(int j=0; Iterator<T> i=Begin(); i != End(); i++; j++)
		{	if(j == index) return i.Get();	}
		return 0;									//if never found
	}else throw LNI;}							//if there is no list //return 0;}

	T* operator[](int index){ return (Find(index))->m_data; }


	void InsertAfter(T data, T* dptr)
	{if(isEmpty()){
		++N_items;
		node<T>* temp = new node<T>(data);	//Allocate and create a new node.
		temp->m_next = dptr->m_next;
		dptr->m_next->m_prev = temp;
		dptr->m_next = temp;				// /Move the new node 
		temp->m_prev = dptr;				// \pointer to the end.
	}else throw LNI;}						//if there is no list //return 0;}


	void InsertBefore(T data, T* dptr)
	{if(isEmpty()){
		++N_items;
		node<T>* temp = new node<T>(data);	//Allocate and create a new node.
		temp->m_prev = dptr->m_prev;
		dptr->m_prev->m_next = temp;
		dptr->m_prev = temp;				// /Move the new node 
		temp->m_next = dptr;				// \pointer to the end.
	}else throw LNI;}						//if there is no list //return 0;}


	node<T>* Extract(node<T>* nptr, bool del = false)//----Removes a node, and returns it.
	{	node<T>* temp = nptr->m_next;				//Saves address before disconnection
		if(del) nptr->m_data->~Cell();				//? Deletes Cell
		if(nptr == m_head) m_head = nptr->m_next;	//If at m_head update
   else if(nptr == m_tail) m_tail = nptr->m_prev;	//If at m_tail update
		nptr = nptr->m_next;						//Move m_next
		nptr->m_prev = temp->m_prev;				//Move m_prev
		if(del) temp->~node();						//? Deletes node
		N_items--;									//update N_items
		if(del) return nptr;						//Used for Purge
		/*else*/return temp;						//Required
	}


	void Purge()
	{	node<T>* nptr = m_head;
		do{ nptr = Extract( nptr, 1 );	//Call extract with delete key.
		}while( nptr != m_head );		//While not at end.
		m_head = 0;
		m_tail = 0;
	}

	~LL(){ Purge(); }
	

private: 
	int N_items;
	node<T>* m_head; node<T>* m_tail;
	Exception LNI;
};


template<typename T>
class Iterator
{public:
				 Iterator ();
				 Iterator (Iterator*p) : m_node(p->m_node)//{m_node = p->m_node}
				 Iterator (node<T>* p) : m_node(p)
	Iterator&	operator= (Iterator other)	{ m_node = other.m_node;}
	Iterator&	operator= (node<T>* other)	{ m_node = other	   ;}
	node<T> 	operator* ()				{ return *m_node; 		}
	node<T>*	Get()						{ return  m_node;		}

	Iterator	operator++()
				{	m_node = m_node->m_next;	return m_node;	}

	Iterator	operator++(int)
				{	Iterator temp(m_node);	++m_node;	return temp;	}

	Iterator	operator--()
				{	m_node = m_node->m_prev;	return m_node;	}

	Iterator	operator--(int)
				{	Iterator temp(m_node);	--m_node;	return m_node;	}
	
	Iterator	operator==(Iterator other){ return (m_node == other.m_node); }
//	Iterator	operator==(node<T>* other){ return (m_node == other)	   ; }

	Iterator	operator!=(Iterator other){ return (m_node != other.m_node); }
//	Iterator	operator!=(node<T>* other){ return (m_node != other		  ); }

				~Iterator (){}

private:
	node<T>* m_node;
};

#ifdef NOT

void iter()
{	for(Iterator i=(LL.Begin()); i != LL.End(); i++)
	{	
	}
}

#endif