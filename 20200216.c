#include<stdio.h>
#include<math.h>
int findUnsortedSubarray(int* nums, int numsSize) {
	int i,j;
	int left = 0;
	int right = numsSize - 1;
	/*int max = 0;
	int min = 0;
	for (i = 0; i < numsSize - 1; i++) {
		if (i == 0) {
			max = nums[i];
		}
		else {
			if (nums[i] < max) {
				right = i;
				break;
			}
			
			max = nums[i]; 
			
		}
	}
	for (i = numsSize - 1; i >= 0; i--) {
		if (i == numsSize - 1) {
			min = nums[numsSize - 1];
		}
		else {
			if (nums[i] > min) {
				left = i;
				break;
			}
			
				min = nums[i];
			
		}
	}*/
	for (i = 0; i < numsSize-1; i++) {
		if (nums[i] > nums[i + 1]) {
			left = i;
			for (j = left; j > 0; j--) {
				if (nums[left] == nums[left - 1]) {
					left--;
				}
			}
			break;
		}
		right--;
	}
	if (right == 0) {
		return 0;
	}
	for (i = numsSize - 1; i > 0; i--) {
		if (nums[i] < nums[i - 1]) {
			right = i;
			for (j = right; j < numsSize; j++) {
				if (nums[right] == nums[right + 1]) {
					right++;
				}
			}
			break;
		}
	}
	return right - left + 1;
}

int main() {
	int nums[5] = { 1,2,4,5,3 };
	int numsSize = 5;
	int a = findUnsortedSubarray(nums, numsSize);
	printf("%d", a);
	return 0;
}