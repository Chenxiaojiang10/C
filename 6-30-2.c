#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//һ�����������м�������������
int func(int* a, int size) {
	int i = 0;
	int cont = 0;
	while (i < size) {
		//��ͬ������һλ
		if (a[i] == a[i + 1]) {
			i++;
		}
		// ������������
		else if (a[i] < a[i + 1]) {
			i++;  //��ͷ�����жϳ���ʱ�������ǵݼ�
			//�ٽ���while�������������ּ��Ժ���������Ƿ��������
			while (1) {
				if (a[i] <= a[i + 1]) {
					i++;
				}
				//���ֿ�ʼ�ݼ��ˣ���ϣ�����cont++
				else {
					cont++;
					i++;
					break;
				}
			}
		}
		//�ݼ���������
		else if (a[i] > a[i + 1]) {
			i++;
			while (1) {
				if (a[i] > a[i + 1]) {
					i++;
				}
				else {
					cont++;
					i++;
					break;
				}
			}
		}
	}
	return cont;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int q = func(a, n);
	printf("%d\n", q);
	return 0;
}