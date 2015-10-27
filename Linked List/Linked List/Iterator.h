#ifndef ITERATOR
#define ITERATOR

#include "Node.h"

template<typename T>
class Iterator
{public:
				 Iterator (){}
				 Iterator (Iterator*p) : m_node(p->m_node){}
				 Iterator (cNode<T>* p) : m_node(p		 ){}
	Iterator&	operator= (Iterator other)	{ m_node = other.m_node;return *this;}
	Iterator&	operator= (cNode<T>* other)	{ m_node = other;		return *this;}
	cNode<T> 	operator* ()				{ return *m_node; }
	cNode<T>*	Get()						{ return  m_node; }

	Iterator	operator++()
				{	m_node = m_node->m_next;			return *this;	}

	Iterator	operator++(int)
				{	Iterator temp(m_node);	++(*this);	return temp;	}

	Iterator	operator--()
				{	m_node = m_node->m_prev;			return *this;	}

	Iterator	operator--(int)
				{	Iterator temp(m_node);	--(*this);	return temp;	}
	
	bool	operator==(Iterator other){ return (m_node == other.m_node); }
//	bool	operator==(cNode<T>* other){ return (m_node == other)	   ; }

	bool	operator!=(Iterator other){ return (m_node != other.m_node); }
//	bool	operator!=(cNode<T>* other){ return (m_node != other		  ); }

				~Iterator (){}

private:
	cNode<T>* m_node;
};

#endif