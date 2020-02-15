#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	int a, b;
	int* array = (int*)malloc(2 * sizeof(int));
	for (i = 0; i < numsSize; i++) {
		a = target - nums[i];
		nums[i] = 0;
		for (j = 0; j < numsSize; j++) {
			if (nums[j] == a&&i!=j) {
				array[0] = i;
				array[1] = j;
			}
		}
	}
	*returnSize = 2;
	return array; 
	
	
	/*int i, j;
	int a = numsSize, b;
	int m, n;
	int* arr = (int*)malloc(numsSize * sizeof(int));
	for (i = 0; i < numsSize; i++) {
		arr[i] = nums[i];
	}
	for (i = 0; i < numsSize - 1; i++) {
		for (j = 0; j < numsSize - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i]<target && nums[i + 1]>target) {
			a = i + 1;
		}
	}
	int* array = (int*)malloc(2 * sizeof(int));
	for (i = 0; i < a; i++) {
		b = target - nums[i];
		for (j = i + 1; j < a; j++) {
			if (nums[j] == b) {
				m = nums[i];
				n = nums[j];
			}
		}
	}
	for (i = 0; i < numsSize; i++) {
		if (arr[i] == m || arr[i] == n) {
			*(array + 0) = i;
			for (j = i + 1; j < numsSize; j++) {
				if (arr[i] == m || arr[i] == n) {
					*(array + 1) = j;
					break;
				}
			}
			break;
		}
	}
	*returnSize = numsSize;
	return array;*/
}

int main() {
	int nums[4] = { 2,7,11,15 };
	int numsSize = 4;
	int returnSize = 0;
	int target = 9;
	int* p = twoSum(nums, numsSize, target, &returnSize);
	printf("%d %d", p[0], p[1]);
	return 0;
}