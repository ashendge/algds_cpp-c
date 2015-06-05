#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
void alter(Node *,Node **, Node **);

int main(){

		Node *head = NULL;
		Node *a = NULL, *b = NULL;

		//add_node(&head,0);
		add_node(&head,4);
		add_node(&head,3);
		add_node(&head,2);
		add_node(&head,1);
		add_node(&head,0);
		print(head);

		alter(head,&a,&b);
		print(a);
		print(b);
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


void alter(Node *head, Node **a_ref, Node **b_ref){

		Node *ptr = head;
		Node *a = NULL , *b = NULL;
		Node **a_tail = a_ref;
		Node **b_tail = b_ref;	


//		a = *a_ref->next;
//		b = *b_ref->next;

		while(ptr!=NULL){

				add_node(a_ref,ptr->value);
				a_ref = &((*a_ref)->next);		
				ptr = ptr->next;

				if(ptr==NULL)
					return;

				add_node(b_ref,ptr->value);
				b_ref = &((*b_ref)->next);
				ptr = ptr->next;

		}



}
