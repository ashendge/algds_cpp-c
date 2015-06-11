#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;
};

void add_node(Node **, int );
void print(Node *);
void rotate(Node **, int );


int main(){

	Node *head = NULL;
	add_node(&head, 60);
	add_node(&head, 50);
	add_node(&head, 40);
	add_node(&head, 30);
	add_node(&head, 20);
	add_node(&head, 10);
	print(head);
	rotate(&head,4);
	print(head);
	return 0;
}


void add_node(Node **head_ref, int value){

	Node *new_node = new Node;

	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;

}

void print(Node *head){
	Node *temp = head;
	while(temp){
		cout<<" "<<temp->value;
		temp = temp->next;
	}
	cout<<endl;
}

void rotate(Node **head_ref, int k){

		int count = 1;
		Node *temp = *head_ref;

		while(count < k){
			temp = temp->next;
			count++;
		}
		
		Node *pivot = temp; // store the first half end
		temp = pivot->next;
		Node *rotate = temp; // store the second half starting
		pivot->next = NULL;

		while(temp->next!=NULL)
			temp = temp->next;
				
		// Link the pointers
		
		temp->next = *head_ref;
		*head_ref = rotate; 

		// This step sort of takes the cake. 
		//Important to change the head to the ew pointer [rotate  pointer in this case to be specific]

}



