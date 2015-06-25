	/*
balance the given string for paranthesis
You may use the STL library for using pre implemented stacks
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool is_balanced(string str){
	stack <char> s;
	for(int i=0;i<str.size();i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			s.push(str[i]);
		}
		else{
			if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
				s.pop();
			}
		}
	}
	if(s.empty())
		return true;
	return false;
}

int main(){
	string str = "(anu)rag)";	
	if(is_balanced(str))
		cout<<"The string is balanced"<<endl;
	else
		cout<<"String is unbalanced"<<endl;
}