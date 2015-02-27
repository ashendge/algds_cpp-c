#include <stdio.h>


int main(){

	int a[]={1,4,2,2,3,5,6,6};
	int n=8;
	int b[8]={0};
	int count=1;
	int temp;
	temp = a[0];

	int i=1;int j;	
	while(i<=n){

		if(temp == a[i])
		{ i++; count++;	}
		
		else
		{
		  if(count%2!=0)
		    {//	printf("%d",temp);
			 b[j]=temp; j++;}	
		  count =1;
		  temp = a[i];
		  count = 1;
		  i++; 	
		}	


	}
		
	for(i=0;i<n;i++)
	printf("%d ",b[i]);



}
