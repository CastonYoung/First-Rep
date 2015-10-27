//#define CAST(x) reinterpret_cast< x >

#define CAST(x, y) *(reinterpret_cast< x* >(& y))

#define MSIZE 15 //Max size of the stack.
#define ORNOT else return false
#define TP template<typename T> \

#ifndef STDAFX
#define STDAFX

//#include "Exceptions.h"
#include <iostream>
#include "Iterator.h"
#include "Node.h"
#include "Stack.h"
#include "Linked_List.h"




#endif