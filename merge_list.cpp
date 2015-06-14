#include <iostream>
using namespace std;

void merge_sort(int [], int ,int );
void merge(int [], int ,int ,int );
void printArray(int [], int );
int main(){

	int arr[] = {77,55,4,88,21,0,1,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printArray(arr, size);
	merge_sort(arr,0,size-1);
	printArray(arr, size);

}
void printArray(int arr[], int size){

		for(int i=0;i<size;i++){

			cout<<arr[i]<<" ";

		}
		cout<<endl;
}

void merge_sort(int arr[], int l, int r){

	if(l<r){

			int m = (l+r)/2;
			merge_sort(arr,l,m);
			merge_sort(arr,m+1,r);
			merge(arr,l,m,r);

	}

}
void merge(int arr[], int l, int m, int r){

	int i=0, j=0, k=0;
	int n1=0, n2=0;

	n1 = m-l+1;
	n2 = r-m;
	int left[n1];
	int right[n2];

	for(int p=0; p<n1; p++)
		left[p] = arr[l+p];
	for(int q=0; q<n2; q++)
		right[q] = arr[m+1+q];

	k = l;

	while(i<n1 && j<n2){

		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;	
		}
		else{
			arr[k] = right[j];
			j++; 
		}
		k++;
	}	

	while(i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}

}
