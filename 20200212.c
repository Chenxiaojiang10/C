//#include<stdio.h>
//#include<stdlib.h>
//int* sortArrayByParity(int* A, int ASize, int* returnSize) {
//	int i;
//	int max = ASize-1;
//	int min = 0;
//	int* re =(int *) malloc(ASize * sizeof(int));
//	for (i = 0; i < ASize; i++) {
//		if (A[i] % 2 != 0) {
//			re[max--] = A[i];
//		}
//		else if (A[i] % 2 == 0) {
//			re[min++] = A[i];
//		}
//	}
//	*returnSize = ASize;
//	return re;
//}
////力扣上函数段成功了
//int main() {
//	int A[4] = { 3,1,2,4 };
//	int ASize = sizeof(A)/sizeof(int);
//	int* returnSize = 0;
//	int* p = sortArrayByParity(A, ASize, returnSize);
//	for(int i=0;i<4;i++){
//		printf("%d", p[i]);
//	}
//	
//	return 0;
//}