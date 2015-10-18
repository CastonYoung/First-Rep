#ifdef NOT

void Prepend(){
	Node Nn;
	if(head!=0) Nn.next = head;
	else {head = Nn; tail = Nn;}
}

void Purge(){
	Node* to_delete = head;
	while(to_delete.next != 0)
	{	Node* Nn = to_delete.next;
		delete to_delete;
		to_delete = NN;
	}delete to_delete;
}

void Example()
{	Iterator i;
	for(i = List.begin(); i <= List.end(); i++)
	{
	}
}



void Extract(){//Delete node
}
#endif

