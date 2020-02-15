#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	
	if (digits[digitsSize - 1] + 1 < 10) {
		digits[digitsSize - 1] += 1;
		*returnSize = digitsSize;
		return digits;
	}
	int i;
	int flag = 1;//标志着这个数组是不是全由9组成，1表示是的
	for (i = 0; i <digitsSize ; i++) {
		if (digits[i] != 9) {
			flag = 0;//加1后要多一位数，只有一种情况就是全部是9
			break;
		}
	}
	
	if (flag == 1) {
		int* re = (int*)malloc((digitsSize + 1) * sizeof(int));
		re[0] = 1;
		for (i = 1; i < digitsSize + 1; i++) {
			*(re + i) = 0;
		}
		*returnSize = digitsSize + 1;
		return re;
	}
	else{
		digits[digitsSize - 1] += 1;
		for (i = digitsSize - 1; i >= 0; i--) {
			if (digits[i] == 10) {
				digits[i] = 0;
				digits[i - 1] += 1;
			}
		}
		*returnSize = digitsSize;
		return digits;
	}
	
}

int main() {
	int digits[5] = { 9,9,9,9,9};
	int digitsSize = 5;
	int returnSize = 5;
	int *p = plusOne(digits, digitsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", p[i]);
	}
	return 0;
}