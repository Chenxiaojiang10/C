#include<stdio.h>

int main() {
	int i = 0;
	int arr1[] = { 0,1,2,3,4 };
	int arr2[] = { 5,6,7,8,9 };
	while (i<=(sizeof(arr1)/4)) {
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr2[i] ^ arr1[i];
		arr2[i] = arr1[i] ^ arr2[i];
		i++;
	}
	printf("�����������1��");
	for (i = 0; i < 5; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n�����������2��");
	for (i = 0; i < 5; i++) {
		printf("%d ", arr2[i]);
	}
	return 0;
}