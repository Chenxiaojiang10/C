#include <iostream>  
using namespace std;
/*交换函数 使用指针传参*/
void swap(int* m, int* n)   //形参是指针变量
{
	int temp = *m;           //使*m和*n互换
	*m = *n;
	*n = temp;
}
/* 使用引用传参 */
void swap(int& m, int& n)     //形参是整数类型变量的引用  
{
	int temp = m;
	m = n;
	n = temp;
}
int main()
{
	int a = 3;
	int b = 5;
	cout << "转化前: a=" << a << " b=" << b << endl;
	swap(&a, &b);     //调用指针传参函数
	cout << "指针传参转换后：a=" << a << " b=" << b << endl;
	swap(a, b);     //调用引用传参函数
	cout << "引用传参调用转换后：a=" << a << " b=" << b << endl;
	return 0;
}
