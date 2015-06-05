#include <iostream>
#include <cmath>

using namespace std;

struct Node{
	int value;
	Node *next;
};

void add_node(Node **, int  );
void print(Node *);
Node *merge(Node *, Node *);
Node *merge_rec(Node *, Node *);

int main(){


	Node *head1 = NULL;
	Node *head2 = NULL;
	
	add_node(&head1,15);
	add_node(&head1,10);
	add_node(&head1,5);	

	add_node(&head2,20);
	add_node(&head2,3);
	add_node(&head2,2);
	
	print(head1);
	print(head2);
	
	//Node *result = merge(head1,head2);
	
	Node *result_rec = merge_rec(head1,head2);
	print(result_rec);
	
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

Node *merge(Node *a, Node *b){

		Node *result = NULL;
		Node **res_ref = &result;

		if(a == NULL)
			return b;
		if(b == NULL)
			return a;
		while(a!=NULL && b!=NULL){
		if(a->value <= b->value){
			add_node(res_ref,a->value);
			res_ref = &((*res_ref)->next);
			a = a->next;
		}
		else if(b->value < a->value){
			add_node(res_ref,b->value);
			res_ref = &((*res_ref)->next);
			b = b->next;	

		}	
	}
		if(a == NULL){
				while(b!=NULL){
				add_node(res_ref,b->value);
				res_ref = &((*res_ref)->next);
				b = b->next;	
				
			}
		}
			
		else if(b == NULL){
				
				while(a!=NULL){
				add_node(res_ref,a->value);
				res_ref = &((*res_ref)->next);
				a = a->next;	
			  }
		}	
	
		return result;

}


Node *merge_rec(Node *a, Node *b){

			struct Node *result  = NULL;


			if(a == NULL)
				return b;
			if(b == NULL)
				return a;

			if(a->value <= b->value){

				result = a;
				result->next = merge_rec(a->next,b);
			}	
			else
			{
				result = b;
				result->next = merge_rec(b->next,a);
			}

			return result;
	}
