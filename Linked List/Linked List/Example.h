#include<iostream>

#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T> 
class List;

template <typename T>
class ListNode //nodes to be contained with a list
{
	friend class List<T>;

public:
	ListNode(T);
	T getData();

private:
	T data; //templatized data stored in node
	ListNode* nextPtr; //pointer to the next node in list
};

template <typename T>
ListNode<T>::ListNode(T dataIn)
{
	data = dataIn; //stores data in node
	nextPtr = 0; //initializes point to next node to null
}

template <typename T>
T ListNode<T>::getData() //returns data stored in node
{
	return data;
}

#endif

/*-----------------------------------------------------------------------------------------------------------*/

#ifndef LIST_H
#define LIST_H

//#include <iostream>
using namespace std;

//#include "ListNode.h"

template <typename T>
class List //linked list of ListNode objects
{
public:
	List();
	~List();
	void insertNewNode(T); //fucntion used to insert new node in order in the list
	void print(); //prints the contents of the linked list
	ListNode<T>* search(T);//search for a valU in la linked list & returns le point to object that has sed valU

private:
	ListNode<T> *startPtr; //stores the pointer of first object in the linked list
	ListNode<T> *endPtr; //stored the pointer of the last object in the linked list
	bool isEmpty(); //utility functions used to see if the list contains no elements
	void insertBegin(T); //inserts new node before the first node in the list
	void insertEnd(T); //inserts new node after the last node in the list
};



template <typename T>
List<T>::List() //creates list with start and end as NULL
{
	startPtr = NULL;
	endPtr = NULL;
}

template <typename T>
List<T>::~List()
{
	if ( !isEmpty() ) // List is not empty
   {    
      ListNode<T> *currentPtr = startPtr;
      ListNode<T> *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
      {  
         tempPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }
   }
}

template <typename T>
bool List<T>::isEmpty()//if the start and end pointer are NULL then the list is empty
{	if(startPtr == NULL && endPtr == NULL) return 1;
	else return 0;										}

template <typename T>
void List<T>::insertBegin(T dataIn)
{
	if(isEmpty()) //if the list is empty create first element of the list
	{
		ListNode<T> * newPtr = new ListNode<T>(dataIn); //creates new node
		startPtr = newPtr; //start and end pointer are same becuase there is only one object in list
		endPtr = newPtr;
	}

	else //if node(s) exist in list insert additional object before the first
	{	
		ListNode<T> * newPtr = new ListNode<T>(dataIn);
		newPtr->nextPtr = startPtr;	//the new node's next pointer points to the formerly first node
		startPtr = newPtr;			//the pointer for the new node is now the starting node
	}
}

template <typename T>
void List<T>::insertEnd(T dataIn)
{
	if(isEmpty())
	{//if the list is empty create first element of the list (same as first case in insert at begin)
		ListNode<T> * newPtr = new ListNode<T>(dataIn);
		startPtr = newPtr;
		endPtr = newPtr;
	}
	
	else 
	{//if node(s) exist in the list then insert new node at the end of the list
		ListNode<T> * newPtr = new ListNode<T>(dataIn);
		endPtr->nextPtr = newPtr;//the current last node's next pointer points to the new node
		endPtr = newPtr;		//the new node is now the last node in the list
	}
}

template <typename T>
void List<T>::insertNewNode(T dataIn) //general funtionn to insert new node the proper order in the list
{
	if(isEmpty()){	insertBegin(dataIn);	}
	//if there is no nodes in the list simply insert at beginning

	else 
	{	if(dataIn < startPtr->data)		{	insertBegin(dataIn);}
		//if the data of the new object is less than than the data of first node in list insert at beginning
	
		else if(dataIn >= endPtr->data) {	insertEnd(dataIn);	}
		//if the data of the new object is greater than than the data of last node in list insert at end
		
		else //the new node is being inserted in order but not at the beginning or end
		{
			ListNode<T> * currentPtr = startPtr;
			ListNode<T> * newPtr = new ListNode<T>(dataIn); //creates new node
			while(currentPtr != endPtr) //runs until the end of the list is reached
			{
				if((newPtr->data < currentPtr->nextPtr->data) && (newPtr->data >= currentPtr->data)) 
				{//if new_node-data is < next_node-data && > current_node-data, insert after current node
					ListNode<T> * next = currentPtr->nextPtr; 
					currentPtr->nextPtr = newPtr; //current nodes next pointer now points to the new node
					newPtr->nextPtr = next;//the new node's next* now points after the former current node
					//At least I think that's what he meant to say.
					break;
				}
				currentPtr = currentPtr->nextPtr; //moves to the next node in the list
			}
		}
	}
}

