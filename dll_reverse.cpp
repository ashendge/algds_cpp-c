#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
	Node *prev;
};

void add_node(Node **,int );
void print(Node *);
void reverse(Node **);
int main(){

	Node *head = NULL;

	add_node(&head,11);
	/*add_node(&head,22);
	add_node(&head,33);
	add_node(&head,44);
	add_node(&head,55);
	*/
	print(head);
	reverse(&head);
	print(head);
}

void add_node(Node **head_ref,int value){
	Node *new_node = new Node;
	new_node->value = value;

	new_node->next = *head_ref;
	new_node->prev = NULL;
	if(*head_ref != NULL)
		(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
/* Print DLL*/
void print(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void reverse(Node **head_ref){

	Node *current = *head_ref, *temp;

	if(current == NULL || current->next == NULL)
		return;

	while(current!=NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;

	}
	/*This step ensures that the head is pointing to the app
	-ropriate node [the last or the new first node]*/
	
	//if(temp!=NULL)
		*head_ref = temp->prev;
}