#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
	
	};

struct node *insert(struct node *,int );
struct node *getnode(int );
int search(struct node *, int );
int Find_min(struct node* );
int find_height(struct node *);


int search(struct node *root, int val)
{
//	printf("<%p>\n",root);
	if(root==NULL)	return 0;
	else if(root->data == val) return 1;
	
	else if(root->data >= val) return search(root->left,val);	
	else  return search (root->right,val);		

}
struct node *getnode(int val)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));	
	temp->data = val;
	temp->left=temp->right=NULL;
	return temp;

}

struct node *insert(struct node *root,int val){
	if(root==NULL){
	root = getnode(val);
	
	}

	else if(root->data <= val) 
	{  
	   //printf("\n[ROOT:Right=%p - VAL=%d]\n",root,val);	
	   root->right = insert(root->right,val); 

	}
	else{   
		//printf("\n[ROOT:Left=%p - VAL=%d\n]",root,val);
		root->left=insert(root->left,val);
  	  }
	
	return root;
}


int main(){
	
	struct node *root= NULL;
	
	root = insert(root,15);		
	root=insert(root,10);
	root =insert(root,20);
	root =insert(root,8);
	root =insert(root,2);
	root =insert(root,17);

	/*	To search a number in a tree	*/
  	/*	
	if(search(root,14)== 1)  
	printf("FOUND"); 
	else printf("NOT FOUND");
	*/
	
	/* TO find MIN AND MAX
	printf("%d",Find_min(root));
	*/

	/*FIND THE HEIGHT*/
	printf("\nHeight %d\n",find_height(root));

	
	
	
	return 0;
	}


int Find_min(struct node *root){

	struct node * temp;
	temp = root;

	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp->data;

}


int find_height(struct node *root){

	int lefth,righth;
	if(root==NULL)
	return -1;

	lefth= find_height(root->left);
	righth= find_height(root->right);
	
	if(lefth > righth)
	return lefth + 1;
	else 
	return righth + 1;
}
