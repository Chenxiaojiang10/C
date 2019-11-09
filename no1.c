#include <stdio.h>
#include<math.h>

int main() {
	int i;
	int n,p;
	double j;
	for (i = 100; i <= 200; i = i + 1) {
		j = sqrt(i);
	    for (n = 2; n <= j; n=n+1) 
			if(i % n==0)
				break;
		    if(n>j)
		        printf("%d\n", i);
	}
	return(0);
}

