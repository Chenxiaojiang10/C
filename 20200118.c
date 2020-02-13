//#include<stdio.h>
//
//int searchInsert(int* nums, int numsSize, int target) {
//	int i;
//	if (nums[0] > target) {
//		return 0;
//	}
//	if (nums[numsSize - 1] < target) {
//		return numsSize;
//	} 
//	for (i = 0; i < numsSize; i++) {
//		if (nums[i] == target) {
//			return i;
//		}
//		else if (nums[i]<target && nums[i + 1]>target) {
//			return i + 1;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	int nums[4] = { 1,3,5,6 };
//	int numsSize = 4;
//	int target = 5;
//	int a = searchInsert(nums, numsSize, target);
//	printf("%d\n", a);
//	return 0;
//}