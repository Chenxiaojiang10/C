#include <iostream>//�����Ľ׳�
#include<string>
//#include<cmath>
using namespace std;
//����ת��
void transform(string& str, int& num)
{
	if (num >= 0 && num < 9)
	{
		str = "000" + to_string(num);
	}
	else if (num >= 10 && num <= 99)
	{
		str = "00" + to_string(num);
	}
	else if (num >= 100 && num <= 999)
	{
		str = "0" + to_string(num);
	}
	else
	{
		str = to_string(num);
	}
}
//�׳˼���
void func(int num)
{
	int* arr = new int[num];//100���ڲ���Խ�磬���Ǻܴ�Ļ����ǻ�Խ���
	string* str = new string[num];
	int length = 1;//100�Ľ׳�һ��ʼ������������˲��ᳬ��һ������������һ��Ϊ��λ����ʼ������ռ���鳤��Ϊ1
	int temp = 0;
	int c_num = 0;//��λ
	arr[0] = 1;// ��ʼ�� a[0] �����һ������������ ��������
	int j = 0;
	for (int i = num; i > 1; i--)
	{
		for (j = 0; j < length; j++)
		{
			if (j == 0)//���׸�����Ԫ�������㲻��Ҫ�ӽ�λ
			{
				temp = arr[j] * i;
				arr[j] = temp % 10000;
				transform(str[j], arr[j]);
				c_num = temp / 10000;
			}
			if (j != 0)
			{
				temp = arr[j] * i + c_num;
				arr[j] = temp % 10000;
				transform(str[j], arr[j]);
				c_num = temp / 10000;
			}
		}
		arr[j] = c_num;
		transform(str[j], arr[j]);//����ת�ַ���
		if (c_num > 0)
		{
			length++;
		}
	}
	for (int i = length - 1; i >= 0; i--)
	{
		cout << str[i];
	}
	cout << endl;
	delete[] arr;//�ͷ�
	delete[] str;
}
int main()
{
	int n = 0;
	cout << "����һ���Ƿ�������";
	cin >> n;
	func(n);
	system("pause");
	return 0;
}
