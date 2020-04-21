//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//
//typedef int datatype;
//typedef struct Heap
//{
//	datatype* array;
//	int size;
//	int capacity;
//}Heap;
//
//void Swap(datatype* array, int left, int right) {
//	int tmp = array[left];
//	array[left] = array[right];
//	array[right] = tmp;
//}
//
////��ѣ����µ���
//void bigshiftdown(datatype* array, int size, int parent) {  //parent��ʾ��ʼ����λ��
//	//��ѡ������
//	int child = 2 * parent + 1;
//	while (child < size) {
//		if (child + 1 < size && array[child] < array[child + 1]) {
//			child++;
//		}
//		if (array[child] > array[parent]) {
//			//�������ڵ���ӽڵ��ֵ
//			Swap(array, child, parent);
//			//���£���������
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else { 
//			break;
//		}
//	}
//}
//
////��ѣ����ϵ���
//void bigshiftUp(datatype* array, int child) {  //child��ʼ����λ��
//	int parent = (child - 1) / 2;
//	while (child > 0) {
//		if (array[child] > array[parent]) {
//			Swap(array, child, parent);
//			//���£��������ϵ���
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else {  //��û�и���㣬���ߴ��ڸ��ڵ��ֵ�ͽ���ѭ��
//			break;
//		}
//	}
//}
//
////С�ѣ����µ���
//void shiftdown(datatype* array, int size, int parent) {  //parent��ʾ��ʼ����λ��
//	//��ѡ������
//	int child = 2 * parent + 1;
//	while (child < size) {
//		//Ҫ���Һ��Ӵ����Ҹ�С�Ļ���ѡ���Һ��ӣ�child��һ�����Һ���
//		if (child + 1 < size && array[child] > array[child + 1]) {
//			child++;
//		}
//		if (array[child] < array[parent]) {
//			//�������ڵ���ӽڵ��ֵ
//			Swap(array, child, parent);
//			//���£���������
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else { //��������Ҫ��Ȼ�ߵ�Ҷ�ӽڵ㣬Ҫ��Ȼ����С��Ҫ��
//			break;
//		}
//	}
//}
//
////С�ѣ����ϵ���
//void shiftUp(datatype* array, int child) {  //child��ʼ����λ��
//	int parent = (child - 1) / 2;
//	while (child > 0) {
//		if (array[child] < array[parent]) {
//			Swap(array, child, parent);
//			//���£��������ϵ���
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else {  //��û�и���㣬����С�ڸ��ڵ��ֵ�ͽ���ѭ��
//			break;
//		}
//	}
//}
//
////����
//void HeapCreate(Heap* hp, datatype* array, int size) {
//	hp->array = (datatype*)malloc(sizeof(datatype) * size);
//	memcpy(hp->array, array, size * sizeof(datatype));
//	hp->size = size;
//	hp->capacity = size;
//
//	//�����һ����Ҷ�ӽڵ㿪ʼ����
//	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
//		shiftdown(hp->array, size, parent);
//	}
//}
//
//// �ѵĲ���
//void HeapPush(Heap* hp, datatype x) {
//	//�����Ƿ�Ҫ����
//	if (hp->size == hp->capacity) {
//		hp->capacity += 10;
//		hp->array = (datatype*)realloc(hp->array, hp->capacity * sizeof(datatype));
//	}
//	//β��
//	hp->array[hp->size++] = x;
//	shiftUp(hp->array, hp->size - 1);
//}
//
//// �ѵ�ɾ��
//void HeapPop(Heap* hp) {
//	if (hp->size > 0) {
//		//���ø��������һ���ڵ㽻��λ��
//		Swap(hp->array, 0, hp->size - 1);
//		//βɾ��ʵ����ɾ���ǶѶ�Ԫ��
//		hp->size--;
//		shiftdown(hp->array, hp->size, 0);
//	}
//}
//
//
//// ȡ�Ѷ�������
//datatype HeapTop(Heap* hp) {
//	return hp->array[0];
//}
//
//// �ѵ����ݸ���
//int HeapSize(Heap* hp) {
//	return hp->size;
//}
//
//// �ѵ��п�
//int HeapEmpty(Heap* hp) {
//	if (hp->size == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////��ӡ�ѵ�ÿ��Ԫ��
//void HeapPrint(Heap* hp) {
//	for (int i = 0; i < hp->size; i++) {
//		printf("%d ", hp->array[i]);
//	}
//	printf("\n");
//}
//
////�ѵ�����
//void HeapDestory(Heap* hp)
//{
//	assert(hp);
//	free(hp->array);
//	hp->array = NULL;
//	hp->size = hp->capacity = 0;
//}
//
//
////����Сֵ�����
//
//
////�����ֵ��1.����ǰK�����ݽ�С��
////2.Ȼ�����ΰ�ʣ���Ԫ�������ͶѶ�Ԫ�رȽ�
////3.���С�ڶѶ�Ԫ�أ���ɾ���Ѷ�Ԫ����ѣ����������һ��Ԫ�ص��ж�
//void PrintTopK(int* a, int n, int k){
//	Heap hp;
//	//��������K��Ԫ�صĶ�
//	HeapCreate(&hp, a, k);
//
//	for (size_t i = k; i < n; ++i)  // N
//	{
//		//ÿ�κͶѶ�Ԫ�رȽϣ����ڶѶ�Ԫ�أ���ɾ���Ѷ�Ԫ�أ������µ�Ԫ��
//		if (a[i] > HeapTop(&hp)) // LogK
//		{
//			HeapPop(&hp);
//			HeapPush(&hp, a[i]);
//		}
//	}
//	for (int i = 0; i < k; ++i) {
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//}
//
//int main() {
//	int array[11] = { 23,45,78,65,13,44,12,32,56,9,11 };
//	Heap hp;
//	//����
//	HeapCreate(&hp, array, 11);
//	HeapPrint(&hp);
//	//�Ѳ�
//	HeapPush(&hp, 22);
//	HeapPrint(&hp);
//	printf("�ѵĸ�����%d\n", HeapSize(&hp));
//	//��ɾ
//	HeapPop(&hp);
//	HeapPrint(&hp);
//	//���˴�ӡ���Ѷ�Ԫ��
//	while (HeapEmpty(&hp) != 1) {
//		printf("%d\n", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	//��������ǰK����ֵ
//	/*PrintTopK(array, 11, 3);
//	HeapPrint(&hp);*/
//	return 0;
//}