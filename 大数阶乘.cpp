#include <iostream>//大数的阶乘
#include<string>
//#include<cmath>
using namespace std;
//类型转换
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
//阶乘计算
void func(int num)
{
	int* arr = new int[num];//100以内不会越界，但是很大的话还是会越界的
	string* str = new string[num];
	int length = 1;//100的阶乘一开始最大的两个数相乘不会超过一万，所有我们以一万为单位，初始运算所占数组长度为1
	int temp = 0;
	int c_num = 0;//进位
	arr[0] = 1;// 初始化 a[0] 让其第一次运算结果等于 该数本身
	int j = 0;
	for (int i = num; i > 1; i--)
	{
		for (j = 0; j < length; j++)
		{
			if (j == 0)//在首个数组元素中运算不需要加进位
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
		transform(str[j], arr[j]);//整型转字符型
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
	delete[] arr;//释放
	delete[] str;
}
int main()
{
	int n = 0;
	cout << "输入一个非符整数：";
	cin >> n;
	func(n);
	system("pause");
	return 0;
}
