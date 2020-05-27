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
		printf("字符串全为0\n");
	}
	else
	{
		printf("字符串不全为0\n");
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
	switch (pid = fork()) { // 创建子进程
	case -1:
		printf("当前shell出现故障，正在维护中...\n");
		return;
	case 0: {
		int ret = execvp(argv[0], argv); // 子进程中用argv[0],也就是我们输入的命令替换子进程的空间
		printf("%s : command not found\n", argv[0]);
		exit(1);
	}
		  break;
	default: {
		int status;
		waitpid(pid, &status, 0); // 父进程等待子进程死亡
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
	do_action(argc, argv); // 执行命令
}
int main(void) {
	char buf[512];
	while (1) {
		printf("[taoge shell] # ");
		if (get_input(buf) == 0) // 读取一行数据
			continue;
		do_parse(buf); // 解析数据
	}
}

