#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	for (int i = 1; i < 4; i++) {
	char pwd[1000] = { 0 };
	printf("�����������룺");
	scanf("%s", pwd);
	if (strcmp(pwd, "123456") == 0) {
		printf("��½�ɹ���");
		break;
	}
	else {
		printf("�������\n");
		}
	}
	return 0;
}
