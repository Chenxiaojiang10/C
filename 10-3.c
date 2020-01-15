#include<stdio.h>

void printARR(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
	
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	//方法1：开辟一个二维数组
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
 
	//方法2：只用一个一维数组解决问题，动态规划
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