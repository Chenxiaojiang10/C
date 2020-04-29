#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
const char* PASSWORD = "123456789";
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
	pasOk = CheckPassword("123412341234155555555");

	if (pasOk)
	{
		printf("password is correct\n");
	}
	else
	{
		printf("password is incorrect\n");
	}
	return 0;
}
