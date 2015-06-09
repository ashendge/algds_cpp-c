#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
void delete_lesser(Node *head);

int main(){

		Node *head = NULL;
		
		
		add_node(&head,10);
		add_node(&head,20);
		add_node(&head,30);
		add_node(&head,40);
		add_node(&head,50);
		add_node(&head,60);
		print(head);

		delete_lesser(head);
		
		return 0;
}

void print(Node *head){

		Node *temp = head;
		Node **temp_ref = &temp;
		
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


void delete_lesser(Node *head){

		Node *current = head;
		Node *prev = NULL;

			while(current !=NULL){
				
		if(current->next != NULL){
		
		if(current->value < (current->next)->value){

				Node *t1 = current;
				current = current->next;
				
				if(head == t1){
					head=prev=current;
					cout<<t1->value<<" deleted\n";
					delete t1;
				}
				else
				{
					cout<<t1->value<<" deammn\n";
					prev->next = t1->next;
					delete t1;
				}
		
		}

		else{
		
			if(current == NULL)
				break;
			prev = current;
			current = current->next;
		}

	}
	else
	{
	
		print(head);
		return;
	}
}


}
