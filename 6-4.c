#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int menu() {
	printf("ѡ������Ҫִ�еĹ��ܣ�\n");
	printf("1.��ʼ������\n");
	printf("2.�������\n");
	printf("3.����Ԫ������\n");
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
		arr[i] = 0;                //����൱���ʼ��Ϊ0
		printf("%d  ", arr[i]);
	}
}

void reverse(int arr[], int size) {
	int left = 0;
	int right = size-1;
	int tmp = 0;
	//left��right��ȵ�ʱ������Ԫ�ؾ������������м�Ĳ��ý�����
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