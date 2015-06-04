#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

	int p = 10;
	int *x;

	x= &p;
	
		
	cout<<"Value="<<*x<<endl;

	cout<<"AddX of integer="<<x<<endl;
	cout<<"Address of the pointer="<<&x<<endl;


	
	return 0;
}