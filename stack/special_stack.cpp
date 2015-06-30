/*******************************************************************************
Link:http://www.geeksforgeeks.org/design-and-implement-special-stack-data-
structure/

Desciption:
Question: Design a Data Structure SpecialStack that supports all the stack
operations like push(), pop(), isEmpty(), isFull() and an additional
operation getMin() which should  return minimum element from the
SpecialStack. All these operations of  SpecialStack must be O(1).
To implement SpecialStack, you should only use standard  Stack data
structure and no other data structure like arrays, list, .. etc.

solution:

I am designing my own Stack class with the basic stack functions:
push pop ismepty isFull. I will extend this class which will be inherited
by the SpecialStack data structure.

********************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;


class Stack{
  private:
    static const int max = 10;
    int arr[max];
    int top;
  public:
    Stack(){
      top = -1;
    }
    void push(int x);
    int pop();
    bool isEmpty();
    bool isFull();
};

bool Stack::isEmpty(){
  if(top == -1)
    return true;
  return false;
}

bool Stack::isFull(){
  if(top == max -1)
    return true;
  return false;
}
int Stack::pop(){
  if(isEmpty()){
    cout<<"Stack Empty, nothing to pop...Aborting!"<<endl;
    abort();
  }
  return arr[top--];
}

void Stack::push(int x){

  if(isFull()){
    cout<<"StackOverflow...Aborting!"<<endl;
    abort();
  }
  arr[++top] =x;
}

class SpecialStack:public Stack{

      Stack min;
    public:
      int pop();
      void push(int x);
      int getMin();
};


void SpecialStack::push(int x){

    if(isEmpty()){
      Stack::push(x);
      min.push(x);
    }
    else{
      Stack::push(x);
      int val = min.pop();
      min.push(val);
      if(x>val)
        min.push(val);
      else
        min.push(x);
  }
}
int SpecialStack::pop(){

  int pop_value = Stack::pop();
  min.pop();
  return pop_value;
}

int SpecialStack::getMin(){
  int x = min.pop();
  min.push(x);
  return x;
}


int main(){

  SpecialStack s;

    s.push(20);
    s.push(10);
    s.push(30);
    cout<<s.getMin()<<endl;
    s.push(5);
    cout<<s.getMin()<<endl;


}
