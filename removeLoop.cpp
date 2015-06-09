#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
void detectRemove(Node *);
int getLoopLen(Node *);
Node *getLoopNode(Node *);

int main(){

		Node *head = NULL;
		
		
	//	add_node(&head,7);
		add_node(&head,44);
	//	add_node(&head,11);
		
		//add_node(&head,5);
		//add_node(&head,10);
		add_node(&head,12);
		add_node(&head,6);
		add_node(&head,4);
		add_node(&head,2);
		add_node(&head,0);
		
		head->next->next->next->next->next = head->next->next;
		
		detectRemove(head);
		print(head);	

		return 0;
}

void print(Node *head){

		Node *temp = head;
		Node **temp_ref = &temp;
		
		while(temp!=NULL){
			cout<<temp->value<<" ";
			temp = temp->next;
		}
		cout<<endl;
}

void add_node(Node **head_ref, int value){

	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;

}



Node *getLoopNode(Node *head){

	Node *slow_ptr = head, *fast_ptr=head;

	while(fast_ptr->next!=NULL && slow_ptr!=NULL){
		
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if(slow_ptr == fast_ptr)
			return slow_ptr;
	}

	return NULL;
}

int getLoopLen(Node *loopNode){

	Node *slw=loopNode, *fst = loopNode;
	int len = 0;

	while(fst->next!=NULL && slw!=NULL){

		slw = slw->next;
		fst = fst->next->next;
		len++;

		if(slw == fst)
			break;
	}

	return len;
}
void detectRemove(Node *head){

	Node *ptr1=head, *ptr2=head;;
	Node *loopNode = getLoopNode(head);
	int loopLength = 0;;

	if(loopNode == NULL && head == NULL)
	{
		cout<<"NO LOOP\n";
		return;
	}

	loopLength = getLoopLen(loopNode);
	int i =0;

	for(i =0; i<loopLength; i++){

		ptr2 = ptr2->next;	
	}

	while(ptr2->next!=NULL)
	{
		if(ptr1->next == ptr2->next)
			break;

		cout<<"WE did it"<<endl;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	ptr2->next = NULL;
}

