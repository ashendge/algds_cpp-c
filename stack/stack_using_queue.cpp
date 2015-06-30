#include <iostream>

using namespace std;
/*Build a custom Queue*/


class Queue{

  private:
    static const int capacity = 10;
    int arr[capacity];
    int front;
    int rear;

  public:
    Queue(){
      front = -1;
      rear = -1;
    }
  void enqueue(int x);
  int dequeue();
  bool isEmpty();
  bool isFull();
};

bool Queue::isEmpty(){
  if(front == -1)
    return true;
  return false;
}
bool Queue::isFull(){
  if(rear >= capacity-1)
    return true;
  return false;
}

void Queue::enqueue(int x){
      if(isEmpty()){

        arr[++rear] =x;
        front++;
        cout<<"Element Enqueued "<<arr[rear]<<" Rear="<<rear<<endl;
      }
      else if(!isFull()){
        arr[++rear] = x;
        cout<<"Element Enqueued "<<arr[rear]<<" Rear="<<rear<<endl;
      }
      else{
        cout<<"Queue overflow!"<<endl;
        return;
      }
}

int Queue::dequeue(){
  if(isEmpty()){
      return -1111;
  }
  int x_val;

  if(front == rear){
    x_val = arr[front];
    front = rear = -1;
  }
  else{
    x_val = arr[front];
    front = front +1;
  }
  return x_val;
}

class Stack: public Queue{

  Queue q1, q2;
public:
void push(int x);
int pop();

};

void Stack::push(int x){
  q2.enqueue(x);
  while(!q1.isEmpty()){
    q2.enqueue(q1.dequeue());
  }
Queue tempQ = q1;
q1 = q2;
q2 = tempQ;
}

int Stack::pop(){
  return q1.dequeue();
}


int main(){

  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);

cout<<" Popped ="<<s.pop()<<endl;
cout<<" Popped ="<<s.pop()<<endl;
cout<<" Popped ="<<s.pop()<<endl;
cout<<" Popped ="<<s.pop()<<endl;
cout<<" Popped ="<<s.pop()<<endl;

}
