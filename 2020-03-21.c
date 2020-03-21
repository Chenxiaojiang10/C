#include<stdio.h>

void FindNumTwo(int* arr,int size,int* num1,int* num2) {
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {   //
		sum ^= arr[i];
	}

	int p;
	for (p = 0; p < 32; p++) {
		if ((sum & (1 << p)) != 0) {
			break;
		}
	}

	for (i = 0; i < size; i++) {
		if ((arr[i] & (1 << p)) == 0) {
			*num1 ^= arr[i];
		}
		else {
			*num2 ^= arr[i];
		}
	}
}


int main() {
	int arr[] = { 1,1,2,2,3,3,5,6 };
	int num1 = 0;
	int num2 = 0;
	int size = 8;
	FindNumTwo(arr, size, &num1, &num2);
	printf("%d %d", num1, num2);
	return 0;
}