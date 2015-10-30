#ifndef LINKED_LIST
#define LINKED_LIST

#include "Header.h"
#include "Exceptions.h"
#include "Node.h"
#include "Iterator.h"
#define STRING string//find_
using namespace std;

/************************************************************************
* Class: cLL ("Linked List")
*
* Constructors:	
*	cLL()
*		Default Constructor, initializes all member variables to 0,
*		except for LNI which becomes a string.
*
*	cLL(cLL* other)
*		required, but un-used function
*
* Mutators:
*	cLL<T>& operator=(const cLL<T>& rhs)	Performs a deep copy.
*
* Methods:
*	int Get_size()		Getter N_items
*	cNode<T>& First()	Getter m_head
*	cNode<T>& Last ()	Getter m_tail
*	bool Is_empty  ()	returns binary reply
*	Iterator<T> Begin()	Returns a new iterator for the m_head node.
*	Iterator<T>   End()	Returns a new iterator for the m_tail node.
*
*#ifdef DISPLAY_METHOD
*	void Display_all()	Calls cCell.Display once for each city.
*#endif
*
*	void Append  (T data)	Adds a new T to the back (tail end)
*	void Preppend(T data)	Adds a new T to the front(head end)
*
*#ifdef CELL_ID
*	cNode<T>* Find(STRING tag)	<Returns a specific node
*	T* operator[](STRING index)	</
*#endif
*
*	cNode<T>* Find(int index)	<Returns a specific node
*	T* operator[](int index)	</
*
*	void InsertAfter (T data, T* dptr)	insert <data> after <dptr>.
*	void InsertBefore(T data, T* dptr)	insert <data> before<dptr>.
*
*	cNode<T>* Extract(cNode<T>* nptr, bool del = false)	Removes a node, and returns it.
*
*	void Purge()	Deletes all
*
*Private:
*	int		  N_items	The nummber of items in the list.
*	cNode<T>* m_head	The head node.
*	cNode<T>* m_tail	The tail node.
*	Exception LNI		("List Not Initialized") an error message.
*************************************************************************/

template<typename T/*, typename find_*/>
class cLL
{public:
	cLL();//Default Constructor
	cLL(cLL* other){}

	int Get_size();
	cNode<T>& First();
	cNode<T>& Last ();
	bool isEmpty();
	Iterator<T> Begin();
	Iterator<T>   End();

#ifdef DISPLAY_METHOD
	void Display_all();//Calls cCell.Display once for each city.
#endif

	void Append  (T data);//Adds a new T to the back (tail end)
	void Preppend(T data);//Adds a new T to the front(head end)

#ifdef CELL_ID
	cNode<T>* Find(STRING tag);	//<Returns a specific node
	T* operator[](STRING index);//</
#endif

	cNode<T>* Find(int index);//<Returns a specific node
	T* operator[](int index);//</

	void InsertAfter (T data, T* dptr);//insert <data> after <dptr>.
	void InsertBefore(T data, T* dptr);//insert <data> before<dptr>.

	cNode<T>* Extract(cNode<T>* nptr, bool del = false);//Removes a node, and returns it.

	void Purge();//Deletes all

	~cLL();
	

private: 
	int N_items;
	cNode<T>* m_head;
	cNode<T>* m_tail;
	Exception LNI;
//	Exception CNF;
};



/*Default Constructor
No items may be passed.
Initializes all members to 0, except LNI which it initalizes as shown.*/
template<typename T>
cLL<T>::cLL(){	m_head = 0;	m_tail = 0;	N_items = 0;
				LNI ="Error: list not initialized.";	}

/*Getter, returns N_items*/
template<typename T>
int	 cLL<T>::Get_size()	{ return N_items;		}

/*Getter, returns m_head*/
template<typename T>
cNode<T>& cLL<T>::First()	{ return m_head;		}

/*Getter, returns m_tail*/
template<typename T>
cNode<T>& cLL<T>::Last ()	{ return m_tail;		}

