#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int menu() {
	printf("选择你想要执行的功能：\n");
	printf("1.初始化数组\n");
	printf("2.清空数组\n");
	printf("3.数组元素逆置\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void init(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 1;
		printf("%d  ", arr[i]);
	}
}

void empty(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;                //清空相当与初始化为0
		printf("%d  ", arr[i]);
	}
}

void reverse(int arr[], int size) {
	int left = 0;
	int right = size-1;
	int tmp = 0;
	//left跟right相等的时候数组元素就是奇数个，中间的不用交换。
	for (; left < right; left++, right--) {
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
}

int main() {
	int arr[] = { 1,2,3,4,5,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int a = menu();
	if (a == 1) {
		init(arr,size);
	}
	else if(a == 2) {
		empty(arr,size);
	}
	else if(a == 3) {
		reverse(arr,size);
	}
	else {
		printf("byebye!\n");
	}
	return 0;
}