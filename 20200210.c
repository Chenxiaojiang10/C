//#include<stdio.h>
//
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//	int i;
//	int j = 0;
//	for (i = m; i < m + n; i++) {
//		nums1[i] = nums2[j];
//		j++;
//	}
//	for (i = 0; i < m + n - 1; i++) {
//		for (j = 0; j < m + n - 1 - i; j++) {
//			if (nums1[j] > nums1[j + 1]) {
//				int tmp = nums1[j];
//				nums1[j] = nums1[j + 1];
//				nums1[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main() {
//	int nums1[8] = { 1,2,3,4 };
//	int nums2[] = { 2,3,5,6 };
//	int nums1Size = 8;
//	int m = 4;
//	int n = 4;
//	int nums2Size = sizeof(nums2) / sizeof(int);
//	merge(nums1, nums1Size, m, nums2, nums2Size, n);
//	for (int i = 0; i < m + n; i++) {
//		printf("%d ", nums1[i]);
//	}
//
//	return 0;
//}