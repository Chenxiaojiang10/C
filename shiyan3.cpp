#include <iostream>  
using namespace std;
/*�������� ʹ��ָ�봫��*/
void swap(int* m, int* n)   //�β���ָ�����
{
	int temp = *m;           //ʹ*m��*n����
	*m = *n;
	*n = temp;
}
/* ʹ�����ô��� */
void swap(int& m, int& n)     //�β����������ͱ���������  
{
	int temp = m;
	m = n;
	n = temp;
}
int main()
{
	int a = 3;
	int b = 5;
	cout << "ת��ǰ: a=" << a << " b=" << b << endl;
	swap(&a, &b);     //����ָ�봫�κ���
	cout << "ָ�봫��ת����a=" << a << " b=" << b << endl;
	swap(a, b);     //�������ô��κ���
	cout << "���ô��ε���ת����a=" << a << " b=" << b << endl;
	return 0;
}
