#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int  greedySelector(int* a, int* f, int* arr,int *number,int n) {
	int j=0,k=0,m=0,count=0;
	while (count != n) {                      
		m++;                                   
		for (j; j < n; j++) {                 
			if (arr[j] == 0) {                 
				arr[j] = 1;                    
				count++;                       
				k = j;
				printf("%d�����ѱ������ڵ�%d������\n",number[j], m);
				break;                        
			}
			else
				continue;         
			}
		    
		for (int i = 0; i < n; ++i) {         
				                                
			if (a[i] >= f[k] && arr[i] == 0) {  
				arr[i] = 1;              
				k = i;                          
				count++;                        
				printf("%d�����ѱ������ڵ�%d������\n",number[i], m);
				}
				else ;
			}
	}
	return m;                                  
}

void sort(int a[],int f[],int number[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				int temp1 = f[i];
				int temp2 = number[i];
				a[i] = a[j];
				f[i] = f[j];
				number[i] = number[j];
				a[j] = temp;
				f[j] = temp1;
				number[j] = temp2;
			}
		}
	}
}

int main() {
	int n;
	printf("�������¼�����(n)��");
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);      
	int* f = (int*)malloc(sizeof(int) * n);      
	int* number = (int*)malloc(sizeof(int) * n); 
	printf("������������¼��Ŀ�ʼʱ��,����ʱ��ͻ����ţ�\n");
	for (int i = 0; i < n; i++)
	scanf("%d %d %d",&a[i],&f[i],&number[i]);
	sort(a,f,number,n);                        
	int arr[100] = { 0 };                       
	int num = greedySelector(a, f, arr,number,n);
	printf("������Ҫ������%d��\n",num);
	return 0;
}
