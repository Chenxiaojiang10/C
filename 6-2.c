#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void exchange(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
	printf("%d  %d\n", a, b);
}
int main() {
	exchange(11, 12);
	return 0;
}