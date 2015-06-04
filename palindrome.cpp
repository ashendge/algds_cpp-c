#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{

	char val;
	Node *next;
};



void add_node(Node **, char );
void print(Node *);
bool is_palindrome(Node *);
void reverse(Node **);
bool compare_lists(Node *,Node *);
int main(){

	Node *head = NULL;

	char str[] = "abacaba";
	int i =0;

	for(i=0; str[i]!='\0'; i++){

		add_node(&head, str[i]);

		print(head);
	if(is_palindrome(head)){
		cout<<"Yay!!\n";
	}
	else
	{
		cout<<"GO To HELL\n";
	}


	}



	if(is_palindrome(head)){
		cout<<"Yay!!\n";
	}
	else
	{
		cout<<"Sorry Not a is_palindrome\n";
	}

	print(head);


}

bool is_palindrome(Node *head){

		Node *slow, *fast,*prev_of_slow,*mid_odd;
		slow = fast = head;
		mid_odd = NULL;
		bool res;
		if(head!=NULL && head->next!=NULL){

		while(slow!=NULL && fast!=NULL && fast->next!=NULL){

					fast = fast->next->next;
					prev_of_slow = slow;
					slow = slow->next;	
			
		}

		
// if the word is even numbered. 
		if(fast!=NULL){ 

			mid_odd = slow;
			slow = slow->next;
		}

		

		Node *second_half = slow;
		prev_of_slow->next = NULL;
		reverse(&second_half);
		res = compare_lists(head,second_half);


		/*Join them again */

		reverse(&second_half);
		if(mid_odd != NULL){

			 prev_of_slow->next = mid_odd;
			 mid_odd->next = second_half;

		}

		else
		{
			prev_of_slow->next = second_half;
		}

	}

	return res;

}


void reverse(Node **second_half_ref){

	Node *prev = NULL;
	Node *current,*Next;
	current = *second_half_ref;

	while(current!=NULL){

			Next = current->next;
			current->next = prev;
			prev = current;
			current = Next;
	}
		*second_half_ref = prev; 

}

bool compare_lists(Node *first_half, Node *second_half){

		Node *temp1 = first_half ;
		Node *temp2 = second_half;

		while(temp1!=NULL && temp2!=NULL){

				if(temp1->val == temp2->val)
				{
					temp1 = temp1->next;
					temp2 = temp2->next;

				}
				else
					 return 0;

		}

		if(temp1 == NULL && temp2 == NULL)
			return 1;

		return 0;

}




void print(Node *head){

	Node *temp;

	temp = head;

	while(temp!=NULL){

		cout<<temp->val;
		temp = temp->next;
	}

	cout<<endl;
}
void add_node(Node **head_ref, char val){


	Node *new_node = new Node;
	new_node->val = val;

	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}


