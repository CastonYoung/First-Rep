#define STRING string//find_
#define RCAST(x) reinterpret_cast<x>

using namespace std;

template<typename T/*, typename find_*/>
		class LL;

template<typename T>
		class node;

//class Cell;

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
	LL(){	head = 0;	tail = 0;	N_items = 0;}//-----Constructor


	void Add(T data)//----------------------------------Adds a new City
	{	++N_items;
		node<T>* temp = new node<T>(data);//		<-Allocate and create a new node.
		if (head == 0) { head = temp; }//			<-If first list item, set head and tail to itself.
		else{ tail->m_next = temp;
			  temp->m_prev = tail; }//				<-Move the tail pointer to the end.
		tail = temp;//								<-Move tail to the end
		temp->m_next = head;//						<-Reattach tail to head
		head->m_prev = tail;
	}


#ifdef CELL_ID
	node<T>* Find(STRING tag)//--------------------Returns a specific node
	{if(head != 0){
		int checks(0);
		node<T>* ptr = head;						//create a pointer to continually check against
		do{
			if(ptr->m_data->cell_ID == tag)return ptr;	//if found
			ptr = ptr->m_next;							//if not yet found
		}while(ptr != head);							   //if all checked
		return 0;									//if never found
	}else return 0;}							//if there is no list

	T* operator[](STRING index){ return (Find(index))->m_data; }
#endif

	node<T>* Find(int index)//--------------------Returns a specific node
	{if(head != 0){
		int check(0);
		node<T>* ptr = head;						//create a pointer to continually check against
		do{
			if (check++ == index) return ptr;			//if found
			ptr = ptr->m_next;							//if not yet found
		}while(ptr != head)							   //if all checked
		return 0;									//if never found
	}else return 0;}							//if there is no list

	T* operator[](int index){ return (Find(index))->m_data; }


	void Deleet(node<T>* ptr)//--------------------------Deletes a Cell.
	{	node<T>* temp = ptr->m_next;			//Saves address before disconnection
		ptr->m_data->~Cell();					//Deletes Cell
		if(ptr == head) head = ptr->m_next;		//If at head update
   else if(ptr == tail) tail = ptr->m_prev;		//If at tail update
		ptr = ptr->m_next;						//Move m_next
		ptr->m_prev = temp->m_prev;				//Move m_prev
		temp->~node();							//Delete node.
		N_items--;
	}


	//void printList();


	//Iterator Begin(){ return Iterator(head); }


private: 
	int N_items;
	node<T>* head; node<T>* tail;
};


/*
class Iterator
{public:
			 Iterator (node<int>* P) : m_node(P)
				{}
Iterator&	operator= (Iterator other){ m_node = other.m_node; }
   node<int>operator* (){return*m_node; 		}
	bool	operator++(){return m_node.next;	}
	bool	operator--(){return m_node.previous;}
	bool	operator==(Iterator other){ return (m_node == other.m_node); }
			~Iterator (){}
private:
	node<int>* m_node;
}

void iter(){
	for(Iterator i=(List.Begin()); i != tail; i++)
	{	
	}
}*/