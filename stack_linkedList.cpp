#include <iostream>
using namespace std;
#define EMPTY_VALUE -111111;
struct Node{
	int value;
	Node *next;
};

void push(Node **top_ref, int value){
	Node *new_node = new Node;
	new_node->value = value;
	new_node->next = *top_ref;
	*top_ref = new_node;
	cout<<value<<" added to the stack"<<endl;
}
bool isEmpty(Node **top_ref){
	//cout<<"Is it even2";
	if(*top_ref == NULL)
		return true;
	return false;
}
int pop(Node **top_ref){
	if(isEmpty(top_ref)){
		cout<<"Stack Empty, nothing to pop"<<endl;
		return EMPTY_VALUE;
	}
	int pop_value = (*top_ref)->value;
	Node *temp = *top_ref;
	*top_ref =(*top_ref)->next;
	delete temp;
	return pop_value;
}
int peek(Node **top_ref){
	if(isEmpty(top_ref)){
		cout<<"Stack Empty, nothing to peek"<<endl;
		return EMPTY_VALUE;
	}
	return (*top_ref)->value;
}

int main(){

	Node *top = NULL;
/*	push(&top,22);
		push(&top,33);
			push(&top,44);
				push(&top,55);
					push(&top,66);
*/					//	push(&top,77);

	if(pop(&top)>0)
	cout<<"Element popped->"<<pop(&top)<<endl;
	if(peek(&top)>0)
	cout<<"Element remaining peek->"<<peek(&top)<<endl;



	return 1;
}
