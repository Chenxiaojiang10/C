#include<stdio.h>

int containsDuplicate(int* nums, int numsSize) {
	int i, j;
	for (i = 0; i < numsSize ; i++) {
		for (j = i; j < numsSize  ; j++) {
			if (nums[i] == nums[j] &&i!=j) {
				return 1;
			}
		}
	}
	return 0;
}


int main() {
	int nums[] = { 1,2,3,3 };
	int numsSize = 4;
	int a = containsDuplicate(nums, numsSize);
	printf("1´ú±ítrue£º%d", a);
	return 0;
}