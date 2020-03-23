#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_Strncat(char* destination, const char* source, size_t num) {
	if (destination == NULL || source == NULL) {
		return NULL;
	}
	int cur = 0;
	while (destination[cur] != '\0') {
		cur++;
	}
	size_t i = 0;
	while ( i < num && source!='\0') {
		destination[cur + i] = source[i];
		i++;
	}
	destination[cur + i] = '\0';
	return destination;
}

int my_Strncmp(const char* str1, const char* str2, size_t num) {
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0'&& 1 < num) {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			str1++;
			str2++;
			num--;
		}
	}//出while循环代表起码有一个字符串遇到‘\0’了
	if (*str1 > * str2) {
		return 1;
	}
	else if (*str1 < *str2) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	char str1[20] = "abcde";
	char str2[20] = "abclk";
	int a = my_Strncmp(str1, str2, 3);
	printf("%d", a);
	
	my_Strncat(str1, str2, 4);
	printf("%s", str1);
	return 0;
}