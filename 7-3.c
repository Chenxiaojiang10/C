//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
////顺序打印各个数字的递归函数
//void printnum(int n) {
//	if(n > 9) {
//		printnum(n / 10);
//		
//	}
//	printf("%d  ", n%10);
//}
////求各数位之和的递归函数
//int sumnum(int n) {        
//	if (n < 10) {
//		return n;
//	}
//	return n % 10 + sumnum(n / 10);
//}
//int main() {
//	printf("顺序打印一个数字的各个位，并计算各个位数字之和：");
//	int a = 0;
//	scanf("%d", &a);
//	printnum(a);
//	int b = sumnum(a);
//	printf("\n各个数位之和位%d", b);
//	return 0;
//}