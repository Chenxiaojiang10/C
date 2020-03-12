//#include<stdio.h>
//typedef int(*Cmp)(int, int);
//void bubble(int* arr, int s, Cmp cmp) {
//	int i, j;
//	for (i = 0; i < s-1; i++) {
//		for (j = 0; j < s - 1 - i; j++) {
//			if (cmp(arr[j], arr[j + 1]) == 0) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int Less(int a, int b) {
//	return a < b ? 1 : 0;
//}
//
//int Greater(int a, int b) {
//	return a > b ? 1 : 0;
//}
//
//int main() {
//	int arr[] = { 1,5,9,7,3,6 };
//	int s = sizeof(arr) / sizeof(arr[0]);
//	bubble(arr, s, Less);
//	int i;
//	for (i = 0; i < s; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}