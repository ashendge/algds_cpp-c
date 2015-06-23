#include <iostream>

using namespace std;

int partition(int [],int ,int );
void quick_sort(int [], int , int);
void swap(int *,  int *);
void print(int a[], int n);

int main(){

	int arr[] ={1,9,2,8,3,7};
	//cout<<"Size of arra="<<(sizeof(arr)/sizeof(*arr))<<endl;
	print(arr, (sizeof(arr)/sizeof(arr[0])));
	cout<<endl;	
	
	quick_sort(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
	
	print(arr, (sizeof(arr)/sizeof(arr[0])));
	cout<<endl;	
	return 1;	
}

void quick_sort(int arr[], int l, int r){

	if(l<r){
		int p_index = partition(arr,l,r);
		quick_sort(arr,l,p_index-1);
		quick_sort(arr,p_index+1,r);
	}
}

int partition(int arr[], int l, int r){
	int pivot = arr[r];
	//cout<<"Pivot="<<pivot<<endl;
	int i = l-1;
	for(int j=l;j<r;j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	cout<<"Pivot Swap start*****\n";
	swap(&arr[i+1],&arr[r]);	
	cout<<"Pivot Swap End*****\n";
	return i+1;
}	

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	cout<<"a ="<<*a<<" b="<<*b<<" temp ="<<temp<<endl;
}	
void print(int a[], int n)
{
    int i=0;
    while(i<n){
        cout<<a[i]<<",";
        i++;
    }
}
