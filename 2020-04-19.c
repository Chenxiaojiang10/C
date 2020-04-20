#include<stdio.h>
//��������ж�����
//����Ҫ������Ҫ�����
//����Ҫ���򣬽�С��
typedef int datatype;
void Swap(datatype* array, int left, int right) {
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}
//��ѣ����µ���
void bigshiftdown(datatype* array, int size, int parent) {  //parent��ʾ��ʼ����λ��
	//��ѡ������
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child] < array[child + 1]) {
			child++;
		}
		if (array[child] > array[parent]) {
			//�������ڵ���ӽڵ��ֵ
			Swap(array, child, parent);
			//���£���������
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
//��������ж�����
void HeapSort(int* array, int n) {
	//����
	for (int i = (n - 2) / 2; i >= 0; i--) {
		bigshiftdown(array, n, i);
	}
	int size = n;
	while (size > 1) {
		//ѭ��βɾ
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