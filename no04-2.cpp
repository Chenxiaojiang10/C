#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//处理10以内的进制
void func1(int m, int n) {
	int a[32] = { 0 };
	int i = 0;
	while (m > 0)
	{
		a[i] = m % n;
		m = m / n;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		printf("%d", a[j]);
}
//处理16进制
void func2(int m, int n) {
	int a[32] = { 0 };
	int i = 0;
	while (m > 0)
	{
		a[i] = m % n;
		m = m / n;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		if (a[j] >= 10) {
			printf("%c", a[j] + 55);
		}
		else {
			printf("%d", a[j]);
		}
	printf("\n");
}


int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (b < 10) {
		func1(a, b);
	}
	else {
		func2(a, b);
	}
	return 0;
}
