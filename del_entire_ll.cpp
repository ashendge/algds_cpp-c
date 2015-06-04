#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{

	int value;
	Node *next;	
};

Node *add_node(Node *, int );
void print(Node *);
Node *delete_entire(Node *);
int count(Node *, int );

int main(){


		cout<<"linked list\n";
		struct Node *head = new Node;	
		head->value=44;
		head->next=NULL;

		/*push the node into the linked list*/	

		head = add_node(head,55);
		head = add_node(head,66);
		head = add_node(head,22);
		head = add_node(head,88);
		
		print(head);
		//head = delete_entire(head);	
		cout<<"Count=>"<<count(head,42)<<endl;	

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

int count(Node *head, int num){

		Node* temp;
		temp = head;
		int count =0;

		while(temp!=NULL)
		{

			if(temp->value==num)
				count++;
			temp = temp->next;
		}
		return count;
}

struct Node *add_node(Node *head,int value){


		if(head==NULL)
		{
			cout<<"The program is temrminated"<<endl;

			exit(0);
		}


		Node *temp = head;

		while(temp->next!=NULL)
		{

			temp = temp->next;

		}

		temp->next = new Node;
		temp = temp->next;
		temp->value = value;
		temp->next = NULL;

		return head;

}

Node *delete_entire(Node *head){

	Node *Next,*current;

	current = head;

	while(current!=NULL)
	{
		Next = current->next;
		delete current;
		current = Next;

	}	
	head = NULL;
	return head;
}

