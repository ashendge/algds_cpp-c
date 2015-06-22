#include <iostream>

using namespace std;
struct Node{
	int value;
	Node *next;
	Node *arbit;
};


Node *add_node(int key);
void print(Node *head);
Node *clone(Node *head);
Node *head = NULL;

int main(){

	Node *head = add_node(1);
	head->next = add_node(2);
	head->next->next = add_node(3);
	head->next->next->next = add_node(4);
	head->next->next->next->next = add_node(5);
	head->next->next->next->next->next = NULL;
	/*
	Arranging the arbit pointers now below
	*/
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit = head->next->next->next->next;
	head->next->next->next->arbit = head->next->next;
	head->next->next->next->next->arbit = head->next;
	cout<<"Original List"<<"\n";
	print(head);
	Node *ans = clone(head);
	cout<<"Cloned List"<<"\n";
	print(ans);
	return 1;
}

Node *add_node(int key){
	Node *new_node = new Node;
	new_node->value = key;
	new_node->next = NULL;
	new_node->arbit = NULL;
	return new_node;
}
void print(Node *head){

	Node *temp = head;
	while(temp!=NULL){

		cout<<"Node data="<<temp->value<<" Arbit data="<<temp->arbit->value<<endl;
		temp = temp->next;
	}
	cout<<endl;
}

Node *clone(Node *head){

		Node *org_ptr =  head;
		Node * dummy_ptr;
	cout<<"test";	
		while(org_ptr){
				
			dummy_ptr = add_node(org_ptr->value);
			Node *temp = org_ptr->next;
			org_ptr->next = dummy_ptr;
			dummy_ptr->next = temp;
			org_ptr = temp;

		}
		org_ptr = head; // Important step!
	
		while(org_ptr!= NULL && org_ptr->next != NULL){
			org_ptr->next->arbit = org_ptr->arbit->next;
			org_ptr = org_ptr->next->next;
		}	

		Node *duplicate_head = head->next;
		org_ptr = head;

		while(org_ptr){

			dummy_ptr = org_ptr->next;
			org_ptr->next = dummy_ptr->next;
			org_ptr = dummy_ptr->next;
			if(dummy_ptr->next)
				dummy_ptr->next = dummy_ptr->next->next;
		}
		return duplicate_head;
}