template <typename T>
void List<T>::print()
{
	if(isEmpty())
	{	cout << "The list is empty" << endl;	}
	else
	{	ListNode<T> * currentPtr = startPtr;

		cout << "The contents of the list is: ";
		while(currentPtr != NULL) //prints until the end of the list is reached
		{
			cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr; //moves to next node in list
		}
		cout << endl;
	}
}

template <typename T>
ListNode<T>* List<T>::search(T key)
{//search functions that searches for node that contains data equal to the key
	ListNode<T>* nodePtr;
	bool found = false;

	nodePtr = startPtr;

	while((!found) && (nodePtr != NULL))	
	{//runs through list until data is found within a node or end of list is reached
		if(nodePtr->data == key)	found = true;
		//if the node's data equals the key then the node has been found
		
		else	nodePtr = nodePtr->nextPtr;
		//moves to next node in list
	}
	return nodePtr; //returns pointer to the node that contains data equal to key (NULL if not found)
}
#endif

/*___________________________________________________________________________________________________________*/
/*-----------------------------------------------------------------------------------------------------------*/

#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T> 
class Tree;

template <typename T>
class TreeNode
{
	friend class Tree<T>;

public:
	TreeNode(T); 
	T getData(); //returns data stored in node

private:
	T data;
	TreeNode* leftPtr; //pointer to left child node of node
	TreeNode* rightPtr; //pointer to right child node of node
};

template <typename T>
TreeNode<T>::TreeNode(T dataIn)
{
	data = dataIn;
	leftPtr = 0; //pointer to left and right child nodes are initilized to NULL
	rightPtr = 0;
}

template <typename T>
T TreeNode<T>::getData()
{
	return data;
}

#endif

/*-----------------------------------------------------------------------------------------------------------*/

#ifndef TREE_H
#define TREE_H

//#include <iostream>
//using namespace std;

//#include "TreeNode.h"

template <typename T>
class Tree
{
public:
	Tree();
	void insertNewNode(T); //inserts new node in the tree
	void preOrderPrint(); //prints out tree in the order in which it was entered
	void inOrderPrint(); //prints out tree in accending order
	void postOrderPrint(); //prints out the tree after the order
	TreeNode<T>* search(T); //search for node thats data = the search key and returns the pointer to that node.

private:
	TreeNode<T> *rootPtr;
	bool isEmpty();

	//utility functions to make the insert, print, and search functions more understandable
	void  insertNewNodeUtility(TreeNode<T>**,T);
	void  preOrderPrintUtility(TreeNode<T>*   );
	void   inOrderPrintUtility(TreeNode<T>*   );
	void postOrderPrintUtility(TreeNode<T>*   );
	TreeNode<T>* searchUtility(TreeNode<T>* ,T);
};

template <typename T>
Tree<T>::Tree()
{
	rootPtr = 0;
}

template <typename T>
void Tree<T>::insertNewNode(T dataIn)
{//Calls insert new node function passing refernce of the root node and the data to be inserted in the new node.
	insertNewNodeUtility(&rootPtr, dataIn);
}

template <typename T>
void Tree<T>::insertNewNodeUtility(TreeNode<T>** temp, T dataIn)
{
	if(*temp == 0) //if node is null create a new node with input data
		*temp = new TreeNode<T>(dataIn);
	else
	{
		if(dataIn < (*temp)->data) //if input data is less than data in current node
			insertNewNodeUtility(&((*temp)->leftPtr),dataIn); //recursive function call with current node's left child as input leaf
		else 
		{
			if(dataIn > (*temp)->data) //if input data is greater than data in current node
				insertNewNodeUtility(&((*temp)->rightPtr),dataIn); //recursive function call with current node's right child as input leaf
			else //if input data is equal to data in current node
				cout << dataIn << " is a duplicate value " << endl; //duplicate values ignored
		}
	}
}

template <typename T>
void Tree<T>::preOrderPrint()
{
	preOrderPrintUtility(rootPtr); 
}

template <typename T>
void Tree<T>::preOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		cout << temp->data << ' '; //process node
		preOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		preOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
	}
}


