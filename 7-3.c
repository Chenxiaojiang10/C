//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
////˳���ӡ�������ֵĵݹ麯��
//void printnum(int n) {
//	if(n > 9) {
//		printnum(n / 10);
//		
//	}
//	printf("%d  ", n%10);
//}
////�����λ֮�͵ĵݹ麯��
//int sumnum(int n) {        
//	if (n < 10) {
//		return n;
//	}
//	return n % 10 + sumnum(n / 10);
//}
//int main() {
//	printf("˳���ӡһ�����ֵĸ���λ�����������λ����֮�ͣ�");
//	int a = 0;
//	scanf("%d", &a);
//	printnum(a);
//	int b = sumnum(a);
//	printf("\n������λ֮��λ%d", b);
//	return 0;
//}