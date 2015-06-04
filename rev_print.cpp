#include <iostream>
#include <cmath>
using namespace std;

struct Node{
	int value;
	Node *next;

};
void add_node(Node **, int  );
void print(Node *);
Node *rev_print(Node *);

int main(){


	Node *head = NULL;
	
	
	add_node(&head,30);
	add_node(&head,15);
	add_node(&head,9);
	add_node(&head,6);
	add_node(&head,3);
	print(head);
	rev_print(head);	
	cout<<endl;

	cout<<head->value;
	cout<<endl;	
	return 0;
}

void print(Node *head){

	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->value<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

Node *rev_print(Node *head){

		Node *temp = head;
		if(head == NULL)
			return NULL;
		rev_print(head->next);
		cout<<head->value<<" ";
}
void add_node(Node **head_ref, int value){
		
		Node *new_node = new Node;
		new_node->value = value;
		new_node->next = *head_ref;
		*head_ref = new_node;

}
