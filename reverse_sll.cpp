#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{

	int value;
	Node *next;	
};

void add_node(Node **, int );
void print(Node *);
void reverse(Node **);
int main(){


		cout<<"linked list\n";
		struct Node *head = new Node;	
		head->value=44;
		head->next=NULL;

		/*push the node into the linked list*/	

		 add_node(&head,55);
		 add_node(&head,66);
		 add_node(&head,77);
		 add_node(&head,88);
		
		//print(head);
		//cout<<endl;

		 reverse(&head);

		 //print(head);
		 cout<<endl;

		return 0;

}


void print(Node *head){

		Node *temp;
		temp = head;
		if(temp!=NULL){		
		while(temp!=NULL)
		{
			cout<<temp->value<<"-";
			temp = temp->next;
		}
	}
	
	else
	cout<<"Empty Linked list";	

}


 void add_node(Node **head_ref,int value){

			Node *current = *head_ref;
		if(current==NULL)
		{
			cout<<"The program is temrminated"<<endl;

			exit(0);
		}


		Node *temp = current;

		while(temp->next!=NULL)
		{

			temp = temp->next;

		}

		temp->next = new Node;
		temp = temp->next;
		temp->value = value;
		temp->next = NULL;

	}

void reverse(Node **head_ref){
	
		Node *first;
		Node *rest;

		if(*head_ref == NULL)
			return;
		first = *head_ref;
		rest  = first->next;
		if(rest==NULL)
				return;

		reverse(&first->next);
			cout<<endl;
		
						
		cout<<"reverse Head="<<first->value<<"<---->Rest="<<rest;

     	first->next->next = first;
     	first->next = NULL;
		*head_ref = rest; 
		//cout<<"After ssssssHead="<<(*head_ref)->value<<"<---->Rest= "<<rest<<endl;

}	
	