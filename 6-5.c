#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void Odd(int a) {
	int i = 2;
	int s = sqrt(a);
	while (i < s) {
		if (a % i == 0) {
			printf("不是素数！");
			break;
		}i++;
	}
	if (i >= s) {
		printf("是素数！");
	}
}
int main() {
	printf("输入一个数来判断它是不是素数：");
	int a = 0;
	scanf("%d",&a);
	Odd(a);
	return 0;
}