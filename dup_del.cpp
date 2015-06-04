#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int value;
	Node *next;

};
void add_node(Node **, int  );
void print(Node *);
void delete_duplicate(Node *);

int main(){


	Node *head = NULL;
	
	
	add_node(&head,30);
	add_node(&head,30);
	
	add_node(&head,9);
	add_node(&head,6);
	add_node(&head,6);
	add_node(&head,3);
		
	print(head);
	
	delete_duplicate(head);
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

void delete_duplicate(Node *head){

		if(head==NULL || head->next == NULL)
			return;

		Node *temp1 = head, *temp2 = head->next;

		while(temp2!=NULL){

			if(temp1->value == temp2->value){
				Node *temp3 = temp2->next;
				temp1->next = temp3;
				cout<<temp2->value<<" DEL\n";
				delete temp2;
				temp2 = temp3;
			}

			else{
				temp1 = temp2;
				temp2 = temp2->next;
			}
		}

}