template <typename T>
void Tree<T>::inOrderPrint()
{
	inOrderPrintUtility(rootPtr);
}

template <typename T>
void Tree<T>::inOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		inOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		cout << temp->data << ' '; //process node
		inOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
	}
}


template <typename T>
void Tree<T>::postOrderPrint()
{
	postOrderPrintUtility(rootPtr);
}

template <typename T>
void Tree<T>::postOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		postOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		postOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
		cout << temp->data << ' '; //process node
	}
}

template <typename T>
TreeNode<T>* Tree<T>::search(T key)
{
	return searchUtility(rootPtr, key);
}

template <typename T>
TreeNode<T>* Tree<T>::searchUtility(TreeNode<T>* leaf, T key)
{
	if(leaf != NULL)
	{
		if(key == leaf->data)
			return leaf;
		if(key < leaf->data)
			return searchUtility(leaf->leftPtr, key);
		else
			return searchUtility(leaf->rightPtr, key);
	}
	else
		return NULL;
}
#endif 

/*___________________________________________________________________________________________________________*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//#include <iostream>
#include <ctime>

//#include "List.h"
//#include "ListNode.h"
//#include "Tree.h"
//#include "TreeNode.h"

//using namespace std;

int main()
{
	int choice = 0;

	//create function array of 10 random numbers between 0 and 100
	const int size = 10;
	int arr[size];
	srand(time(0)); //time is used as the random seed
	for(int i = 0; i <= size-1;  i++)
	{
		arr<i> = rand() % 101; //assigns random number in array
	}

	List<int> intList; //creates order linked list
	for(int i = 0; i <= size-1;  i++)
	{
		intList.insertNewNode(arr<i>); //inserts value from array to the linked list in the proper positions
	}

	Tree<int> intTree; //create binary tree
	for(int i = 0; i <= size-1;  i++)
	{
		intTree.insertNewNode(arr<i>); //inserts value from array to the binry tree in the same order entered
	}

	while (choice != 7)
	{
		//displays initial array of values
		cout << "Initial Array of Values" << endl;
		cout << "-----------------------" << endl;
		for(int i = 0; i <= size-1;  i++)
		{
			cout << arr<i> << ' ';
		}
		cout << endl << endl;

		//menu of options to perform 
		cout << "Linked Lists and Trees" << endl;
		cout << "-----------------------" << endl;
		cout << "1. Print Linked List" << endl;
		cout << "2. Search For Entry In Linked List" << endl;
		cout << "3. Print Pre-Ordered Traverseal of Tree" << endl;
		cout << "4. Print In-Order Traversal of Tree" << endl;
		cout << "5. Print Post-Order Traversal of Tree" << endl;
		cout << "6. Search For Entry In Tree" << endl;
		cout << "7. EXIT" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		system("cls");

		int key; //search key used for both the search of linked list and binary tree
		
		ListNode<int>* posList; //node pointer used to store a pointer to node returned from the linked list search function

		TreeNode<int>* posTree; //node pointer used to store a pointer to node returned from the binary tree search function

		switch(choice)
		{
		case 1:
			cout << "Output of a Sorted Linked List" << endl;
			cout << "------------------------------" << endl;
			intList.print(); //prints contents of linked list
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Searching In a Linked List" << endl;
			cout << "--------------------------" << endl;
			//prompt for search key
			cout << "Enter a a search key: ";
			cin >> key;
			posList = intList.search(key); //stores pointer to list node object
			cout << "The value of pointer is " << posList << endl;
			if(posList != NULL) //if not null then the value was found
				cout << "The value stored at this posistion is " << posList->getData() << endl;
			else
				cout << "The pointer to this position is NULL so there can be no value stored" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Pre-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			intTree.preOrderPrint(); //print pre ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "In-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			intTree.inOrderPrint(); //print in ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Post-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			intTree.postOrderPrint(); //print post ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Searching In a Tree" << endl;
			cout << "-------------------" << endl;
			//prompt for search key
			cout << "Enter a a search key: ";
			cin >> key;
			posTree = intTree.search(key); //stores pointer to tree node object
			cout << "The value of pointer is " << posTree << endl;
			if(posTree != NULL) //if not null then the value was found
				cout << "The value stored at this posistion is " << posTree->getData() << endl;
			else
				cout << "The pointer to this position is NULL so there can be no value stored" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Thanks for using my test program for Linked Lists and Trees" << endl;
			system("pause");
			system("cls");

		}
	}
}