#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//一个序列最少有几个有序子序列
int func(int* a, int size) {
	int i = 0;
	int cont = 0;
	while (i < size) {
		//相同往后走一位
		if (a[i] == a[i + 1]) {
			i++;
		}
		// 递增的子序列
		else if (a[i] < a[i + 1]) {
			i++;  //用头两个判断出来时递增还是递减
			//再进入while，看第三个数字及以后的是数字是否满足递增
			while (1) {
				if (a[i] <= a[i + 1]) {
					i++;
				}
				//发现开始递减了，打断，并且cont++
				else {
					cont++;
					i++;
					break;
				}
			}
		}
		//递减的子序列
		else if (a[i] > a[i + 1]) {
			i++;
			while (1) {
				if (a[i] > a[i + 1]) {
					i++;
				}
				else {
					cont++;
					i++;
					break;
				}
			}
		}
	}
	return cont;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int q = func(a, n);
	printf("%d\n", q);
	return 0;
}