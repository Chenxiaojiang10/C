#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void leapyear(int i) {
	if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
		printf("�����꣡\n");
	}
	else {
		printf("��������!");
	}
}
int main() {
	printf("����һ��������ж��ǲ������꣺");
	int a = 0;
	scanf("%d", &a);
	leapyear(a);
	return 0;
}