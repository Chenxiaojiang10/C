#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int j = 1;
	int idx = 0;
	while (j < numsSize) {
		nums[idx++] = nums[i];
		if (nums[i] != nums[j]) {
			++i;
			++j;
		}
		else {
			while ( j < numsSize && nums[i] == nums[j] ) {
				++j;
			}
			i = j;
			++j;
		}
	}
	if (i < numsSize) {
		nums[idx++] = nums[i];
	}
	return idx;
}

int main() {
	int nums[] = { 1,1 };
	int numsSize = 2;
	int a = removeDuplicates(nums, numsSize);
	for (int i = 0; i < a; i++) {
		printf("%d ", nums[i]);
	}
	
	return 0;
}