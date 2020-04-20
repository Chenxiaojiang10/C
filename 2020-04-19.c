#include<stdio.h>
//对数组进行堆排序
//数组要升序，则要建大堆
//数组要降序，建小堆
typedef int datatype;
void Swap(datatype* array, int left, int right) {
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}
//大堆，向下调整
void bigshiftdown(datatype* array, int size, int parent) {  //parent表示起始调整位置
	//先选择左孩子
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child] < array[child + 1]) {
			child++;
		}
		if (array[child] > array[parent]) {
			//交换父节点跟子节点的值
			Swap(array, child, parent);
			//更新，继续交换
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
//对数组进行堆排序
void HeapSort(int* array, int n) {
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		bigshiftdown(array, n, i);
	}
	int size = n;
	while (size > 1) {
		//循环尾删
		Swap(array, 0, size - 1);
		size--;
		bigshiftdown(array, size, 0);
	}
}
void test() {
	int array[11] = { 23,45,78,65,13,44,12,32,56,9,11 };
	int n = 11;
	HeapSort(array, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
}
int main() {
	test();
	return 0;
}