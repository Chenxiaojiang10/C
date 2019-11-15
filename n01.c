#include<stdio.h>

int main() {
	double result = 1;
	double i, a;
	double n = 100;
	for (i = 1; i <= n; i++) {
		a = 1 / (1 + i);
		result = result - a;
	}
	printf("result=%f\n", result);
	return 0;
}