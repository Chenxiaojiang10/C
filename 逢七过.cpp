#include<stdio.h>
int main()
{
	int x,m,i;
	printf("please enter a number:");
	scanf("%d",&x);
	for(i=1;i<100;i++)
	  {m=++x;
	    if((m%7==0)||(m==7)||(m%10==7))
	      printf("¹ý ");
	    else 
	      printf("%d ",x);
	    if(i%10==0) putchar('\n');
      }  
	return 0;
 } 