/*Checks if the list is empty
No inputs required, returns (N_items == 0);*/
template<typename T>
bool  cLL<T>::isEmpty()			{ return (N_items == 0);}

/*Cast Getter, returns a new iterator for the head node. (uses Iterator.h)*/
template<typename T>//(note the term "Cast Getter" is not standardized)
Iterator<T> cLL<T>::Begin()		{ return Iterator<T> (m_head);}

/*Cast Getter, returns a new iterator for the head node. (uses Iterator.h)*/
template<typename T>
Iterator<T> cLL<T>::End()		{ return Iterator<T> (m_tail);}


/*If type T has a Display function, this function will use it
to display all the items of the list.
No parameters are taken except the typename which is already known.
Once completed all the list items will be displayed, assuming Display is properly written.
Handles all Display methods.*/
#ifdef DISPLAY_METHOD
template<typename T>
void cLL<T>::Display_all()
{	cNode<T>* nptr = m_head;		//Create a temporary node 

	do{	nptr->m_data->Display();	//Call display
		nptr = nptr->m_next;		//Go to the next node.
	} while( nptr != m_head );		//While not at end.
}
#endif


/*Adds a list node w/ data to the start (head end) of the list,
and increments N_items respectively.
Takes one parameter (the data to be added).
References cCell class
Returns nothing.*/
template<typename T>
void cLL<T>::Preppend(T data)
{	++N_items;
	cNode<T>* temp = new cNode<T>(data);//Allocate and create a new cNode.
	if (m_tail == 0) { m_tail = temp; }	//If first list item, set m_tail to temp.
	else{ m_head->m_prev = temp;		// /Move the new cNode 
			temp->m_next = m_head; }	// \pointer to the end.
	m_head = temp;						//Declare this to be the tail
	temp->m_prev = m_tail;				//Reattach tail to head
	m_tail->m_next = m_head;			//Reattach head to tail
}


/*Adds a list node w/ data to the back (tail end) of the list,
and increments N_items respectively.
Takes one parameter (the data to be added).
References cCell & Node classes
Returns nothing.*/
template<typename T>
void cLL<T>::Append(T data)//----------------------------------Adds a new City
{	++N_items;
	cNode<T>* temp = new cNode<T>(data);//Allocate and create a new cNode.
	if (m_head == 0) { m_head = temp; }	//If first list item, set m_head to temp.
	else{ m_tail->m_next = temp;		// /Move the new cNode 
		  temp->m_prev = m_tail; }		// \pointer to the end.
	m_tail = temp;						//Declare this to be the tail
	temp->m_next = m_head;				//Reattach tail to head
	m_head->m_prev = m_tail;			//Reattach head to tail
}


/*If type <T> includes an ID tag called cell_ID create
 A find function that finds the cCell by comparing cell_IDs
 requires a cell_ID (tag) as an input,
 (tag is supposed to be of type <find_>, but since my multiple typename is not yet functional must be a string)
 Calls/References Iterator & cCell classes, as well as internal Begin(), and End(), functions.
 Supposed to return a pointer, but may return 0, if nothing is found, or throw the List Not Initialized Exception.
*/
#ifdef CELL_ID
	template<typename T>
	cNode<T>* cLL<T>::Find(STRING tag)
	{if(!isEmpty()){
			for(Iterator<T> i = Begin(); i != End(); i++)
			{	if ( i.Get()->m_data->GetID() == tag) return i.Get();	}
	/*		or*/if (  m_tail->m_data->GetID() == tag) return m_tail;
			return 0;									//if never found
	}else throw LNI;}									//if there is no list //return 0;}

	/*Also overloads the [] operator,
	 to call Find, so this can be used without having to type Find( x );
	 has same functionality (and returns) as Find.*/
	template<typename T>
	T* cLL<T>::operator[](STRING index){ if(Find(index)) return (Find(index))->m_data; else return false; }
#endif


