#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
Node *reverse(Node *, int );
void iter_reverse(Node **, int );	
/**
Important problem-  Its is better to take the recursive aproach than iterative one. 
in recursion head->next = reverse() is the main step where the linking of already reversed listsis done. I somehow missed it while doing the iterative version
of the same. Still no luck with iterative approach. May be the comments section couls help.

*/

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
		iter_reverse(&head, 3);
		
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


Node *reverse(Node *head, int k){

	int count =0;
	Node *next =NULL, *prev = NULL, *curr = NULL;
	curr = head;

	while(curr!=NULL && count < k){

			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;	
			count++;
		}
// next at this point points to the (k+1)the node. Thus we can start a new list from this point onwards so that 
//it will reverse the second chunk of the list. For linking, the link has to be made up at the original head->next 
//which was passed to the function at the start. I somehow misssed this point.		
		if(next!=NULL){
			head->next = reverse(next,k);
		}
		return prev;
}


void iter_reverse(Node **head_ref, int k){


		Node *curr, *prev, *next;
		Node *temp1, *previous_end = NULL;
		
		int count = 0;
		curr = *head_ref;
		prev = NULL;
		*head_ref = NULL;

		while(1){

			count = k;
			temp1 = curr;
			prev = NULL;		
		
			while(curr!=NULL && count--){

				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}

			if(previous_end!=NULL)
					previous_end->next = prev;


			if(*head_ref == NULL)
				*head_ref = prev;


			if(!curr)
				break;

			temp1->next = curr;
			previous_end = temp1;

		} 

		print(*head_ref);
}



