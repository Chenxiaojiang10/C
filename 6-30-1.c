//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
////翻转字符串，单词内字符顺序不变，各单词顺序翻转，标点算作单词内的符号
//void func(char* str, int size) {
//	char* tmp = (char*)malloc(size + 1);
//
//	int s1 = size - 1;
//	int s2 = size - 1;
//	int i = 0;
//
//	while (s2 >= 0) {
//		//从后往前找到空格
//		
//		while (s1 >= 0 && str[s1] != ' ') {
//			s1--;
//		}
//		int k = s1;
//
//
//		//第一个单词的处理
//		if (s1 < 0 ) {
//			//第一个单词只有一个字符
//			if (s2 == 0) {
//				tmp[i] = str[0];
//			}
//			//第一个单词有多个字符
//			else {
//				for (int j = 0; j < s2 - k; j++) {
//					s1++;
//					tmp[i] = str[s1];
//					i++;
//				}
//			}
//			//给tmp字符串末尾加上\0
//			tmp[size] = '\0';
//			printf("%s", tmp);
//			break;
//		}
//		//不是第一个单词
//		else {
//			//把这个单词存入临时数组
//		
//			for (int j = 0; j < s2 - k; j++) {
//				s1++;
//				tmp[i] = str[s1];
//				i++;
//			}
//			//给这个单词后边补一个空格
//			if (i < size) {
//				tmp[i] = ' ';
//				i++;
//			}
//			
//		}
//		//指针向空格前继续找
//		s2 = k - 1;
//		s1 = k - 1;
//	}
//	
//	
//	
//}
//
//
//
//int main() {
//	char str[1024];
//	gets(str);
//	int size = strlen(str);
//	
//	func(str, size);
//
//
//	return 0;
//}