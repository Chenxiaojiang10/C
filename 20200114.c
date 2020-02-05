//#include<stdio.h>
//
//
//int removeElement(int* nums, int numsSize, int val) {
//	int i, j = 0;
//	int tmp = 0;
//	j = numsSize;
//	for (i = 0; i < numsSize; i++) {//记录移除后元素的个数
//		if (nums[i] == val) {       //用j记因为numsSzie下边还要用
//			j--;
//		}
//	}
//	int n = 0;   //用来指向要移动元素的后一个元素
//	for (i = 0; i < numsSize; i++) {
//		if (nums[i] == val) {
//			tmp = i;//找到第一个值等于val的元素
//			n = tmp + 1;
//			if (n >= numsSize) {
//				break;//如果tmp是最后一个元素，就结束循环，不移动了
//			}
//			while (1) {
//				if (n >= numsSize) {
//					break;//这个是防止那个值等于val的元素移出数组，造成堆栈溢出
//				}
//				if (nums[tmp] != nums[n]) {//交换
//					int m = nums[tmp];
//					nums[tmp] = nums[n];
//					nums[n] = m;
//					break;
//				}
//				else if (n < numsSize && nums[tmp] == nums[n]) {
//					n++;//如果连着两个或者多个值等于val的元素，那n就往后拨
//				}
//			}
//		}
//	}
//	numsSize = j;
//	return numsSize;
//}
//
//int main() {
//	int nums[3] = {2,2,3};
//	int val = 3;
//	int numsSize = 3;
//	int a = removeElement(nums, numsSize, val);
//	for (int i = 0; i < a; i++) {
//		printf("%d ", nums[i]);
//	}
//	return 0;
//}