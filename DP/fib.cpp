#include <iostream>

using namespace std;

int calls;
int calls2 = 0;	
	
	int cache[100000] = {-1};


int fib(int n){

	calls++;
	if(n<2)
		return 1;
	return fib(n-1) + fib(n-2);

}

int fib_fast(int n){

	if(n == 1 || n == 0)
		return 1;
	
	calls2++;
	
	if (cache[n] != -1)
	{
		return cache[n];
	}

	cache[n] = fib_fast(n-1) + fib_fast(n-2);

	
	return cache[n];
}


int main(){

	int n = 30;

	cout<<"Normal fibinacci Value="<<fib(n)<<endl;
	
	cout<<"Calls = "<<calls<<endl;

	calls = 0;
	cout<<"Memoized fibinacci Value="<<fib_fast(n)<<endl;	
	cout<<"Calls = "<<calls2<<endl;	
	
	return 1;

}