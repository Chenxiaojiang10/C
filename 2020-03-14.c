#include<stdio.h>
#include<string.h>
#include<assert.h>
const char* my_Strstr(const char* str1, const char* str2) {
	assert(str1 != '\0' && str2 != '\0');
	if (str2 == '\0') {   //防止str2是空字符串
		return NULL;
	}
	char* black = str1;
	while (*black != '\0') {
		char* red = black;
		char* sub = str2;
		while (*red != '\0' && *sub != '\0' && (*red == *sub)) {
			//跳出这个while的前提是red跑完了，或者sub跑完了，亦或者*sub不等于*red
			red++;
			sub++;
		}
		//sub跑完了,那就找到了，返回black
		if (*sub == '\0') {
			return black;
		}
		//red跑完了,那就是没找到
		if (*red == '\0') {
			return NULL;
		}
		//两者不相等，black往后移一位继续比
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