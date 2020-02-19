#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverseOnlyLetters(char* S) {
	int i;
	int j = 0;
	int n = strlen(S);
	char* ch = (char*)malloc(strlen(S) + 1);
	for (i = 0; i < n; i++) {
		if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
			ch[j] = S[i];
			j++;
			S[i] = ' ';
		}
	}
	for (i = 0; i < n; i++) {
		if (S[i] == ' ') {
			S[i] = ch[j-1];
			j--;
		}
	}
	return S;
}

int main() {
	char S[] = "Test1ng-Leet=code-Q!";
	char* p = reverseOnlyLetters(S);
	
	puts(S);
	return 0;
}