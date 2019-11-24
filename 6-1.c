#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void mul(int i) {
	for (i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d x %d = %d  ", i, j, i * j);
		}
		printf("\n");
	}

}
int main() {
	printf("输入一个数，得到它的乘法表：\n");
	int a = 0;
	scanf("%d", &a);
	mul(a);
	return 0;
}