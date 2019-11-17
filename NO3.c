#include<stdio.h>

int main() {
	int j = 0;
	int i;
	for (i = 1; i < 10; i++) {
		if (i == 9) {
			j++;
		}
	}
	for (i = 10; i < 101; i++) {
		if (i % 10 == 9) {
			j++;
		}
		if (i / 10 == 9) {
			j++;
		}
	}
	printf("100中9的个数为:%d\n", j);
	return 0;
}