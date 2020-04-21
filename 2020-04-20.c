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
////大堆，向下调整
//void bigshiftdown(datatype* array, int size, int parent) {  //parent表示起始调整位置
//	//先选择左孩子
//	int child = 2 * parent + 1;
//	while (child < size) {
//		if (child + 1 < size && array[child] < array[child + 1]) {
//			child++;
//		}
//		if (array[child] > array[parent]) {
//			//交换父节点跟子节点的值
//			Swap(array, child, parent);
//			//更新，继续交换
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else { 
//			break;
//		}
//	}
//}
//
////大堆，向上调整
//void bigshiftUp(datatype* array, int child) {  //child起始调整位置
//	int parent = (child - 1) / 2;
//	while (child > 0) {
//		if (array[child] > array[parent]) {
//			Swap(array, child, parent);
//			//更新，继续向上调整
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else {  //当没有父结点，或者大于父节点的值就结束循环
//			break;
//		}
//	}
//}
//
////小堆，向下调整
//void shiftdown(datatype* array, int size, int parent) {  //parent表示起始调整位置
//	//先选择左孩子
//	int child = 2 * parent + 1;
//	while (child < size) {
//		//要是右孩子存在且更小的话就选择右孩子，child加一就是右孩子
//		if (child + 1 < size && array[child] > array[child + 1]) {
//			child++;
//		}
//		if (array[child] < array[parent]) {
//			//交换父节点跟子节点的值
//			Swap(array, child, parent);
//			//更新，继续交换
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else { //结束条件要不然走到叶子节点，要不然符合小堆要求
//			break;
//		}
//	}
//}
//
////小堆，向上调整
//void shiftUp(datatype* array, int child) {  //child起始调整位置
//	int parent = (child - 1) / 2;
//	while (child > 0) {
//		if (array[child] < array[parent]) {
//			Swap(array, child, parent);
//			//更新，继续向上调整
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else {  //当没有父结点，或者小于父节点的值就结束循环
//			break;
//		}
//	}
//}
//
////建堆
//void HeapCreate(Heap* hp, datatype* array, int size) {
//	hp->array = (datatype*)malloc(sizeof(datatype) * size);
//	memcpy(hp->array, array, size * sizeof(datatype));
//	hp->size = size;
//	hp->capacity = size;
//
//	//从最后一个非叶子节点开始建堆
//	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
//		shiftdown(hp->array, size, parent);
//	}
//}
//
//// 堆的插入
//void HeapPush(Heap* hp, datatype x) {
//	//看看是否要增容
//	if (hp->size == hp->capacity) {
//		hp->capacity += 10;
//		hp->array = (datatype*)realloc(hp->array, hp->capacity * sizeof(datatype));
//	}
//	//尾插
//	hp->array[hp->size++] = x;
//	shiftUp(hp->array, hp->size - 1);
//}
//
//// 堆的删除
//void HeapPop(Heap* hp) {
//	if (hp->size > 0) {
//		//先让根结点和最后一个节点交换位置
//		Swap(hp->array, 0, hp->size - 1);
//		//尾删，实际上删的是堆顶元素
//		hp->size--;
//		shiftdown(hp->array, hp->size, 0);
//	}
//}
//
//
//// 取堆顶的数据
//datatype HeapTop(Heap* hp) {
//	return hp->array[0];
//}
//
//// 堆的数据个数
//int HeapSize(Heap* hp) {
//	return hp->size;
//}
//
//// 堆的判空
//int HeapEmpty(Heap* hp) {
//	if (hp->size == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////打印堆的每个元素
//void HeapPrint(Heap* hp) {
//	for (int i = 0; i < hp->size; i++) {
//		printf("%d ", hp->array[i]);
//	}
//	printf("\n");
//}
//
////堆的销毁
//void HeapDestory(Heap* hp)
//{
//	assert(hp);
//	free(hp->array);
//	hp->array = NULL;
//	hp->size = hp->capacity = 0;
//}
//
//
////找最小值建大堆
//
//
////找最大值：1.先用前K个数据建小堆
////2.然后依次把剩余的元素拿来和堆顶元素比较
////3.如果小于堆顶元素，则删除堆顶元素入堆，否则进行下一个元素的判断
//void PrintTopK(int* a, int n, int k){
//	Heap hp;
//	//建立含有K个元素的堆
//	HeapCreate(&hp, a, k);
//
//	for (size_t i = k; i < n; ++i)  // N
//	{
//		//每次和堆顶元素比较，大于堆顶元素，则删除堆顶元素，插入新的元素
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
//	//建堆
//	HeapCreate(&hp, array, 11);
//	HeapPrint(&hp);
//	//堆插
//	HeapPush(&hp, 22);
//	HeapPrint(&hp);
//	printf("堆的个数：%d\n", HeapSize(&hp));
//	//堆删
//	HeapPop(&hp);
//	HeapPrint(&hp);
//	//依此打印出堆顶元素
//	while (HeapEmpty(&hp) != 1) {
//		printf("%d\n", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	//求数组中前K个最值
//	/*PrintTopK(array, 11, 3);
//	HeapPrint(&hp);*/
//	return 0;
//}