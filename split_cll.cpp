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

		add_node(&head,12);
		add_node(&head,56);
		add_node(&head,2);
		add_node(&head,11);

		split(head,&head1,&head2);
		print(head1);
		print(head2);

}

void split(Node *head, Node *head1_ref, Node **head2_ref){
	
}