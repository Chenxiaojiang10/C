#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	printf("------------------------\n");
	printf("请输入一个数开始猜（1-100）\n");
	printf("------------------------\n");
	srand((unsigned int)time(0));
	int r = rand() % 100 + 1;    //设置随机数范围为1-100
	while (1) {
		int guess = 0;
		scanf("%d", &guess);
		if (guess < r) {
			printf("低了！\n");
		}else if (guess > r) {
			printf("高了！\n");
		}
		else {
			printf("答对了！");
			break;
		}
	}
	return 0;
}