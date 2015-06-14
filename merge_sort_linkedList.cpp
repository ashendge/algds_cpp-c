#include <iostream>
using namespace std;
struct Node{

	int value;
	Node *next;
};

void add_node(Node **, int );
void print(Node *);
void merge_sort(Node **head_ref);
void front_back_split(Node *source, Node **front_ref, Node **back_ref);
Node *sorted_merge(Node *a, Node *b);


int main(){


Node *head = NULL;

add_node(&head,2);
add_node(&head,5);
add_node(&head,0);
add_node(&head,2);
add_node(&head,2);
print(head);

merge_sort(&head);
print(head);

}

void add_node(Node **head_ref, int value){

	Node *new_node = new Node;

	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;


	
}

void print(Node *head){
	Node *temp = head;
	while(temp){
		cout<<" "<<temp->value;
		temp = temp->next;
	}
	cout<<endl;
}

void merge_sort(Node **head_ref){

	Node *head = *head_ref;
	Node *a ,*b;
	if(head == NULL || head->next == NULL)
		return;


	front_back_split(head, &a, &b); // split the linked list until the elements are singular[ recursively merge is being called on the smaller lists]

	/*The two sublists a and b are further being divided into halves */	
	merge_sort(&a);
	merge_sort(&b);

	/*As a single element list is already sorted, the linked list is merged as sorted lists recursively and returned back.
	  this way, the first *head_ref will be the last call returned which has to be the major list sorted which is the final two halves[the largest]
	*/

	*head_ref = sorted_merge(a,b);

}

void front_back_split(Node *source, Node **front_ref, Node **back_ref){

	Node *fast, *slow;

	if(source == NULL || source->next == NULL){

		*front_ref = source;
		*back_ref = NULL;
	}

	else{

			slow = source;
			fast = source->next;

			while(fast!=NULL){
				fast = fast->next;
				if(fast!=NULL){
					slow = slow->next;
					fast = fast->next;
			}
		}	

			*front_ref = source;
			*back_ref = slow->next;
			slow->next = NULL; 

		}

	}


Node *sorted_merge(Node *a, Node *b){
	Node *result = NULL;

	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;

	if(a->value <= b->value){
		result = a;
		result->next = sorted_merge(a->next,b);
	}
	else{
		result = b;
		result->next = sorted_merge(a,b->next);
	}
	return result;
}









