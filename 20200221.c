//#include<stdio.h>
//#include<string.h>
//int compress(char* chars, int charsSize) {
//	if (charsSize == 1) {
//		return 1;
//	}
//	int i;
//	int j = 0;
//	int n = 1;
//	int sum = 1;
//	for (i = 1; i < charsSize; i++) {
//		if (i == charsSize - 1) {
//			if (chars[i] == chars[i - 1]) {
//				n++;
//				while (n > 0) {
//					j++;
//					n /= 10;
//				}
//				return sum + j;
//			}
//			else {
//				while (n > 0) {
//					j++;
//					n /= 10;
//				}
//				return sum + j + 1;
//			}
//		}
//		if (chars[i] == chars[i - 1]) {
//			n++;
//		}
//		else if (chars[i] != chars[i - 1] ) {
//			if (n == 1) {
//				sum++;
//			}
//			else if (n > 1) {
//				while (n > 0) {
//					j++;
//					n /= 10;
//				}
//				sum = sum + j;
//				n = 1;
//			}
//		}
//	}
//	return sum;
//}
//
//int main() {
//	char chars[] = "bbaaal";
//	int charsSize = strlen(chars);
//	int a = compress(chars, charsSize);
//	printf("%d", a);
//	return 0;
//}