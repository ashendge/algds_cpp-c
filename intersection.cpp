#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int value;
	Node *next;

};
void add_node(Node **, int  );
void print(Node *);
Node *sorted_intersection(Node *, Node *);
int main(){


	Node *head = NULL;
	Node *head2 = NULL;
	add_node(&head,6);	
	add_node(&head,5);
	add_node(&head,4);
	add_node(&head,3);
	add_node(&head,2);
	add_node(&head,1);
	print(head);	
	
	add_node(&head2,8);
	add_node(&head2,6);
	add_node(&head2,4);
	add_node(&head2,2);
	print(head2);

	Node *intersect = sorted_intersection(head,head2);
	print(intersect);
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


Node *sorted_intersection(Node *a,Node *b){

		Node *result = NULL;
		Node **res_ref;
		res_ref = &result;
		//cout<<"test1";
		while(a!=NULL && b!=NULL){
		if(a->value == b->value){
    	   	   		   		
     		add_node(res_ref,a->value);
     		res_ref = &((*res_ref)->next);
     		a = a->next;
     		b = b->next;
		}

		 else if (a->value < b->value)
      		a=a->next;       /* advance the smaller list */   
    	else   
      		b=b->next;    
//	cout<<"test2";

}
  		return(result);

  }
  		
  		








