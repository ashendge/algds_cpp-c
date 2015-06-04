#include <iostream>
using namespace std;

struct node{

		int value;
		node *next;
};
void print(node *);
void add_node(node **, int data);
int  is_loop(node *);

int main(){

	node *head = NULL;
	add_node(&head, 22);
	add_node(&head, 33);
	add_node(&head, 44);
	add_node(&head, 55);

	print(head);
	
	head->next->next->next->next = head;

	int result = is_loop(head);

	if(result == 2)
		cout<<" The list is empty"<<endl;
	
	else if(result == 1)
		cout<<" The list does not have a loop "<<endl;

	else if(result == 0)
		cout<<"the list has a loop"<<endl;



}

int is_loop(node *list_head){

		node *slow,*fast;
		slow = fast = list_head;

		if(list_head == NULL){

			return 2;
		}


		while(slow!=NULL && fast!=NULL && fast->next!=NULL){

			slow = slow->next;
			fast = fast->next->next;

			if(slow == fast)
				return 0;

		}

			return 1;

}


void print(node *head){

	node *temp = head;

	while(temp!=NULL){
		cout<<" "<<temp->value<<endl;
		temp = temp->next;
	}
}
void add_node(node **head_ref, int value){

				node *new_node  = new node;
				new_node->value = value;
				new_node->next = *head_ref;
				*head_ref = new_node;


}