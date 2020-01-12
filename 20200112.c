#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


void rotate(int* nums, int numsSize, int k) {
	int arr[10] = { 0 };
	int i = 0;
	if (k == 0) {
		for (i = 0; i < numsSize; i++) {
			printf("%d ", nums[i]);
		}
	}
	else if (k != 0) {
		for (i = 0; i < numsSize; i++) {
			arr[i] = nums[i];
		}
		for (i = 0; i < numsSize; i++) {
			if ((i + k) < numsSize) {
				nums[i + k] = arr[i];
			}
			else if((i + k) >= numsSize) {
				nums[(i + k) - numsSize] = arr[i];
			}
		}
		for (i = 0; i < numsSize; i++) {
			printf("%d ", nums[i]);
		}
	}
}

int main() {
	int nums[7] = { 1,2,3,4,5,6,7};
	int numsSize=7;
	int k = 3;
	rotate(nums, numsSize, k);
	return 0;
}