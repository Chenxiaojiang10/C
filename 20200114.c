//#include<stdio.h>
//
//
//int removeElement(int* nums, int numsSize, int val) {
//	int i, j = 0;
//	int tmp = 0;
//	j = numsSize;
//	for (i = 0; i < numsSize; i++) {//��¼�Ƴ���Ԫ�صĸ���
//		if (nums[i] == val) {       //��j����ΪnumsSzie�±߻�Ҫ��
//			j--;
//		}
//	}
//	int n = 0;   //����ָ��Ҫ�ƶ�Ԫ�صĺ�һ��Ԫ��
//	for (i = 0; i < numsSize; i++) {
//		if (nums[i] == val) {
//			tmp = i;//�ҵ���һ��ֵ����val��Ԫ��
//			n = tmp + 1;
//			if (n >= numsSize) {
//				break;//���tmp�����һ��Ԫ�أ��ͽ���ѭ�������ƶ���
//			}
//			while (1) {
//				if (n >= numsSize) {
//					break;//����Ƿ�ֹ�Ǹ�ֵ����val��Ԫ���Ƴ����飬��ɶ�ջ���
//				}
//				if (nums[tmp] != nums[n]) {//����
//					int m = nums[tmp];
//					nums[tmp] = nums[n];
//					nums[n] = m;
//					break;
//				}
//				else if (n < numsSize && nums[tmp] == nums[n]) {
//					n++;//��������������߶��ֵ����val��Ԫ�أ���n������
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