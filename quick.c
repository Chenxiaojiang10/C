#include<stdio.h>
//快速排序，升序
void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
int partion(int* array, int begin, int end)
{
	//选择基准值
	int key = array[begin];
	int start = begin;
	//划分
	while (begin < end)
	{
		//从后往前找第一个小于key的位置
		while (begin < end && array[end] >= key)
			--end;
		//这两个while循环顺序不可交换
		//从前向后找第一个大于key的位置
		while (begin < end && array[begin] <= key)
			++begin;
		//交换 end, begin
		Swap(array, begin, end);
	}
	//key和相遇位置的数据交换
	Swap(array, start, begin);
	//返回基准值的位置
	return begin;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//划分当前区间
	int keyPos = partion(array, begin, end);
	//划分子区间
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}

int main() {
	int array[10] = { 1,3,6,7,9,5,7,2,3,5 };
	quickSort(array, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}