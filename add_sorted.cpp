#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *next;

};

void add_node(Node **, int  );
void print(Node *);
void add_element_sorted(Node **, int );
int main(){


	Node *head = NULL;

	add_node(&head,88);
	add_node(&head,77);
	add_node(&head,55);
	add_node(&head,44);
	add_node(&head,33);
	add_node(&head,22);
	print(head);

	add_element_sorted(&head,99);
	print(head);

}

void print(Node *head){

	Node *temp = head;
	while(temp!=NULL){
		cout<<" "<<temp->value;
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

void add_element_sorted(Node **head_ref, int data){

		Node *temp1, *temp2;

		if(*head_ref == NULL)
		{
			Node *new_node = new Node;
			new_node->value = data;
			new_node->next = *head_ref;
			*head_ref = new_node;
		}

		if((*head_ref)->value > data){

			Node *new_node = new Node;
			new_node->value = data;
			new_node->next = *head_ref;
			*head_ref = new_node;
		}

		temp1 = *head_ref;
		temp2 = (*head_ref)->next;

		while(temp1!=NULL && temp2!= NULL){

			if(temp2->value > data && temp1->value < data){

				Node *new_node = new Node;
				new_node->value = data;
				Node *helper = temp1->next;
				temp1->next = new_node;
				new_node->next = helper;
				return;
			}

			else{

				temp1 = temp1->next;
				temp2 = temp2->next;
			}


		}

		if(temp1->next==NULL){

			Node *new_node = new Node;
			new_node->value = data;
			new_node->next = NULL;
			temp1->next = new_node;
			return;
		}

		cout<<"John SNow killed whitewalkers";



}
