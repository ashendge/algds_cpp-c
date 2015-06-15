#include <iostream>
using namespace std;
struct Node{
	int value;
	Node *next;
};

void add_node(Node **, int );
void print(Node *);
void merge_sort(Node **head_ref);
void front_back_split(Node *source, Node **front_ref, Node **back_ref);
Node *sorted_merge(Node *a, Node *b);
void reverse(Node **head_ref);
void find_triplet(Node *a, Node *b, Node *c, int num);

int main(){


	Node *headA = NULL;
	Node *headB = NULL;
	Node *headC = NULL;

    add_node (&headB, 29);
    add_node (&headB, 6);
 	add_node (&headB, 12);

    add_node (&headA, 8);
    add_node (&headA, 5);
    add_node (&headA, 23);

    add_node (&headC, 59);
    add_node (&headC, 20);
    add_node (&headC, 90);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    
 
    /*create another sorted linked list 'c' 8->4->2->1 */
    

	find_triplet(headA,headB,headC,101);
	


}

void add_node(Node **head_ref, int value){

	Node *new_node = new Node;

	new_node->value = value;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print(Node *head){
	Node *temp = head;
	while(temp){
		cout<<" "<<temp->value;
		temp = temp->next;
	}
	cout<<endl;
}

void merge_sort(Node **head_ref){

	Node *head = *head_ref;
	Node *a ,*b;
	if(head == NULL || head->next == NULL)
		return;


	front_back_split(head, &a, &b); // split the linked list until the elements are singular[ recursively merge is being called on the smaller lists]

	/*The two sublists a and b are further being divided into halves */	
	merge_sort(&a);
	merge_sort(&b);

	/*As a single element list is already sorted, the linked list is merged as sorted lists recursively and returned back.
	  this way, the first *head_ref will be the last call returned which has to be the major list sorted which is the final two halves[the largest]
	*/

	*head_ref = sorted_merge(a,b);
}

void front_back_split(Node *source, Node **front_ref, Node **back_ref){

	Node *fast, *slow;

	if(source == NULL || source->next == NULL){

		*front_ref = source;
		*back_ref = NULL;
	}

	else{

			slow = source;
			fast = source->next;

			while(fast!=NULL){
				fast = fast->next;
				if(fast!=NULL){
					slow = slow->next;
					fast = fast->next;
			}
		}	

			*front_ref = source;
			*back_ref = slow->next;
			slow->next = NULL; 

		}

	}

Node *sorted_merge(Node *a, Node *b){
	Node *result = NULL;

	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;

	if(a->value <= b->value){
		result = a;
		result->next = sorted_merge(a->next,b);
	}
	else{
		result = b;
		result->next = sorted_merge(a,b->next);
	}
	return result;
}

void reverse(Node **head_ref){

	Node *prev = NULL;
	Node *current = *head_ref;
	Node *Next;

	while(current!=NULL){
		Next = current->next;
		current->next = prev;
		prev= current;
		current = Next;
	}

	*head_ref = prev;
}

void find_triplet(Node *a, Node *b, Node *c, int num){

	Node *aHead = a, *bHead = b, *cHead = c;

	merge_sort(&bHead);
	merge_sort(&cHead);
	reverse(&cHead);

	while(aHead != NULL){
		
		Node *b_prop = bHead;
		Node *c_prop = cHead;
//		print(b_prop);
	//	print(c_prop);

		while(b_prop && c_prop){
			
			int sum = aHead->value + b_prop->value + c_prop->value;
				//cout<<sum<<endl;
			//	cout<<"First="<<aHead->value<<" Second="<<bHead->value<<" Third="<<cHead->value<<endl;
		
			if(sum == num ){
				cout<<"THe triplet is found\n"<<"First="<<aHead->value<<" Second="<<bHead->value<<" Third="<<cHead->value<<endl;
				return;
			}

			else if(sum < num)
				b_prop = b_prop->next;
			else if(sum > num)
				c_prop = c_prop->next;	

		}
		
			aHead = aHead->next;

	}
}
