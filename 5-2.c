//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,11 };
//	int left = 0;
//	int right = sizeof(arr) / 4;
//	int a;
//	scanf("%d", &a);
//	while (right >= left) {
//	int mid = (left + right) / 2;
//	 if (a < arr[mid]) {
//		right = mid - 1;
//	}
//	 if (a > arr[mid]) {
//		left = mid + 1;
//	}
//	 if (a == arr[mid]) {
//		 printf("你要的数字的下标是%d", mid);
//		 break;
//	 }
//	}
//	if (left > right) {
//		printf("没有这个数字！");
//	}
//	return 0;
//}