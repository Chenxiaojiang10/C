#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	int temp;
	printf("��������������\n");
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

	printf("���Լ��Ϊ��%d\n",b);
	return 0;
}