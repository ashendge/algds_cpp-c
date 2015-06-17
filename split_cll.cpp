#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;
};

void add_node(Node **, int );
void print(Node *);
void split(Node *head,Node **head1_ref,Node **head2_ref);

int main(){

		Node *head = NULL;
		Node *head1,*head2;
		add_node(&head,99);
		add_node(&head,12);
		add_node(&head,56);
		add_node(&head,2);
		add_node(&head,11);
		print(head);
		split(head,&head1,&head2);
		print(head1);
		print(head2);

}


void add_node(Node **head_ref, int value){
	Node *new_node = new Node;
	new_node->value = value;
	Node *temp = *head_ref;
	new_node->next = *head_ref;

	if(*head_ref!=NULL){
		while(temp->next != *head_ref)
			temp = temp->next;
		temp->next = new_node;
	}
	else
		new_node->next = new_node;
	*head_ref = new_node;
}

void print(Node *head){

	Node *temp;
	temp = head;

	if(head!=NULL){

		do{
			cout<<" "<<temp->value;
			temp = temp->next;
		}
		while(temp != head);
		cout<<"\n";
	}

}


void split(Node *head, Node **head1_ref, Node **head2_ref){

		Node *slow = head;
		Node *fast = head;
		
		while(fast->next!= head && fast->next->next != head){
			slow = slow->next;
			fast = fast->next->next;
		}

		if(fast->next->next == head)
			fast = fast->next;
		
		*head1_ref = head;	
		*head2_ref = slow->next;
		fast->next = slow->next;
		slow->next = head;
		
		
}