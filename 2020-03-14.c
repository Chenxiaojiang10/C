#include<stdio.h>
#include<string.h>
#include<assert.h>
const char* my_Strstr(const char* str1, const char* str2) {
	assert(str1 != '\0' && str2 != '\0');
	if (str2 == '\0') {   //��ֹstr2�ǿ��ַ���
		return NULL;
	}
	char* black = str1;
	while (*black != '\0') {
		char* red = black;
		char* sub = str2;
		while (*red != '\0' && *sub != '\0' && (*red == *sub)) {
			//�������while��ǰ����red�����ˣ�����sub�����ˣ������*sub������*red
			red++;
			sub++;
		}
		//sub������,�Ǿ��ҵ��ˣ�����black
		if (*sub == '\0') {
			return black;
		}
		//red������,�Ǿ���û�ҵ�
		if (*red == '\0') {
			return NULL;
		}
		//���߲���ȣ�black������һλ������
		black++;
	}
	return NULL;
}


int main()
{
	char str1[] = "hello world";
	char str2[] = "world";
	printf("%p %p", str1, my_Strstr(str1, str2));
	return 0;
}