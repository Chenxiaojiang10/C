#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void reverse_string(char* str, int size, int left, int right) {
	if (left < right) {
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
		reverse_string(str, size, left, right);
	}
}

int main() {
	char str[] = {'a','b','c','d','e'};
	int size = sizeof(str)/sizeof(str[0]);
	int left = 0;
	int right = size - 1;
	reverse_string(str, size, left, right);
	for (int i = 0; i < size; ++i) {
		printf("%c ", str[i]);
	}
	return 0;
}