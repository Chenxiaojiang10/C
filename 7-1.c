//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
////쳲��������У��õݹ麯��ʵ��
//int fib1(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 1;
//	}
//	return fib1(n - 1) + fib1(n - 2);
//}
//
////���õݹ飬ʵ��쳲���������
//int fib2(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 1;
//	}
//	int x = 0;
//	int num1 = 1;   //��ǰ��ǰ��һ�����ֵ
//	int num2 = 1;   //��ǰ��ǰ���������ֵ
//	for (int i = 3; i <= n; i++) {
//		x = num1 + num2;
//		num2 = num1;
//		num1 = x;
//	}
//	return x;
//}
//int main() {
//	printf("����Ҫ쳲����������еĵڼ���Ԫ�أ�");
//	int a = 0;
//	scanf("%d", &a);
//	int f = fib1(a);
//	printf("%d\n", f);
//	int x = fib2(a);
//	printf("%d", x);
//	return 0;
//}