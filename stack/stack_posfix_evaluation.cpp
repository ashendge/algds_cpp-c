#include <iostream>
#include <string>
using namespace std;


/***************************Problem Statement******************



***************************************************************/
/***************************Limitation************************
The code can only work with single digits and not mutiple
digits.
foe example; 2+3 is fine but 10 + 2 is not as I have not yet
incorporated the mechanism to do that as of [June 25th 2015].

Just in case if I come back and try to fix it again,
remember that, it can be done when the input expression
is seperated with spaces[or any delimiter for that matter!].
Spaces are more standard and relatable in an expression though.

****************************************************************/
struct Node{
	int value;
	Node *next;
};
bool isEmpty(Node **top_ref){
  if(*top_ref == NULL)
    return true;
  return false;
}
void push(Node **top_ref, int value){
  Node *new_node = new Node;
  new_node->value = value;
  new_node->next = *top_ref;
  *top_ref = new_node;
}
int pop(Node **top_ref){
  if(isEmpty(top_ref)){
      return -111111;
  }
  int pop_value = (*top_ref)->value;
  Node *temp = *top_ref;
  *top_ref = (*top_ref)->next;
  delete temp;
  return pop_value;
}
int peek(Node **top_ref){
  if(!isEmpty(top_ref))
    return (*top_ref)->value;
  else{
    return -11111;
    }
}
int operate(int right_operand,int left_operand,char operater){
  switch(operater){
    case '+':
      return left_operand + right_operand;
    case '-':
      return left_operand - right_operand;
    case '*':
      return left_operand * right_operand;
    case '/':
      return left_operand / right_operand;
  }
  return -11111;
}
int evaluate_expression(string post_exp){
  Node *stack = NULL;
  for(int i=0; i<post_exp.size();i++){
    if(isdigit(post_exp[i])){
      int char_to_int = post_exp[i] - '0';
      push(&stack,char_to_int);
    }
    else{
      int right_operand = pop(&stack);
      int left_operand = pop(&stack);
      cout<<"Right="<<right_operand<<" Left="<<left_operand;
      cout<<" Operand="<<post_exp[i]<<endl;
      int result = operate(right_operand,left_operand,post_exp[i]);
      push(&stack,result);
    }
  }
  if(!isEmpty(&stack))
    return peek(&stack);
  else
    return -111111;
}

int main(){
  string post_exp = "42351-+*+";
  int result = evaluate_expression(post_exp);
  cout<<"The result of the postfix expression "<<post_exp<<" ="<<result;
  cout<<endl;
  return 0;
}
