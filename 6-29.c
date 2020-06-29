//#include<stdio.h>
//#include<string.h>
//
//void delStr(char* str, int i, int s) {
//	while (i < s) {
//		char tmp = str[i];
//		str[i] = str[i + 1];
//		str[i + 1] = tmp;
//		i++;
//	}
//}
//
//char* func(char* str1, char* str2) {
//	int s1 = strlen(str1);
//	int s2 = strlen(str2);
//
//	for (int i = 0; i < s1; i++) {
//		for (int j = 0; j < s2; j++) {
//			if (str1[i] == str2[j]) {
//				delStr(str1, i, s1);
//				s1--;
//			}
//		}
//	}
//
//	str1[s1] = '\0';
//	return str1;
//}
//
//int main() {
//	char buf1[1024];
//	char buf2[1024];
//	gets(buf1);
//	gets(buf2);
//	func(buf1, buf2);
//
//	printf("%s\n", buf1);
//}