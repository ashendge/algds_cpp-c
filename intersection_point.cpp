#include <iostream>
#include <cmath>
using namespace std;

struct Node{
	int value;
	Node *next;

};

void add_node(Node **, int  );
void print(Node *);
int is_intersection(Node *, Node *);
int get_node_count(Node *);
Node *get_equidistant_point(Node *, int );
int intersection_value(Node *, Node *);
int main(){


	Node *head1 = NULL;
	Node *head2 = NULL;
	
	add_node(&head1,30);
	add_node(&head1,15);
	add_node(&head1,9);
	add_node(&head1,6);
	add_node(&head1,3);
	
	print(head1);

	add_node(&head2,10);
	//head2->next = head1->next->next->next;
	print(head2);

	int res = is_intersection(head1, head2);

	if(res == -1)
	{
		cout<<" The list has no intersecion"<<endl;
	}
	else
	{
		cout<<"Intersection pint "<<res<<endl; 
	}

	return 0;
}

void print(Node *head){

	Node *temp = head;
	while(temp!=NULL){
		cout<<" "<<temp->value;
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

int is_intersection(Node *head1, Node *head2){

	int c1 = get_node_count(head1);
	int c2 = get_node_count(head2);
	int d = abs(c1-c2);
	Node *temp1,*temp2;
	
	if(c1 >= c2){
	
		temp1 = get_equidistant_point(head1,d);
		temp2 = head2;
	}
	else
	{
		temp1 = get_equidistant_point(head2,d);	
		temp2 = head1;
	}
	return intersection_value(temp1,temp2);
}

int get_node_count(Node *head){

		Node *temp = head;
		int count = 0;
		while(temp!=NULL){

			temp = temp->next;
			count++;
		}	
		return count;	
}

Node *get_equidistant_point(Node *head, int d){

		int i = 0;
		Node *tmp = head;
		for(i =0; i<d ; i++){

			tmp = tmp->next;
		}
		return tmp;
}

int intersection_value(Node *temp1, Node *temp2){

	while(temp1!=NULL && temp2!=NULL){

			if(temp1 == temp2){
				return temp1->value;
			}

			temp1 = temp1->next;
			temp2 = temp2->next;
	}
	return -1;
}
	