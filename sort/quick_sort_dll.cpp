#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
	Node *prev;
};


/*Damn you swap!!!*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}
	
Node *partition(Node *first, Node *last){
	
	/*
	 Similar logic to the array implementation
	 Just the change in how i++ is done here

	 If i== NULL, is assigned jth i.e first value
	 else i= i->next or i++;
	 Be careful there
	*/

	int	pivot = last->value;

	Node *i = first->prev;
		
	for(Node *j = first; j!= last; j = j->next){

		if(j->value <= pivot){
			i = (i==NULL) ? first:i->next; // Important ? operator ternary 
			swap(&(i->value), &(j->value));
		}
	}
	i = (i == NULL) ? first : i->next;
	swap(&(i->value),&(last->value));
	return i;
}
				
void push(Node **head_ref, int value){

	Node *new_node = new Node;
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = *head_ref;

	if(*head_ref!=NULL)
		(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
	
void print(Node *head){
	Node *temp = head;
	
	while(temp!=NULL){
	cout<<temp->value<<" ";
	temp = temp->next;
	}
	cout<<endl;
}
Node *getLastNode(Node *first){
	Node *temp = first;
	while(temp->next != NULL)
		temp = temp->next;
	return temp;
}

void _quick_sort(Node *first, Node *last){
	/*
		It is an important condition->
		This ensures that last is not null and it index is smaller than jth.
	*/
	if(last != NULL && first!=last && first != last->next){
		Node *pivot_ptr = partition(first,last);
		_quick_sort(first,pivot_ptr->prev);
		_quick_sort(pivot_ptr->next,last);
	}
}
/*Wraper function just to ensure that last element can be sent as
  argument to _quick_sort(Node *first, Node *last)
*/
void quick_sort(Node *head_ref){	

	Node *first = head_ref;
	Node *last = getLastNode(first);

	_quick_sort(first,last);
}

int main(){

	Node *head = NULL;
	push(&head,18);
	push(&head,6);
	push(&head,1);
	push(&head,10);
	push(&head,2);
	push(&head,33);
	push(&head,4);
	cout<<"Original order:\n";
	print(head);
	cout<<endl;
	quick_sort(head);
	cout<<"Sorted order:\n";
	print(head);
	cout<<endl;
}