#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	printf("------------------------\n");
	printf("������һ������ʼ�£�1-100��\n");
	printf("------------------------\n");
	srand((unsigned int)time(0));
	int r = rand() % 100 + 1;    //�����������ΧΪ1-100
	while (1) {
		int guess = 0;
		scanf("%d", &guess);
		if (guess < r) {
			printf("���ˣ�\n");
		}else if (guess > r) {
			printf("���ˣ�\n");
		}
		else {
			printf("����ˣ�");
			break;
		}
	}
	return 0;
}