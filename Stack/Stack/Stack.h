#ifndef STACK
#define STACK

#include "stdafx.h"

template<typename T>
class cStack
{public:
			cStack(unsigned size = MSIZE) : m_length(size){}
			cStack(cStack* prime);
	cStack<T>& operator=(const cStack<T>& rhs);
		   ~cStack();
	void	Push(T para);
	T		Pull();
	T		Peek();
	int		Size();
	bool	Is_empty();
	bool	Is_full();
private:
	cLL<T> stack;
	unsigned m_length;
};


TP cStack<T>::cStack(cStack* prime)/*Copy Constructor, takes another stack, and creates a deep copy*/
		{ for(int i = prime->stack.N_items;  i != 0; i--) stack.Preppend( (prime->stack)[i] ); }

TP cStack<T>& cStack<T>::operator=(const cStack<T>& rhs)/*Copies all data from one stack to another,
as such requires two existing stacks as inputs*/{ stack = rhs.stack; m_length = rhs.m_length; }

/*Destructor, no inputs, deallocation of stack occurs at exit
*/TP		cStack<T>::~cStack()	{}
		  
/*Adds one /item/ on to the stack takes
  an <item type> as a parameter
*/TP void	cStack<T>:: Push(T para){ if(!Is_full ()) stack.Preppend(para); }

/*if not empty, take and return
  an /item/ off the stack
*/TP T		cStack<T>::	Pull()		{ if(!Is_empty()) return stack.Extract(stack.Find(0))->Get_data(); ORNOT; }

/*returns, but does not remove an
  /item/ from the stack, no inputs
*/TP T		cStack<T>::	Peek()		{ if(!Is_empty()) return *stack[0]; ORNOT; }
			  
/*(Getter) returns the size
  of the stack, no inputs
*/TP int	cStack<T>::	Size()		{ return stack.Get_size(); }
			  
/*returns a true if the stack is empty
  or false if not, no other inputs
*/TP bool	cStack<T>::	Is_empty()	{ return (stack.Is_empty()); }

/*returns a true if the stack is full
  or false if not, no other inputs
*/TP bool	cStack<T>::	Is_full()	{ return (stack.Get_size()+1 > m_length); }


#endif