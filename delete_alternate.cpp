#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void delete_alternate(Node *);
void add_node(Node **, int );
void print(Node *head);
void delete_alt_rec(Node *);
int main(){

		Node *head = NULL;
		//add_node(&head,5);
		add_node(&head,4);
		add_node(&head,3);
		add_node(&head,2);
		add_node(&head,1);
		print(head);
		//delete_alternate(head);
		delete_alt_rec(head);

		print(head);

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

void add_node(Node **head_ref, int value){

	Node *new_node = new Node;

	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;

}

void delete_alternate(Node *head){

	Node *Next;
	Node *temp;
	if(head == NULL)
		return;

	if(head->next== NULL){
		cout<<"There is only one node in the linked list";
			return;
	}

	Next = temp =head;

	while(Next!=NULL && Next->next!=NULL){

			Next = temp->next;
			temp->next = Next->next;
			cout<<"*Node deleleted* "<<Next->value<<endl;	
			delete Next;
			temp = temp->next;
			Next = temp;
	}

}

void delete_alt_rec(Node *head){

		if(head->next == NULL || head == NULL)
			return;
		Node *temp = head->next;
		head->next = temp->next;
		cout<<"*Node deleleted* "<<temp->value<<endl;	
		delete temp;
			if(head->next == NULL)
				return;
		delete_alt_rec(head->next);	

}