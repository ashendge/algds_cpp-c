#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;
	Node *prev;
};
void add_node(Node **, int );
void print(Node *);
void add_middle(Node *,int );
void before_add(Node *, int );
int main(){

	Node *head = NULL;
	
	add_node(&head,77);
	add_node(&head,66);
	add_node(&head,55);
	print(head);
//	add_middle(head->next->next,88);
	before_add(head,120);
	print(head);
}
void add_node(Node **head_ref, int value){

	Node *new_node = new Node;
	new_node->value = value;

	new_node->next = *head_ref;
	new_node->prev = NULL;
	if(*head_ref!=NULL)
		(*head_ref)->prev = new_node;

	*head_ref = new_node;
}
void print(Node *head){	

	Node *temp = head;
	while(temp!=NULL){
		cout<<" "<<temp->value;
		temp = temp->next;
	}
	cout<<"\n";
}

void add_middle(Node *given, int value){
	Node *new_node = new Node;
	new_node->value = value;
	if(given->next!=NULL){
		Node *temp=NULL;	
		temp = given->next;
		temp->prev = new_node;
		given->next = new_node;
		new_node->next = temp;
		new_node->prev = given;
	}
	else{
		new_node->next = given->next;
		given->next = new_node;
		new_node->prev = given;
	}

}

void before_add(Node *given, int value){

	Node *new_node = new Node;
	new_node->value = value;
	if(given->prev != NULL){
		Node *temp = NULL;
		temp = given->prev;
		temp->next = new_node;
		given->prev = new_node;
		new_node->next = given;
		new_node->prev = temp;
	}
	else{
		cout<<"yays\n";

		Node **head_ref = &given;
		new_node->prev = given->prev;
		given->prev = new_node;
		new_node->next = given;
		head_ref = &(given->prev);
	}


}