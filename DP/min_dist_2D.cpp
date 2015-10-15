#include <iostream>
using namespace std;





int main() {


int n, d;
cin>>n>>d;

int R[n],C[n];
int T[n];

for (int i = 0; i < n; ++i)
{
	cin>>R[i];
}

for (int i = 0; i < n; ++i)
{
	cin>>C[i];
}

for (int i = 0; i <n; ++i)
{
	T[i] = -1;
}

/*for (int i = 1; i <=n; ++i)
{
	cout<<R[i]<<" ";
}
cout<<endl;
for (int i = 1; i <=n; ++i)
{
	cout<<C[i]<<" ";
}

*/



for (int i = 0; i < n; ++i)
{
		
	int minCost = -1;
	int cost = 0;
	for (int j = 0; j < n; ++j)
	{

//		cout<<R[i]<<endl;
		if(R[i]+R[j] >= d){

			if(T[i] == -1){
				minCost = C[i] + C[j];
				T[i] = j;
			}
			else {
					if(minCost > C[i] + C[j]){

						minCost = C[i] + C[j];
						T[i] = j;
					}
					else if (minCost == C[i] + C[j])
					{
		
						if(R[j] > R[T[i]]){
								T[i] = j;
						}
						/*else if(R[j] == R[T[i]]){
								;
						}*/

					}
			}
		}

	}

	if(minCost == -1){
		T[i] = 0;
		cout<<T[i]<<" ";
	}
	else{
		cout<<T[i]+1<<" ";
	}


}





return 0;
}