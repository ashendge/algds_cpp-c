#include <iostream>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

void create_tree(Node **root_ref, int );
Node *new_node(int ); 
void print_tree(Node *root);
void join(Node *a, Node *b);
Node *append(Node *a, Node *b);	
Node *tree_to_list(Node *);
void print_list(Node *);
int main(){
	Node *root = NULL;
	create_tree(&root,4);
	create_tree(&root,5);
	create_tree(&root,2);
	create_tree(&root,3);
	create_tree(&root,1);

	cout<<"Tree\n";	
	print_tree(root);

	Node *head = tree_to_list(root);
	cout<<"DLL\n";	
	print_list(head);

	return 0;
}

Node *new_node(int value){
	Node *new_node = new Node;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
/*Tree creation*/
void create_tree(Node **root_ref, int new_value){
	Node *root = *root_ref;
	if(root == NULL){
		*root_ref = new_node(new_value);
		cout<<"Data Inserted ="<<new_value<<endl;
	}
	else{
		if(root->value >= new_value)
			create_tree(&(root->left),new_value);
		else
			create_tree(&(root->right), new_value);
	}
}
void print_tree(Node *root){
	if(root == NULL)
		return;
	print_tree(root->left);
	cout<<root->value<<" ";
	print_tree(root->right);
	cout<<"\n";
}

void join(Node *a, Node *b){
	a->right = b;
	b->left = a;
}

Node *append(Node *a, Node *b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	Node *a_last = a->left;
	Node *b_last = b->left;
	join(a_last,b);
	join(b_last,a);
	return a;
}

Node *tree_to_list(Node *root){
	if(root == NULL)
		return NULL;
	Node *a_ptr = tree_to_list(root->left);
	Node *b_ptr = tree_to_list(root->right);
	/*Ultimate single root - make a circular list out of it and recusrively join lists*/	
	root->left = root;
	root->right = root;
	/* Join the child list a_ptr and b_ptr with the root which is one level up in the recursion*/
	a_ptr = append(a_ptr,root);
	a_ptr = append(a_ptr,b_ptr);
	return a_ptr;
}
void print_list(Node *head){
	Node *temp = head;

	do{
		cout<<temp->value<<" ";
		temp = temp->right;
	}while(temp!=head);
	cout<<"\n";
}


