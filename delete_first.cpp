#include <iostream>
#include <cstdlib>

using namespace std;


struct Node{

	int value;
	Node *next;
};

struct Node *add_node(Node *, int);
struct Node *delete_first_node(Node *);
void print(Node *);

int main(){


		cout<<"linked list\n";
		struct Node *head = new Node;	
		head->value=44;
		head->next=NULL;
//		cout<<"HEAD= "<<head->value;

		/*push the node into the linked list*/	

		head = add_node(head,55);
		head = add_node(head,66);
		head = add_node(head,22);
		head = add_node(head,88);


		//head=delete_first_node(head);	
		

		cout<<"Changed head node= "<<head->value<<endl;

		print(head);

}

struct Node *add_node(Node *head,int value){

			if(head==NULL)
				{
				cout<<"Program terminated"<<endl;
				exit(0);
			}
			Node *temp = head;
			
			while(temp->next!=NULL)
			{
				
				temp = temp->next;
			}

			temp ->next = new Node;
			temp = temp->next;
			temp->value = value;
			temp->next=NULL;
			return head;
		}

void print (Node *head){

	Node* temp = head;

	while(temp!=NULL){

		cout<<temp->value<<" ";
		temp = temp->next;


	}


}	

Node *delete_first_node(Node *head){

		Node *temp;
		temp = head;
		head = head->next;
		cout<<"Deleting the head node= "<<temp->value<<endl;
		
		delete temp;
		return head;

}
