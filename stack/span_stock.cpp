/********************************************************************************
Link:http://www.geeksforgeeks.org/the-stock-span-problem/
Desciption:
The Stock Span Problem
The stock span problem is a financial problem where we have a series of n daily
price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number
 of consecutive days just before the given day, for which the pri
ce of the stock on the current day is less than or equal to its price on the given
 day.For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75,
85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

*********************************************************************************/
#include <iostream>
#include <stack>
using namespace std;


int *stock_span(int price[], int days){

  stack <int> s;
  int span[days];
  span[0] =1;
  s.push(0);

 for(int i=1; i<days; i++){
   while(price[i] >= price[s.top()])
        s.pop();

    if(s.empty())
      span[i] = i+1;
    else
      span[i] = i-s.top();
  s.push(i);

 }

 for(int i=0;i<n;i++)
  cout<<span[i]<<" ";
}

int main(){

  int days;
  cout<<"Number of days=?"<<endl;
  cin>>days;
  int price[days];

  cout<<"Please enter the values"<<endl;
  for(int i=0;i<days;i++)
    cin>>price[i];
  int *p = stock_span(price,days);




  cout<<endl;
  return 1;
}
