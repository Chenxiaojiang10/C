#include<stdio.h>
//������������
void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
int partion(int* array, int begin, int end)
{
	//ѡ���׼ֵ
	int key = array[begin];
	int start = begin;
	//����
	while (begin < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С��key��λ��
		while (begin < end && array[end] >= key)
			--end;
		//������whileѭ��˳�򲻿ɽ���
		//��ǰ����ҵ�һ������key��λ��
		while (begin < end && array[begin] <= key)
			++begin;
		//���� end, begin
		Swap(array, begin, end);
	}
	//key������λ�õ����ݽ���
	Swap(array, start, begin);
	//���ػ�׼ֵ��λ��
	return begin;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//���ֵ�ǰ����
	int keyPos = partion(array, begin, end);
	//����������
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}

int main() {
	int array[10] = { 1,3,6,7,9,5,7,2,3,5 };
	quickSort(array, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}