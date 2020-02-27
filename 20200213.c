//#include<stdio.h>
//#include<stdlib.h>
//
//int* sortedSquares(int* A, int ASize, int* returnSize) {
//	int i, j;
//	/*if (re == NULL) {
//		printf("error!\n");
//		exit(1);
//	}
//	for (i = 0; i < ASize; i++) {
//		*re++ = 0;
//	}*/
//	for (i = 0; i < ASize; i++) {
//		if (A[i] < 0) {
//			A[i] = -A[i];
//		}
//		else {
//			A[i] = A[i];
//		}
//	}
//	for (i = 0; i < ASize ; i++) {
//		for (j = i + 1; j < ASize ; j++) {
//			if (A[j] > A[j + 1]) {
//				int tmp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = tmp;
//			}
//		}
//	}
//	*returnSize = ASize;
//	int* re = (int*)malloc(ASize * sizeof(int));
//	for (i = 0; i < ASize; i++) {
//		re[i] = A[i] * A[i];
//	}
//	return re;
//	/*short i = 0, j, min, min_index;
//	while (i < ASize && A[i] < 0) {
//		A[i] = -A[i];
//		i++;
//	}
//	for (i = 0; i < ASize; i++) {
//		min = A[i];
//		min_index = i;
//		for (j = i + 1; j < ASize; j++) {
//			if (A[j] < min) {
//				min = A[j];
//				min_index = j;
//			}
//		}
//		j = A[i];
//		A[i] = min;
//		A[min_index] = j;
//	}
//	*returnSize = ASize;
//	int* res = (int*)malloc(ASize * sizeof(int));
//	for (i = 0; i < ASize; i++) res[i] = A[i] * A[i];
//	return res;*/
//}
//
//int main() {
//	int A[6] = { -4,-1,0,3,5,8 };
//	int ASize = 6;
//	int* returnSize=0;
//	int* p=sortedSquares(A, ASize, returnSize);
//	for (int i = 0; i < *returnSize; i++) {
//		printf("%d ", p[i]);
//	}
//	return 0;
//}