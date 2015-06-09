#include <iostream>

using namespace std;

struct Node{

		int value;
		Node *next;
};

void add_node(Node **, int )
void print(Node *head);
void segrregate(Node **);c

int main(){

		Node *head = NULL;
		
		
	//	add_node(&head,7);
		add_node(&head,44);
	//	add_node(&head,11);
		
		//add_node(&head,5);
		//add_node(&head,10);
		add_node(&head,12);
		add_node(&head,8);
		add_node(&head,6);
		add_node(&head,4);
		add_node(&head,2);
		add_node(&head,0);

		print(head);
		segrregate(&head);
		print(head);	

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

void segrregate(Node **head_ref){

		Node **head  = head_ref;
		Node *current = *head;
		Node *prev = current;
		Node *end_ptr=*head;
		int count = 1, loopCount = 0;
		int last_vlaue = 0;
		bool flag = true;
		while(end_ptr->next != NULL)
		{
			end_ptr = end_ptr->next;
			count++;
		}				

		while(current != NULL && loopCount<count){

			if(current->value % 2 != 0){

					if(current == *head){
						
						end_ptr->next = current;
						end_ptr = end_ptr->next;
						*head = current->next;
						prev = *head;
						current = *head;
						end_ptr->next = NULL;	

					}

					else{
  
						end_ptr->next = current;
						end_ptr = end_ptr->next;
						prev->next = current->next;
						current = prev->next;
						end_ptr->next = NULL;
				
						if((current->value % 2) == 0 )
							prev = prev->next;

					}

			}

			else if((current->value % 2) == 0){
				current = current->next;
				if(current!=NULL && (current->value % 2) == 0 )
				prev = prev->next;

		}
		loopCount++;
	}

}





