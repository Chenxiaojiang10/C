//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////非递归求字符串长度
//int Strlen(char str[]) {
//	int l = 0;
//	while (str[l] != '\0') {
//		l++;
//	}
//	return l;
//}
////使用递归求字符串长度
//int strlens(char* str) {          
//	int i = 0;
//	if (str[i] == '\0') {
//		return 0;
//	}
//	return 1 + strlens(str + 1);
//}
//int main() {
//	char str[] = "english";
//	int m = Strlen(str);
//	int n = strlens(str);
//	printf("%d\n%d", m, n);
//	return 0;
//}