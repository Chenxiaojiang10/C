//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
////��ת�ַ������������ַ�˳�򲻱䣬������˳��ת��������������ڵķ���
//void func(char* str, int size) {
//	char* tmp = (char*)malloc(size + 1);
//
//	int s1 = size - 1;
//	int s2 = size - 1;
//	int i = 0;
//
//	while (s2 >= 0) {
//		//�Ӻ���ǰ�ҵ��ո�
//		
//		while (s1 >= 0 && str[s1] != ' ') {
//			s1--;
//		}
//		int k = s1;
//
//
//		//��һ�����ʵĴ���
//		if (s1 < 0 ) {
//			//��һ������ֻ��һ���ַ�
//			if (s2 == 0) {
//				tmp[i] = str[0];
//			}
//			//��һ�������ж���ַ�
//			else {
//				for (int j = 0; j < s2 - k; j++) {
//					s1++;
//					tmp[i] = str[s1];
//					i++;
//				}
//			}
//			//��tmp�ַ���ĩβ����\0
//			tmp[size] = '\0';
//			printf("%s", tmp);
//			break;
//		}
//		//���ǵ�һ������
//		else {
//			//��������ʴ�����ʱ����
//		
//			for (int j = 0; j < s2 - k; j++) {
//				s1++;
//				tmp[i] = str[s1];
//				i++;
//			}
//			//��������ʺ�߲�һ���ո�
//			if (i < size) {
//				tmp[i] = ' ';
//				i++;
//			}
//			
//		}
//		//ָ����ո�ǰ������
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