/*A find function that finds the cCell by using an index
 requires an index as an input, the index should work just like the the number in [] when using an array.
 Calls/References Iterator & cCell classes, as well as internal Begin(), and End(), functions.
 Supposed to return a pointer, but may return 0, if nothing is found, or throw the List Not Initialized Exception.
*/
template<typename T>
cNode<T>* cLL<T>::Find(int index)
{if(!isEmpty()){
	int j;
	for(j=0; Iterator<T> i=Begin(); i != End(); i++; j++)
	{	if(j == index) return i.Get();	}
/*		or*/if(j == index) return i.Get();
	return 0;									//if never found
}else throw LNI;}							//if there is no list //return 0;}


/*Overloads the [] operator,
 calls and has same functionality (and returns) as Find.
 so [] can be used without having to type Find;*/
template<typename T>
T* cLL<T>::operator[](int index){ if(Find(index)) return (Find(index))->m_data; else return false; }


/*Adds a list node w/ (data) after the (dptr) node,
and increments N_items respectively.
Takes two parameters| data (the data of cCell), and dptr (the ptr to the previous node).
References cCell class
Returns nothing.*/
template<typename T>
void cLL<T>::InsertAfter(T data, T* dptr)
{if(isEmpty()){
	++N_items;
	cNode<T>* temp = new cNode<T>(data);//Allocate and create a new cNode.
	temp->m_next = dptr->m_next;
	dptr->m_next->m_prev = temp;
	dptr->m_next = temp;				// /Move the new cNode 
	temp->m_prev = dptr;				// \pointer to the end.
}else throw LNI;}						//if there is no list //return 0;}


/*Adds a list node w/ (data) after the (dptr) node,
and increments N_items respectively.
Takes two parameters| data (the data of cCell), and dptr (the ptr to the previous node).
References cCell class
Returns nothing.*/
template<typename T>
void cLL<T>::InsertBefore(T data, T* dptr)
{if(isEmpty()){
	++N_items;
	cNode<T>* temp = new cNode<T>(data);//Allocate and create a new cNode.
	temp->m_prev = dptr->m_prev;
	dptr->m_prev->m_next = temp;
	dptr->m_prev = temp;				// /Move the new cNode 
	temp->m_next = dptr;				// \pointer to the end.
}else throw LNI;}						//if there is no list //return 0;}


/*Adds a list node w/ (data) before the (dptr) node,
and increments N_items respectively.
Takes two parameters| data (the data of cCell), and dptr (the ptr to the next node).
References cCell class
Returns nothing.*/
template<typename T>
cNode<T>* cLL<T>::Extract(cNode<T>* nptr, bool del = false)
{	 if(nptr == m_head) m_head = nptr->m_next;	//If at m_head update
else if(nptr == m_tail) m_tail = nptr->m_prev;	//If at m_tail update
	nptr->m_next->m_prev = nptr->m_prev;		//Move m_next
	nptr->m_prev->m_next = nptr->m_next;		//Move m_prev
	--N_items;									//update N_items
	if(del){
			cNode<T>* temp = nptr->m_next;		//? Used for Purge
			nptr->m_data->~cCell();				//? Deletes cCell
			nptr->~cNode();						//? Deletes cNode
			return temp;		 				//Used for Purge
	}/*els*/return nptr;						//Required
}

/*Deletes all list elements.
Deletes cLL, Node, & cCell data,
what cannot be deleted is assinged to 0
returns nothing.*/
template<typename T>
void cLL<T>::Purge()
{	cNode<T>* nptr = m_head;
	do{ nptr = Extract( nptr, true );	//Call extract with delete key.
		}while( nptr != m_head );		//While not at end.
	m_head = 0;
	m_tail = 0;
}

/*The destructor
Calls Purge.*/
template<typename T>
cLL<T>::~cLL(){ Purge(); }

bool operator==(sub &d1, sub &d2)		{ return (d1.name == d2.name); }//won't link else where
bool operator==(sub &d1, string &s2)	{ return (d1.name == s2)	 ; }//won't link else where

#endif