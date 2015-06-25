
/*
Link to the problem:

https://www.hackerearth.com/problem/algorithm/biased-chandan/description/

*/
#include <iostream>
#include <stack>
 using namespace std;


long sum_ratings(int a[], int n){
	stack <long> s;
	long sum = 0;
	int i=0;

	for(int i=0;i<n;i++){
		if(a[i] > 0){
			s.push(a[i]);
		}
		else if(a[i] == 0){
			if(!s.empty())
			s.pop();
		}
	}
	while(!s.empty())
	{	
		sum += s.top();
		s.pop();
	}

	
	return sum;
}

 int main(){
 	int n = 0;
 	cin>>n;
 	int a[n];
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}
 	cout<<sum_ratings(a,n);

 }