#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	int temp;
	printf("请输入两个数：\n");
	scanf("%d,%d",&a,&b);

	if (a < b) {
		b = a ^ b;
		a = b ^ a;
		b = a ^ b;
	}

	while (a % b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	printf("最大公约数为：%d\n",b);
	return 0;
}