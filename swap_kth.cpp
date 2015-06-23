#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;
};
/*Known Bug in the program
for input k=n ; n being the last element of the linked list, the program seg faults
*/

void add_node(Node **,int value);
void print(Node *);
void swap(Node **head_ref,int k);
int main(){

	Node *head = NULL;	
	
	add_node(&head,8);
	add_node(&head,7);
	add_node(&head,6);
	add_node(&head,5);
	add_node(&head,4);
	add_node(&head,3);
	add_node(&head,2);
	add_node(&head,1);
	print(head);
	swap(&head,7);
	print(head);

}
void add_node(Node **head_ref,int value){
	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
	void print(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}
void swap(Node **head_ref, int k){

	int count = 1;
	Node *front = *head_ref;
	Node *back = *head_ref;
	Node *prev_f = NULL;
	Node *prev_b = NULL;
	Node *fast = NULL;

	/*Case1 : Where Head and the last element are to be swapped*/
	if(k==1){

		Node *temp = *head_ref;
		Node *prev = NULL;
		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
		}
		
		temp->next = (*head_ref)->next;
		prev->next = *head_ref;
		*head_ref = temp;
		 prev->next->next = NULL;
		return;
	}
	/*Fixing the prev abd front back pointer*/
	while(count != k){
		prev_f = front; // ptr 1
		front = front->next; // ptr 2
		count++;		
	}	
	
	//cout<<"Front ="<<front->value<<" Prev of Front="<<prev_f->value<<endl;
	fast = front;

	while(fast->next!=NULL){
		prev_b = back;  // ptr 3
		back = back->next; // ptr 4
		fast = fast->next;
		count++;
	}

	//cout<<"Back ="<<back->value<<" Prev of Back="<<prev_b->value<<endl;
	Node *temp1 = front->next;
	Node *temp2 = back->next;

	prev_f->next = back;
	prev_b->next = front;
	back->next = temp1;
	front->next = temp2;

/*
	cout<<"should be 6"<<prev_f->next->value;
	cout<<"\nShould be 3"<<prev_b->next->value;
*/


}