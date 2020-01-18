#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int k = 0;

int menu() {
	printf("-----------------------\n");
	printf("选择你想要的算法：\n");
	printf("1.首次适应算法。\n");
	printf("2.循环首次适应算法。\n");
	printf("3.最佳适应算法。\n");
	printf("4.最坏适应算法。\n");
	printf("0.退出程序。\n");
	printf("-----------------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void PrintF(int arr[],int s) {
	int i;
	for (i = 0; i < s; i++) {
		printf("%d ", arr[i]);
	}
}
//=====================首次适应算法=================
void FF(int arr[],int s, int u) {
	int i;
	int size=5;
	int m_size;//每个空闲区大小
	int u_size = u;//请求分区大小
	for (i = 0; i < 10; i++) {
		m_size = arr[i];
		if (m_size > u_size) {
			if ((m_size - u_size) <= size) {
				arr[i] = 0;
				PrintF(arr, s);
				k = i;
				break;
			}
			else {
				arr[i] = arr[i] - u_size;
				PrintF(arr, s);
				k = i;
				break;
			}
		}
	}
}
//===============循环首次适应算法=================
void NF(int arr[], int s, int u) {
	int i;
	int size = 5;
	int m_size;//每个空闲区大小
	int u_size = u;//请求分区大小
	//先遍历从上次分配出去的分区的到最后一个分区
	for (i = k; i < 10; i++) {
		m_size = arr[i];
		if (m_size > u_size) {
			if ((m_size - u_size) <= size) {
				arr[i] = 0;
				PrintF(arr, s);
				k = i;
				break;
			}
			else {
				arr[i] = arr[i] - u_size;
				PrintF(arr, s);
				k = i;
				break;
			}
		}
	}
	//再遍历从0分区到上次分配的那个分区
	for (i = 0; i < k; i++) {
		m_size = arr[i];
		if (m_size > u_size) {
			if ((m_size - u_size) <= size) {
				arr[i] = 0;
				PrintF(arr, s);
				k = i;
				break;
			}
			else {
				arr[i] = arr[i] - u_size;
				PrintF(arr, s);
				k = i;
				break;
			}
		}
	}
}
//================最佳===============
void BF(int arr[], int s, int u) {
	int i,j;
	int size = 5;
	int m_size = 0;//每个空闲区大小
	int u_size = u;//请求分区大小
	for (i = 0; i < 9; i++) { //按照空闲片大小从小到大排序
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		m_size = arr[i];
		if (m_size > u_size) {
			if ((m_size - u_size) <= size) {
				arr[i] = 0;
				PrintF(arr, s);
				k = i;
				break;
			}
			else {
				arr[i] = arr[i] - u_size;
				PrintF(arr, s);
				k = i;
				break;
			}
		}
	}
}
//===================最坏===================
void WF(int arr[],int s,int u) {
	int i, j;
	int size = 5;
	int m_size = 0;//每个空闲区大小
	int u_size = u;//请求分区大小
	for (i = 0; i < 9; i++) {     ////按照空闲片大小从大到小排序
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		m_size = arr[i];
		if (m_size > u_size) {
			if ((m_size - u_size) <= size) {
				arr[i] = 0;
				PrintF(arr, s);
				k = i;
				break;
			}
			else {
				arr[i] = arr[i] - u_size;
				PrintF(arr, s);
				k = i;
				break;
			}
		}
	}
}

int main() {
	int arr[10] = { 32,50,64,32,24,12,32,64,32,128 };//空闲分区片
	int s = sizeof(arr) / sizeof(arr[0]);
	//int* px = arr[0];//指向链首
	//int* py = arr[9];//指向链尾
	while (1) {
		
		//循环输入
		int choice = menu();
		printf("请输入你想要申请的分区大小：\n");
		int u = 0;  //申请的分区大小
		scanf("%d", &u);
		if (choice == 1) {
			printf("========首次适应算法========\n");
			printf("初始的空闲分区：");
			PrintF(arr, s);
			printf("\n");
			printf("分配后空闲分区：");
			FF(arr, s, u);//1.首次适应算法
			printf("\n");
		}
		else if (choice == 2) {
			printf("=======循环首次适应算法=======\n");
			printf("初始的空闲分区：");
			PrintF(arr, s);
			printf("\n");
			printf("分配后空闲分区：");
			NF(arr, s, u);//2.循环首次适应算法
			printf("\n");
		}
		else if (choice == 3) {
			printf("=========最佳适应算法=========\n");
			printf("初始的空闲分区：");
			PrintF(arr, s);
			printf("\n");
			printf("分配后空闲分区：");
			BF(arr, s, u);//3.最佳适应算法
			printf("\n");
		}
		else if (choice == 4) {
			printf("=======最坏适应算法=======\n");
			printf("初始的空闲分区：");
			PrintF(arr, s);
			printf("\n");
			printf("分配后空闲分区：");
			WF(arr, s, u);//4.最坏适应算法
			printf("\n");
		}
		else if (choice == 0) {
			printf("程序结束！\n");
			break;
		} 
		else {
			printf("error!\n");
		}
	}
	

	return 0;
}