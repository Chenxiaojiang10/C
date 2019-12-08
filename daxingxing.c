#include<stdio.h>

int main() {
	int a = 0;
	int i, j;
	int n = 7;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			putchar(' ');
		}
		for (j = 0 ; j < 2 * i - 1; j++) {
			putchar('*');
		}
		printf("\n");
	}
	//反着再来一遍，n-1是为了消除重复的一行
	for (i = n - 1; i >= 1 ; i--) {
		for (j = 1; j <= n - i; j++) {
			putchar(' ');
		}
		for (j = 0; j < 2 * i - 1; j++) {
			putchar('*');
		}
		printf("\n");
	}
	return 0;
}