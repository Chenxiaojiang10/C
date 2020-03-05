//#include<stdio.h>
//
//int pivotIndex(int* nums, int numsSize) {
//	if (numsSize == 0) {
//		return -1;
//	}
//	int a = nums[0];
//	int b = nums[numsSize - 1];
//	int left = 0;
//	int right = numsSize - 1;
//	int n = 2;
//	while (left < right) {
//		
//		if (a > b) {
//			if (nums[right-1] < 0) {
//				left++;
//				a = a + nums[left];
//				n++;
//			}
//			else {
//				right--;
//				b = b + nums[right];
//				n++;
//			}
//			
//		}
//		else if (a < b) {
//			
//			if (nums[left+1] < 0) {
//				right--;
//				b = b + nums[right];
//				n++;
//			}
//			else {
//				left++;
//				a = a + nums[left];
//				n++;
//			}
//		}
//		else if (a == b && n == numsSize - 1) {
//			return left + 1;
//		}
//		else if (a == b && n != numsSize - 1) {
//			if (nums[right - 1] < 0) {
//				left++;
//				a = a + nums[left];
//				n++;
//			}
//			right--;
//			b = b + nums[right];
//			n++;
//		}
//	}
//	return -1;
//}
//
//int main() {
//	int nums[] = { -1,-1,-1,-1,0,-1 };
//	int numsSize = sizeof(nums) / 4;
//	int a = pivotIndex(nums, numsSize);
//	printf("%d", a);
//	return 0;
//}