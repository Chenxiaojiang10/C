#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int k = 0;

int menu() {
	printf("-----------------------\n");
	printf("ѡ������Ҫ���㷨��\n");
	printf("1.�״���Ӧ�㷨��\n");
	printf("2.ѭ���״���Ӧ�㷨��\n");
	printf("3.�����Ӧ�㷨��\n");
	printf("4.���Ӧ�㷨��\n");
	printf("0.�˳�����\n");
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
//=====================�״���Ӧ�㷨=================
void FF(int arr[],int s, int u) {
	int i;
	int size=5;
	int m_size;//ÿ����������С
	int u_size = u;//���������С
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
//===============ѭ���״���Ӧ�㷨=================
void NF(int arr[], int s, int u) {
	int i;
	int size = 5;
	int m_size;//ÿ����������С
	int u_size = u;//���������С
	//�ȱ������ϴη����ȥ�ķ����ĵ����һ������
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
	//�ٱ�����0�������ϴη�����Ǹ�����
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
//================���===============
void BF(int arr[], int s, int u) {
	int i,j;
	int size = 5;
	int m_size = 0;//ÿ����������С
	int u_size = u;//���������С
	for (i = 0; i < 9; i++) { //���տ���Ƭ��С��С��������
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
//===================�===================
void WF(int arr[],int s,int u) {
	int i, j;
	int size = 5;
	int m_size = 0;//ÿ����������С
	int u_size = u;//���������С
	for (i = 0; i < 9; i++) {     ////���տ���Ƭ��С�Ӵ�С����
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
	int arr[10] = { 32,50,64,32,24,12,32,64,32,128 };//���з���Ƭ
	int s = sizeof(arr) / sizeof(arr[0]);
	//int* px = arr[0];//ָ������
	//int* py = arr[9];//ָ����β
	while (1) {
		
		//ѭ������
		int choice = menu();
		printf("����������Ҫ����ķ�����С��\n");
		int u = 0;  //����ķ�����С
		scanf("%d", &u);
		if (choice == 1) {
			printf("========�״���Ӧ�㷨========\n");
			printf("��ʼ�Ŀ��з�����");
			PrintF(arr, s);
			printf("\n");
			printf("�������з�����");
			FF(arr, s, u);//1.�״���Ӧ�㷨
			printf("\n");
		}
		else if (choice == 2) {
			printf("=======ѭ���״���Ӧ�㷨=======\n");
			printf("��ʼ�Ŀ��з�����");
			PrintF(arr, s);
			printf("\n");
			printf("�������з�����");
			NF(arr, s, u);//2.ѭ���״���Ӧ�㷨
			printf("\n");
		}
		else if (choice == 3) {
			printf("=========�����Ӧ�㷨=========\n");
			printf("��ʼ�Ŀ��з�����");
			PrintF(arr, s);
			printf("\n");
			printf("�������з�����");
			BF(arr, s, u);//3.�����Ӧ�㷨
			printf("\n");
		}
		else if (choice == 4) {
			printf("=======���Ӧ�㷨=======\n");
			printf("��ʼ�Ŀ��з�����");
			PrintF(arr, s);
			printf("\n");
			printf("�������з�����");
			WF(arr, s, u);//4.���Ӧ�㷨
			printf("\n");
		}
		else if (choice == 0) {
			printf("���������\n");
			break;
		} 
		else {
			printf("error!\n");
		}
	}
	

	return 0;
}