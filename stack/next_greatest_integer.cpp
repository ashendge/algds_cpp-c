#include <iostream>
#include <stack>
/*****************************************************************************
Link: http://www.geeksforgeeks.org/next-greater-element/
Description:
Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element
on the right side of x in array. Elements for which no greater
element exist, consider next greater element as -1.
******************************************************************************/
using namespace std;

void finNGE(int a[], int n){

  stack <int> s;
  s.push(a[n-1]);

  for(int i=n-1;i>=0;i--){

    while(!s.empty() && s.top() <= a[i])
      s.pop();

    if(s.empty())
      cout<<"a[i]="<<a[i]<<"->Next= -1"<<endl;
    else
      cout<<"a[i]="<<a[i]<<"->Next= "<<s.top()<<endl;
    s.push(a[i]);
  }
}

int main(){

  int arr[4] = {4,5,2,25};
  finNGE(arr,4);


}
