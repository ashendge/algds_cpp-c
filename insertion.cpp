#include <iostream>
#include <cstdlib>

using namespace std;
void print(int , int );
void insert_sort(int[] ,int );

int main(int argc, char* argv[]){

	int n;

	n = atoi(argv[1]); 	/*number of elements in the array to be sorted*/

	int a[10];
	
	
	cout<<"Enter the elements in the array\n";

	for(int i=0;i<n;i++)
	{
		cin>>a[i];

	}

	cout<<"Unsorted array\n";
	print(a,n);

	insert_sort(a,n);		


}

void print(int a[], int n){

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" " ;
	}
	cout<<endl;
}

void insert_sort(int a[],int n){


		int i,j;

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j>=1;j--)
			{
				if(a[j]<a[j-1])
				{
					int temp = a[j];
					a[j] = a[j-1];
					a[j-1]= temp;
				}
			}
		}

		cout<<"Sorted array:\n";
		print(a,n);

}