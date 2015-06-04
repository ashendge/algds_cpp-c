#include <stdio.h>


int main(){



int a[6]={4,6,2,8,0,3};
int i,min_index;

	min_index=0;
	for(i=1;i<5;i++)
	{
		if(a[min_index] > a[i]){
		min_index = i;
		
		}
			
	
	
	}

	printf("%d",min_index);


}

