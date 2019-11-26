#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void leapyear(int i) {
	if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
		printf("是闰年！\n");
	}
	else {
		printf("不是闰年!");
	}
}
int main() {
	printf("输入一个年份来判断是不是闰年：");
	int a = 0;
	scanf("%d", &a);
	leapyear(a);
	return 0;
}