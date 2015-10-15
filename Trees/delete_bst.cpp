	#include <iostream>

	using namespace std;


	struct Node{

		int data;
		Node *left;
		Node *right;
	};

	void inorder(struct Node *root)
	{
	    if (root != NULL)
	    {
	        inorder(root->left);
	        cout<<root->data<<" ";
	        inorder(root->right);
	    }
	}
	 

	Node *min_value(Node *root){

		Node *curr = root;
		while(curr->left != NULL)
			curr = curr->left;
		return curr;
	}

	Node *insert(Node *root,int value){

					if (root == NULL)
			{
					Node *temp = new Node;
				temp->data = value;
					temp->left = NULL;
						temp->right = NULL;
				//cout<<value<<endl;
				return temp;

			}

				if (value < root->data)
			{
		
					root->left = insert(root->left,value);

			}
				else
			{
				root->right = insert(root->right,value);
			}
			return root;

	}

	Node *deleteNode(Node *root, int key){


		if (root == NULL)
			return root;

		if(root->data > key)
			root->left = deleteNode(root->left,key);
		else if (root->data < key )
			root->right = deleteNode(root->right,key);

		else{

			if (root->left == NULL)
				{
					Node *temp = root->right;
					delete(root);
					return temp;

				}	
			else if (root->right == NULL)
			{
				Node *temp = root->left;
				delete(root);
				return temp;
			}	


			Node *temp = min_value(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);	
		}

		return root;
	}










	int main(int argc, char const *argv[])
	{
		

		Node *root = NULL;
 	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
	
	inorder(root);
		    cout<<endl;

	root = deleteNode(root,5);
	inorder(root);
		    cout<<endl;

		return 0;
	}

