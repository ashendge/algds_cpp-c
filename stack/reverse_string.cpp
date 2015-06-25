#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*****************************************************************
Problem description: Reverse a string using stack
Link:http://geeksquiz.com/stack-set-3-reverse-string-using-stack/
****************************************************************/

string reverse(string str){
  stack <char> s;
  for(int i=0;i<str.size();i++){
    s.push(str[i]);
  }
  for(int i=0;i<str.size();i++){
   str[i] = s.top();
   s.pop();
 }
 return str;
}

int main(){
  string str = "anurag";
  cout<<"Original string --->"<<str<<endl;
  string result_str = reverse(str);
  cout<<"Reversed string --->"<<result_str<<endl;
  return 1;
}
