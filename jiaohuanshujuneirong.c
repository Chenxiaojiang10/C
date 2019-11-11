#include <stdio.h>

int main() {
	int a = 10, b = 20;
	int c;
	c = a;
	a = b;
	b = c;
	printf("a=%d\nb=%d\n", a, b);
	return(0);
}