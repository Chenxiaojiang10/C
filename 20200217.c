//#include<stdio.h>
//
//int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//	int* array = (int*)malloc(2 * sizeof(int));
//	*returnSize = 2;
//	if (numsSize == 0) {
//		array[0] = -1;
//		array[1] = -1;
//		return array;
//	}
//	int left = 0;
//	int right = numsSize;
//	int mid = 0;
//	
//	while (left <= right) {
//		mid = (left + right) / 2;
//		if (mid > numsSize - 1) {
//			left++;
//			break;
//		}
//		if (target < nums[mid]) {
//			right = mid - 1;
//		}
//		
//		if (target > nums[mid]) {
//			left = mid + 1;
//			
//		}
//		if (target == nums[mid]) {
//			if(numsSize==1||nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
//				array[0] = array[1] = mid;
//				break;
//			}
//			else if (target == nums[mid - 1]) {
//				array[0] = mid-1;
//				array[1] = mid;
//				break;
//			}
//			else if (target == nums[mid + 1]) {
//				array[0] = mid;
//				array[1] = mid+1;
//				break;
//			}
//			
//		}
//	}
//	if (left > right) {
//		array[0] = -1;
//		array[1] = -1;
//	}
//	
//	return array;
//}
//
//
//int main() {
//	int nums[] = { 2,2 };
//	int numsSize = sizeof(nums) / sizeof(int);
//	int returnSize = 0;
//	int target = 2;
//	int* p = searchRange(nums, numsSize, target, &returnSize);
//	printf("%d %d", p[0], p[1]);
//	return 0;
//}