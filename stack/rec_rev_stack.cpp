/********************************************************************************
Link: http://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
Desciption:Reverse a stack using recursion
You are not allowed to use loop constructs like while, for..etc, and you can
 only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)

>> Beautiful recursion !
*********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    char value;
    Node *next;
};

bool isEmpty(Node **top_ref){
    if((*top_ref)==NULL)
      return true;
    return false;
}

void push(Node **top_ref,char value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = *top_ref;
    *top_ref = new_node;
}

char pop(Node **top_ref){

    if(isEmpty(top_ref))
      return '\0';
    char val_temp = (*top_ref)->value;
    Node *temp = *top_ref;
    *top_ref  = (*top_ref)->next;
    delete temp;
    return val_temp;
}

int insert_at_back(Node **top_ref,char value){
  char temp;
  if(isEmpty(top_ref))
    push(top_ref,value);
  else{
       temp = pop(top_ref);
      insert_at_back(top_ref,value);
      push(top_ref,temp);

  }

}


void reverse(Node **top_ref){
  char temp;
  if(!isEmpty(top_ref)){
    temp = pop(top_ref);
    reverse(top_ref);
    insert_at_back(top_ref,temp);
  }
}

int main(){
Node *top = NULL;
push(&top,'A');
push(&top,'B');
push(&top,'C');
push(&top,'D');
cout<<pop(&top)<<endl;
reverse(&top);

cout<<pop(&top)<<endl;

return 1;

}
