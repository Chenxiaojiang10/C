//#include<stdio.h>
////升序
//void shellSort(int* arr, int size) {
//	int gap = size;
//	while (gap > 1) {
//		//设置步长
//		gap = gap / 2;
//		//通过步长进行分组，每组进行一轮插入排序
//		for (int i = 0; i < size - gap; i++) {
//			int end = i;
//			int key = arr[end + gap];
//			while (end >= 0 && key < arr[end]) {
//				arr[end + gap] = arr[end];
//				end = end - gap;
//			}
//			arr[end + gap] = key;
//		}
//	}
//}
//int main() {
//	int arr[10] = { 1,9,5,3,6,4,4,7,10,2 };
//	shellSort(arr, 10);
//	for(int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}