//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int isPalindrome(char* s) {
//	int i;
//	int j = 0;
//	int m = strlen(s);
//	char* ch = (char*)malloc(strlen(s) + 1);
//	for (i = 0; i < m; i++) {
//		if (s[i] >= 'A' && s[i] <= 'Z') {
//			s[i] = s[i] + 32;
//		}
//		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
//			ch[j] = s[i];
//			j++;
//		}
//	}
//	int left = 0;
//	int right = j;
//	for (i = 0; i < j / 2; i++) {
//		if (ch[left] != ch[right-1]) {
//			return 0;
//		
//		}
//		else {
//			left++;
//			right--;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	char s[] = "A man, a plan, a canal: Panama";
//	int a = isPalindrome(s);
//	printf("%d", a);
//	return 0;
//}