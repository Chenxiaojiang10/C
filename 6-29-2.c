//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////贪心，求队伍中值德最大值
//void paiXu(int* arr, int size) {
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = 0; j < size - 1 - i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int func(int* arr, int a) {
//	int num = 0;
//	int s = 3 * a;
//	for (int i = 0; i < a; i++) {
//		num = num + arr[s - 2];
//		s -= 2;
//	}
//
//	return num;
//}
//
//int main() {
//	int arr[100];
//	int a = 0;
//	scanf("%d", &a);
//	for (int i = 0; i < 3 * a; i++) {
//		scanf("%d", &arr[i]);
//	}
//	paiXu(arr, 3 * a);
//	int n = func(arr, a);
//	printf("%d\n", n);
//	
//	return 0;
//}