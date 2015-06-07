#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
void alt_k_reverse(Node **, int );

int main(){

		Node *head = NULL;

		add_node(&head,9);
		add_node(&head,8);
		add_node(&head,7);
		add_node(&head,6);
		add_node(&head,5);
		add_node(&head,4);
		add_node(&head,3);
		add_node(&head,2);
		add_node(&head,1);
		print(head);

		alt_k_reverse(&head,3);

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

  
void alt_k_reverse(Node **head, int k){
Node *current=*head;
Node *prevNode,*nextNode,*tmp1,*tmp2;
int cnt;

prevNode=*head;
*head=NULL;

while(current)
{ 
	cnt=k;
	tmp1=prevNode; //save 1st poniter
	tmp2=current; //save 2nd pointer

		while(current && cnt--) // reverse k nodes

		{
		nextNode=current->next;
		current->next=prevNode;
		prevNode=current;
		current=nextNode;
		}

	if(*head==NULL) //set new head
	*head=prevNode;	

	else
	tmp1->next=prevNode; //link 1st ponter
	 
	tmp2->next=current; //link 2nd pointer
	cnt=k;

	while(current&&cnt--){ // skips k noodes
		prevNode=current;
		current=current->next;
		 }


}
print(*head);

}
