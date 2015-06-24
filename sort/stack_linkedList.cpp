#include <iostream>
using namespace std;
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
	cout<<"Is it even2";
	if(*top_ref == NULL)
		return true;
	return false;
}
Node pop(Node **top_ref){
	cout<<"Is it even1";
	if(isEmpty(top_ref))
		cout<<"The stack is is Empty";
	else
		cout<<"teh stack is not empty";

}

int peek(){

}

int main(){

	Node *top = NULL;
	push(&top,22);
	push(&top,33);
	push(&top,44);
	pop(&top);
	return 1;
}