#include <stdio.h>

void replace( int len, char str[] ){

	int i,j,spaceCount,x,total_len,real_len;
	i=0;j=0;
	total_len=0;
	spaceCount=0;
	real_len=0;

	while(str[i]!='\0'){
			
			total_len++;		
			if(str[i]==' ')
			spaceCount++;
			i++;
	     }

	x = total_len - len;
	spaceCount = spaceCount - x;
	//printf("%d",spaceCount);
	
	real_len =len + 2*spaceCount;
	
	/* Implementing the repalce function   */

	for(i=len-1,j=real_len-1;i>=0;i--,j--)
		{
	
			if(str[i]==' '){
				
				str[j]='0';
				printf("%d\n",j);
				str[--j]='2';
				printf("%d\n",j);
				str[--j]='%';	
				printf("%d\n",j);

			}	
				else
				str[j]=str[i];

		}
		str[real_len]='\0';
	//for(i=0;i<real_len;i++)
	printf("%s",str);	
	
	//printf("\n%d %c\n",real_len,str[17]);
	
}


int main(){

	char str[]="Mr John Smith      ";
	int len = 13;

	printf("Original string=>%s\n",str);
	replace(len,str);


}


