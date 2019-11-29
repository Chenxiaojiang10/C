//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
////斐波那契数列：用递归函数实现
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
////不用递归，实现斐波那契数列
//int fib2(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	if (n == 2) {
//		return 1;
//	}
//	int x = 0;
//	int num1 = 1;   //当前项前边一项的数值
//	int num2 = 1;   //当前项前边两项的数值
//	for (int i = 3; i <= n; i++) {
//		x = num1 + num2;
//		num2 = num1;
//		num1 = x;
//	}
//	return x;
//}
//int main() {
//	printf("你想要斐波那契数列中的第几个元素：");
//	int a = 0;
//	scanf("%d", &a);
//	int f = fib1(a);
//	printf("%d\n", f);
//	int x = fib2(a);
//	printf("%d", x);
//	return 0;
//}