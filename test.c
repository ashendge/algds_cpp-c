#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char []);


void compress(char str[]){

	char newstr[]="";
	char temp;
	char buff;
	int count = 1; int len = strlen(str); int i,j;
	
	temp = str[0];
	printf("%c",temp);
	for(i=1;i<len;i++){

		if(i!=len && str[i]==temp)
			count++;
		else{
			strcat(newstr,temp);	
			strcat(newstr,count);
			temp = str[i];
			count = 1;  	
			
	
		}
		
	
	}
			
	if(strlen(newstr)==strlen(str))	
		printf("%s",str);
	else
		printf("%s",newstr);





}

int main(){

char str[]="aaabbcddddf";


return 0;

}



