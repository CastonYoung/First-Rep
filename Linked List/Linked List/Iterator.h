#ifndef ITERATOR
#define ITERATOR

#include "Node.h"

/************************************************************************
* Class: cLL ("Linked List")
*
* Constructors:	
*	Iterator ()				//Default (not used, canonical)
*	Iterator (Iterator*p)	//Copy	  (not used in this program, canonical)
*	Iterator (cNode<T>*p)	//Parameterized, used to get the location of the node.
*
* Mutators/Methods:	//I don't really know what they should be considered
*	Iterator& operator= (Iterator  other)//Assignment overload, copies data from one ITERATOR to the other.
*	Iterator& operator= (cNode<T>* other)//Assignment overload, copies data from one NODE to the ITERATOR.
*
*	Iterator operator++()				//Overloads the ++operator.
*	Iterator operator++(int)			//Overloads the operator++.
*
*	Iterator operator--()				//Overloads the --operator.
*	Iterator operator--(int)			//Overloads the operator--.
*
* Methods:
*	cNode<T> 	operator* ()			//Overloads the operator*.
*	cNode<T>*	Get()					//Getter for <m_node>.
*	
*	bool	operator==(Iterator other)	//checks for   equality among Iterators.
*	bool	operator!=(Iterator other)	//checks for INequality among Iterators.
*
*	~Iterator ()	//destructor (canonical)
*
*************************************************************************/
template<typename T>
class Iterator
{public:
				 Iterator (){}								//Default (not used, canonical)
				 Iterator (Iterator*p) : m_node(p->m_node){}//Copy	  (not used in this program, canonical)
				 Iterator (cNode<T>* p) : m_node(p		 ){}//Parameterized, used to get the location of the node.

	Iterator&	operator= (Iterator other)	{ m_node = other.m_node;return *this;}
	//Assignment overload, copies data from one ITERATOR to the other.

	Iterator&	operator= (cNode<T>* other)	{ m_node = other;		return *this;}
	//Assignment overload, copies data from one NODE to the ITERATOR.
	
	cNode<T> 	operator* ()				{ return *m_node; }//Overloads the operator*.
	cNode<T>*	Get()						{ return  m_node; }//Getter for <m_node>.

	Iterator	operator++()//Overloads the ++operator.
				{	m_node = m_node->m_next;			return *this;	}

	Iterator	operator++(int)//Overloads the operator++.
				{	Iterator temp(m_node);	++(*this);	return temp;	}

	Iterator	operator--()//Overloads the --operator.
				{	m_node = m_node->m_prev;			return *this;	}

	Iterator	operator--(int)//Overloads the operator--.
				{	Iterator temp(m_node);	--(*this);	return temp;	}
	
	bool	operator==(Iterator other){ return (m_node == other.m_node); }//checks for   equality among Iterators.
//	bool	operator==(cNode<T>* other){ return (m_node == other)	   ; }

	bool	operator!=(Iterator other){ return (m_node != other.m_node); }//checks for INequality among Iterators.
//	bool	operator!=(cNode<T>* other){ return (m_node != other		  ); }

				~Iterator (){}

private:
	cNode<T>* m_node;
};

#endif