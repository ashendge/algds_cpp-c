#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
};
void add_node(Node **, int );
void print(Node *);
void add_sorted(Node **head_ref,int );
int main(){

	Node *head = NULL;

		add_node(&head,99);
		add_node(&head,10);
		add_node(&head,8);
		add_node(&head,3);
		add_node(&head,2);
		print(head);
		add_sorted(&head,105);
		print(head);

}

void add_node(Node **head_ref, int value){

	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = *head_ref;
	Node *temp = *head_ref;

	if(*head_ref != NULL){
	while(temp->next != *head_ref)
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
		cout<<" "<< temp->value;
		temp = temp->next;
	}while(temp !=head);
	cout<<"\n";

}

void add_sorted(Node **head_ref, int newVal){

	Node *new_node = new Node;
	new_node->value = newVal;
	Node *temp = *head_ref;
	Node *prev;
	if((*head_ref)->value >= newVal){
		
		while(temp->next != *head_ref)
			temp = temp->next;
		new_node->next = *head_ref;
		temp->next = new_node;
		*head_ref = new_node;	
	}
	else{
		prev = temp;
		temp = temp->next;

		while(temp != *head_ref){
			


			if(temp->value < newVal){
				temp = temp->next;
				prev = prev->next;
			}
		
				else{
				new_node->next = temp;
				prev->next = new_node;
				break;
			}

		}
		if(temp == *head_ref){
				new_node->next = temp;
				prev->next = new_node;
				cout<<"Test "<<(new_node->next)->value<<endl;
			}

	}
}