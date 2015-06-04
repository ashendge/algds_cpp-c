	#include <iostream>
	#include <cstdlib>

	using namespace std;

	struct Node{
		int value;
		Node *next;
	};

	void add_node(Node * , int );
	int get_length(Node *);

	int main(){

		
		cout<<"linked list\n";
		struct Node *head = new Node;	
		head->value=44;
		head->next=NULL;

		/*push the node into the linked list*/	

		add_node(head,55);
		add_node(head,66);
		add_node(head,22);
		add_node(head,88);

		cout<<"The length of linked list is: "<<get_length(head)<<endl;

		return 0;
	}
		/* Code to add node to the head or last element in a linked list!!*/
		void add_node(Node *head,int value){

			if(head==NULL)
				{
				cout<<"Program terminated"<<endl;
				exit(0);
			}
			Node* temp = head;
			
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}

			temp->next = new Node;
			temp->value = value;

		}



	int get_length(Node *head){

		if(head==NULL)
		{
			return 0;
		}
		else
			return 1 + get_length(head->next);

	}	

