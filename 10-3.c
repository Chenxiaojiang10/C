#include<stdio.h>

void printARR(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
	
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	//����1������һ����ά����
	/*int arr[10][10] = { 0 };
	int j, i = 0;
	for (i = 0; i < 10; i++) {
		arr[i][0] = 1;
		for (j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
    }*/
 
	//����2��ֻ��һ��һά���������⣬��̬�滮
	int arr[10] = { 1 };
	int i, j;
	printf("1\n");
	for (i = 1; i < 10; i++) {
		for (j = i; j > 0; j--) {
			arr[j] += arr[j - 1];
		}
		printARR(arr, i + 1);
	}
	return 0;
}