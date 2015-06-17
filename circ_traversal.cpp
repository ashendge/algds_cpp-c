#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
};

void add_node(Node **,int value);
void print(Node *);

int main(){

	Node *head = NULL;
	add_node(&head,22);
	add_node(&head,44);
	add_node(&head,55);
	add_node(&head,66);
	print(head);

}

void add_node(Node **head_ref,int value){

	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = *head_ref;
	Node *temp = *head_ref;
	if(*head_ref!=NULL){
		while(temp->next!=*head_ref)
			temp = temp->next;

		temp->next = new_node;
	}
	else
		new_node->next = new_node;

	*head_ref = new_node;

}
void print(Node *head){
	Node *temp = head;

	do{	
		cout<<" "<<temp->value;
		temp = temp->next;
	}while(temp!=head);

	cout<<endl;
		
	

}