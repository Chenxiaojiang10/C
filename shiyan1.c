#include<stdio.h>
#include<limits.h>
int main()
{
	int i;
	unsigned int j;
	i = INT_MAX;
	i++;
	printf("i=%d\n", i);




	j = UINT_MAX;
	j++;
	printf("j=%d\n", j);
	i = INT_MIN;
	i--;
	printf("i=%d\n", i);
	j = 0;
	j--;
	printf("j=%u\n", j);
	return 0;

}
