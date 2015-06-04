/*	Detect if two integers have opposite signs	*/

#include <stdio.h>

int isopp(int , int );


void main()
{

	
	if(isopp(4,-5)>1)
	printf("The signs are oppostire");
	else
	printf("SASAS");

}


int isopp(int x,int y)
{
return (x ^ y);
;
}
