#include <iostream>

using namespace std;

struct Node{
	
	int value;
	Node *left;
	Node *right;
};

int isBalanced(Node *root, int* ht_ref){

	int lh=0, rh=0;

	if(root == NULL){
		*ht_ref = 0;
		return 1;
	}
	
	int l_res = isBalanced(root->left,&lh);
	int r_res = isBalanced(root->right,&rh);

	*ht_ref = (lh > rh ? lh:rh) +1;

	if((lh-rh) >=2 || (rh-lh) >=2)
		return 0;

	return (l_res && r_res);
}


Node *create_node(int value){ 

	Node *temp = new Node;
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;		
	return temp;	

}


int main(){

	Node *root = create_node(1);
 	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->left->left->left = create_node(7);
	
	int height = 0;	

	if(isBalanced(root,&height) == 1)
		cout<<"Tree is balanced!"<<endl;
	else
		cout<<"Tree is not balanced!"<<endl;

	return 1;
}
