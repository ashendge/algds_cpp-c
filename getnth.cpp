#include <iostream>
#include <cstdlib>

using namespace std;


struct Node{

	int value;
	Node *next;
};

Node *add_node(Node *, int );
Node *get_nth_node(Node *,int );
Node *nth_ptr_from_end(Node *, int );
void print(Node *);


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
		//add_node(head,99);
		cout<<"Nth node from the start is="<<(get_nth_node(head,2))->value<<endl;	
		cout<<"Nth node from end is="<<(nth_ptr_from_end(head,2))->value<<endl;
		print(head);
		return 0;



}	


void print(Node *head){

		Node *temp;
		temp = head;
		
		while(temp!=NULL)
		{
			cout<<temp->value<<"-";
			temp = temp->next;
		}

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

struct Node *nth_ptr_from_end(Node *head, int n){

		Node *ptr1, *ptr2;

		ptr1=ptr2=head;
		int count = 1;

		if(head!=NULL)
		{
			while(ptr1->next!=NULL)
			{
				if(count==n)
				{
					ptr1 = ptr1->next;
					ptr2 =ptr2->next;
				}

				else
				{
					ptr1 = ptr1->next;
					count++;
				}

			}
		
			return ptr2;
		}

		return NULL;

}

struct Node *get_nth_node(Node *head, int n){

		int count = 1;
		Node *temp = head;
		while(count!=n)
		{
			temp = temp->next;
			count++;

		}

		return temp;
}
