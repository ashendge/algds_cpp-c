/*If I take two for loops then it would be a O(n^2) solution */

#include <stdio.h>

int dup(int a[],int n){

	int i,j;
	for(i=0;i<n;i++)
	    {
	
		for(j=i+1;j<n;j++)
		{

			if(a[i]==a[j])	
			printf("Duplicate %d-%d\n ",a[i],a[j]);	

		}
	
	    }	
	

	

	}


int main(){
	int n = 6;
	int a[6]={1,4,4,1,4,2};
	dup(a,n);

	return 1;


	}

