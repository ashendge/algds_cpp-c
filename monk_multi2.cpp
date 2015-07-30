/*Monk was asked to answer some queries in an interview. He is given an empty array A. Queries are of 4 types:-
1. 1 X - Add number X to the array A.
2. 2 X - Remove a single instance of number X from the array A. If not possible, print "-1" without the quotes.
3. 3 - Find the maximum element in the array A.
4. 4 - Find the minimum element in the array A.

Input:
The first line contains the integer Q.
The next Q lines will each contain a query like the ones mentioned above.

Output: 
For queries 3 and 4, print the answer in a new line. If the array is empty for query 3 and 4, then print "-1" without the quotes.

Constraints:
1 <= Q <= 100000
1 <= X <= 100000*/

#include <iostream>
#include <queue>

using namespace std;



int cnt[100009];
int main(){

	int Q;
	priority_queue<int> max;
	priority_queue<int> min;

	cin>>Q;
	int x;
	int op;
	while(Q--){
		cin>>op;

		if(op==1){
			cin>>x;
			cnt[x]++;
			max.push(x);
			min.push(x*(-1));
		}
		else if(op==2){
			cin>>x;
			if(cnt[x]>0){
				cnt[x]--;

			}else{
				cout<<"-1"<<endl;
			}
		}
			else if(op ==3){
			while(max.size()>0 && cnt[max.top()] == 0)
				max.pop();
			if(max.size()>0)
				cout<<max.top()<<endl;
			else
				cout<<"-1"<<endl;

		}
		else{
			while(min.size()>0 && cnt[min.top()*(-1)] == 0)
				min.pop();
			if(min.size()>0)
				cout<<min.top()*(-1)<<endl;
			else
				cout<<"-1"<<endl;

		}		
	
		
	}



	return 0;

}