#include <stdio.h>

int cal_angle(int , int );

int cal_angle(int h, int m){

	int Hangle,Mangle;

	Hangle= h*5*6;
	Mangle=m*6;
 	if(Mangle > Hangle)
	return (Mangle - Hangle);
	else
	return (Hangle - Mangle);
	
}

int main(){

int h,m;

	printf("Enter the time");
	scanf("%d",&h);		
	scanf("%d",&m);
	 
	printf("\nAngel= %d",cal_angle(h,m));


}

