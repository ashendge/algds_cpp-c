#include <iostream>
#include <queue>
using namespace std;

int main(){
	long long N;

	cin>>N;
	priority_queue<long long> q;

	for(int i=0;i<N;i++){
		long long a;
		long long temp1,temp2,temp3;
		cin>>a; 
		q.push(a);
		if(q.size()<3)
			cout<<"-1"<<endl;
		else{

			temp1 = q.top();
			q.pop();
			
			temp2 = q.top();
			q.pop();

			temp3 = q.top();
			q.pop();

			q.push(temp1);
			q.push(temp2);
			q.push(temp3);

			cout<<(temp3*temp2*temp1)<<endl;
		}

}	
		

	}

