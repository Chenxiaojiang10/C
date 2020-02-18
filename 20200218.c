#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
	int b = strlen(s);
	if (b == 0) {
		return 0;
	}
	for (int i = b - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			return b - i - 1;
		}
	}
	return b;
}

int main() {
	char s[] = "e";
	int a = lengthOfLastWord(s);
	printf("%d", a);
	return 0;
}