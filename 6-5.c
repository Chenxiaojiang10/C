#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void Odd(int a) {
	int i = 2;
	int s = sqrt(a);
	while (i < s) {
		if (a % i == 0) {
			printf("����������");
			break;
		}i++;
	}
	if (i >= s) {
		printf("��������");
	}
}
int main() {
	printf("����һ�������ж����ǲ���������");
	int a = 0;
	scanf("%d",&a);
	Odd(a);
	return 0;
}