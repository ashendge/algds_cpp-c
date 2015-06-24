#include <iostream>
#include <string>
using namespace std;

struct Node{
	char value;
	Node *next;
};
void push(Node **top_ref, char op){
	Node *new_node = new Node;
	new_node->value = op;
	new_node->next = *top_ref;
	*top_ref = new_node;
	//cout<<op<<" added to the stack"<<endl;
}
bool isEmpty(Node **top_ref){
	if(*top_ref == NULL)
		return true;
	return false;
}
char pop(Node **top_ref){

	if(isEmpty(top_ref)){
		return '\0';
	}
	char pop_value = (*top_ref)->value;
	Node *temp = *top_ref;
	*top_ref =(*top_ref)->next;
	delete temp;
	return pop_value;
}
char peek(Node **top_ref){
	return (*top_ref)->value;
}

bool is_valid_expression(string str){
	/*This function still has bugs in the sense that it can only 
		detect the cases where a parantehsisi is not closed
		but cannot detect the cases where suppose 2*(3+)*5
		This would pass as a valid expression 
	*/
	Node *temp_stack = NULL;
	for(int i=0;i<str.size();i++){
		
		if(str[i] == '(')
			push(&temp_stack,str[i]);
		else{
			if(str[i] == ')'){
				//cout<<"Popped="<<
				pop(&temp_stack);
			}
			

		}	
		/*if(!isEmpty(&temp_stack))
		//cout<<"Stack value= "<<peek(&temp_stack)<<endl;*/
	}

	//cout<<"Status is->"<<isEmpty(&temp_stack)<<endl;
	if(isEmpty(&temp_stack)){
		return true;
	}
	else{
		cout<<"Invalid"<<endl;
		return false;
	}
}


bool is_operand(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z' ))
		return true;
	return false;
}
int precedence(char ch){

	switch(ch){	
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;		
	}
	return -1;
}
string infix_to_postfix(string expr){
	if(!is_valid_expression(expr)){
		//cout<<"Warning!! Invalid expression";
		return "";
	}

	Node *stack=NULL;

	int k=-1;

	for(int i=0;i<expr.size();i++){
		//cout<<"Input="<<expr[i]<<endl;

		if(is_operand(expr[i])){
			expr[++k] = expr[i];
			//cout<<expr[k]<<endl;
		}
	
		else{
			if(expr[i] == '(')
				push(&stack,expr[i]);
			
			else if(expr[i] == ')'){
				while(!isEmpty(&stack) && peek(&stack) != '(')
					expr[++k] = pop(&stack);
				if(!isEmpty(&stack) && peek(&stack) != '(')
					return "";
				else 
					pop(&stack); // this one pops '(' --> not required in the output
			}
			else{
					
					while(!isEmpty(&stack) && precedence(expr[i]) <= precedence(peek(&stack)))	
						expr[++k] = pop(&stack);
					push(&stack, expr[i]);
				
			}	
		} 
	}
	while(!isEmpty(&stack)){
		expr[++k] = pop(&stack);
	}
	
	expr[++k] = '\0';
	return expr;

}


int main(){

	string expr = "(a+b)+c";
	string output = infix_to_postfix(expr);
	int i=0;
	while(output[i]!='\0')
		cout<<output[i++];
	cout<<endl;

}		