#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
const char* PASSWORD = "00000000000";
int CheckPassword(char* password)
{
	int passOk = 0;
	char buffer[12] = { 0 };
	passOk = (0 == strcmp(password, PASSWORD));
	strcpy(buffer, password);

	printf("[%s]\n", buffer);
	return passOk;
}
int  main(int argc, char* argv[])
{
	int pasOk = 0;
	char str[12] = { 0 };
	scanf("%s", str);
	pasOk = CheckPassword(str);

	if (pasOk)
	{
		printf("�ַ���ȫΪ0\n");
	}
	else
	{
		printf("�ַ�����ȫΪ0\n");
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/wait.h>

#define ERR_EXIT(msg)\
	do{
		printf("[%s][%d] %s:%s\n", __FILE__, __LINE__, msg, strerror(errno)); \
		exit(EXIT_FAILURE);\
	}while(0)

int get_input(char* buf) {
	memset(buf, 0x00, sizeof(buf));
	if (scanf("%[^\n]%*c", buf) != 1) {
		int c;
		do c = getchar(); while (c != '\n');
	}
	return strlen(buf);
}
void do_action(int argc, char* argv[]) {
	pid_t pid;
	switch (pid = fork()) { // �����ӽ���
	case -1:
		printf("��ǰshell���ֹ��ϣ�����ά����...\n");
		return;
	case 0: {
		int ret = execvp(argv[0], argv); // �ӽ�������argv[0],Ҳ������������������滻�ӽ��̵Ŀռ�
		printf("%s : command not found\n", argv[0]);
		exit(1);
	}
		  break;
	default: {
		int status;
		waitpid(pid, &status, 0); // �����̵ȴ��ӽ�������
	}
		   break;
	}
}
void do_parse(char* buf) {
	int argc = 0;
	char* argv[10] = {};
#define OUT 0
#define IN 1
	int status = OUT;
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		if (status == OUT && !isspace(buf[i])) {
			argv[argc++] = buf + i;
			status = IN;
		}
		else if (isspace(buf[i])) {
			status = OUT;
			buf[i] = '\0';
		}
	}
	argv[argc] = NULL;
	do_action(argc, argv); // ִ������
}
int main(void) {
	char buf[512];
	while (1) {
		printf("[taoge shell] # ");
		if (get_input(buf) == 0) // ��ȡһ������
			continue;
		do_parse(buf); // ��������
	}
}

