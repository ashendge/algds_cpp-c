#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int value;
	Node *next;

};
void add_node(Node **, int  );
void print(Node *);
void swap(Node *);

int main(){


	Node *head = NULL;
	
	add_node(&head,50);	
	add_node(&head,30);
	add_node(&head,9);
	add_node(&head,6);
	add_node(&head,5);
	add_node(&head,3);
		
	print(head);
	swap(head);	
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


void swap(Node *head){


		Node *temp = head;
		
		while(temp->next != NULL && temp!=NULL){


			int x = temp->value;
			temp->value = temp->next->value;
		    temp->next->value = x;
		    temp = temp->next->next;

		    if(temp== NULL)
		    	return;
		}

}

void swap_recursive(Node *head){
		if(head == NULL)
			return;

		
		

}