#include <stdio.h>

/*Rememberto be careful about printing and calculating derivative.			
 * Struct can be used. As it will save a lot pf memory
 *
 *
 *
 *
 * */

calc_derrivative(int ,int );


int main()
{
   int poly[50];	
   int n,i;			/*Declare an Array to hold a polynomial !*/


printf("Enter the degree of the polynomial ");	
scanf("%d",&n);
//n=n+1;
	
printf("/nEnter the polunomial/n");
for(i=0;i<=n;i++)
{

scanf("%d",&poly[i]);
}

for(i=n;i>=0;i-- )
{
	
printf("%dX[%d] + ",poly[i],i);

}

calc_derivative(poly,n);
return 0;
}
/*	CODE FOR DERRIVATIVE		*/

	void calc_derivative(int poly[],int n){

		int j=1;
		int i;
		do
		{	poly[j-1]=poly[j]*j;
			j++;			
		}while(j<=n);
		printf("\n");

		for(i=n;i>0;i--)
		{
			printf("%dX^%d + ",poly[i-1],i-1);
		}
}
