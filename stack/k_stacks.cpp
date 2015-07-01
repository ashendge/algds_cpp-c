#include <iostream>
#include <climits>
using namespace std;


class kStack{

  int *arr;
  int *top;
  int *next;

  int n,k;
  int free;

public:
  kStack(int k,int n);
  bool isEmpty(int sn){
    if(top[sn] == -1)
      return true;
    return false;
  }
  bool isFull(){
    if(free == -1)
      return true;
    return false;
  }

  void push(int item, int sn);
  int pop(int sn);
};

/*constructor*/
kStack::kStack(int k1, int n1){
  k=k1;
  n=n1;
  free = 0;
  arr = new int[n];
  next = new int[n];
  top = new int[k];

  for(int i=0; i<k; i++)
    top[k] = -1;

  for(int i=0; i<n-1; i++)
    next[i] = i+1;
  next[n-1]  = -1;
}

void kStack::push(int item, int sn){

  if(isFull()){
    cout<<"The stack is Full\n";
    return;
  }

  int i = free;
  free = next[i];
  next[i] = top[sn];
  top[sn] = i;

  arr[i] = item;
  cout<<arr[i]<<" added to the stack at index i= "<<i<<endl;
}

int kStack::pop(int sn){

  if(isEmpty(sn)){
    cout<<"The stack is empty\n";
    return INT_MAX;
  }

  int i = top[sn];
  top[sn] = next[i];

  /*Pretty confusing , still not clear why next is assigend as free*/
  next[i] = free;
  free = i;

  return arr[i];
}


int main(){
  int k = 3, n = 10;
  kStack ks(k, n);

  // Let us put some items in stack number 2
  ks.push(15, 2);
  ks.push(45, 2);

  // Let us put some items in stack number 1
  ks.push(17, 1);
  ks.push(49, 1);
  ks.push(39, 1);

  // Let us put some items in stack number 0
  ks.push(11, 0);

  cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
  cout << "Popped element from stack 0 is " << ks.pop(0) << endl;


  ks.push(9, 0);
  ks.push(7, 0);

  cout << "Popped element from stack 2 is " << ks.pop(2) << endl;

  return 0;

}
