#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int );
void print(Node *head);
void add_link(Node *, Node *);

int main(){

		Node *head1 = NULL, *head2;
		
		add_node(&head2,4);
		add_node(&head2,8);
		
		add_node(&head1,6);
		add_node(&head1,4);
		add_node(&head1,9);
		add_node(&head1,5);
		add_node(&head1,7);

		print(head1);
		print(head2);
	
		add_link(head1,head2);
		
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

void add_link(Node *num1, Node *num2){
/****************************************************

In this function we add till shorter runs out. 




*/
	Node *sum_node = NULL;
	Node **ref_sum;
	ref_sum = &sum_node;

	Node *ptr1 = num1, *ptr2 = num2;		
	int sum_temp = 0 , carry =0;

	while(ptr1 && ptr2){

		sum_temp = ptr1->value + ptr2->value + carry;

		if(sum_temp > 9){

			carry = sum_temp / 10;
			sum_temp = sum_temp % 10;
			add_node(ref_sum,sum_temp);
			
		}

		else{
			add_node(ref_sum,sum_temp);
		}

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

	}
	
	if(ptr1){
/**********************************************
	Here a flag is maintained because the carry has to  be zero if the element[ptr->value] 
	is not 9 in the previous step

*/
			int flag = 0;	
	
		while(ptr1){
				flag=0;
				sum_temp = ptr1->value + carry;

				if(sum_temp > 9){
					flag = 1;
					carry = sum_temp / 10;
					sum_temp = sum_temp % 10;
					add_node(ref_sum,sum_temp);
				}

				else{
					add_node(ref_sum,sum_temp);
			}
				if(flag!=1)
				carry =0;
				ptr1 = ptr1->next;
		}

	}

	else if(ptr2){

			int flag =0;
			while(ptr2){
				flag=0;
			sum_temp = ptr2->value + carry;

			if(sum_temp > 9){
				flag =1;	
				carry = sum_temp / 10;
				sum_temp = sum_temp % 10;
			
				add_node(ref_sum,sum_temp);
			}

			else{
			add_node(ref_sum,sum_temp);
		}	
			if(flag!=1)	
			carry = 0;
			ptr2 = ptr2->next;
		}		
	
	}
	 
	print(sum_node);
	
}








	