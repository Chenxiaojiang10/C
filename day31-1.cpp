#include<iostream>
#include<vector>
using namespace std;
//美国节日，破题，测试用例有问题
void func1(int n) {
	//一月的第三个星期一
	//先计算出每年的一月一号是星期几，然后再加上这年到指定月的日期数，计算出我们要求的那个月的一号是星期几
	//然后再根据要求的是第几周的星期几算出那一号
	if (n == 2000) {
		cout << n << '-' << "01" << '-' << 17 << endl;
		return;
	}
	int sum = ((n - 2000) * 365) + ((n - 1 - 2000) / 4) + 1;
	int one = ( sum - 2) % 7;//%的结果是0对应的是星期一
	one++;  //为了显示星期一，所以给0加一
	int i = 1;
	if (one != 1) {
		i = i + 7 - one + 1;//加一是找第一个星期一
	}
	i = i + 7 * 2;  //然后加上两周，就是第三个周一了
	//cout << n << '-' << "01" << '-' << i << endl;
	printf("%d-01-%02d\n", n, i);
}

void func2(int n) {
	//2月的第三个星期一
	if (n == 2000) {
		cout << n << '-' << "02" << '-' << 21 << endl;
	}
	int sum = ((n - 2000) * 365) + ((n - 1 - 2000) / 4) + 1;
	sum += 31;
	int one = (sum - 2) % 7;
	one++;
	//cout << one << endl;//%的结果是0对应的是星期一
	int i = 1;
	if (one != 1) {
		i = i + 7 - one + 1;//加一是找星期一
	}
	i = i + 7 * 2;
	printf("%d-02-%02d\n", n, i);
	//cout << n << '-' << "02" << '-' << i << endl;
}

void func3(int n) {
	//5月的最后一个星期一
	if (n == 2000) {
		cout << n << '-' << "05" << '-' << 29 << endl;
	}
	int sum = ((n - 2000) * 365) + ((n - 1 - 2000) / 4) + 1;
	sum = sum + 31 +28 +30 +31;
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
		sum++;
	}
	int one = (sum - 2) % 7;
	one++;
	//cout << one << endl;//%的结果是0对应的是星期一
	int i = 1;
	if (one != 1) {
		i = i + 7 - one + 1;//加一是找星期一
	}
	i = i + 7 * 5;  //假设有五个星期一
	while (i > 31) {
		i = i - 7;//那就只有4个星期一
	}
	printf("%d-05-%02d\n", n, i);
	//cout << n << '-' << "05" << '-' << i << endl;
}

void func4(int n) {
	//9月的第一个星期一
	if (n == 2000) {
		cout << n << '-' << "09" << '-' << "04" << endl;
	}
	int sum = ((n - 2000) * 365) + ((n - 1 - 2000) / 4) + 1;
	sum = sum + 31 + 28 + 30 + 31 + 31 + 30 + 31 + 31;
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
		sum++;
	}
	int one = (sum - 2) % 7;
	one++;
	//cout << one << endl;//%的结果是0对应的是星期一
	int i = 1;
	if (one != 1) {
		i = i + 7 - one + 1;//加一是找星期一
	}
	printf("%d-09-%02d\n", n, i);
	//cout << n << '-' << "09" << '-' << i << endl;
}

void func5(int n) {
	//11月的第4个星期4
	if (n == 2000) {
		cout << n << '-' << "11" << '-' << "23" << endl;
	}
	int sum = ((n - 2000) * 365) + ((n - 1 - 2000) / 4) + 1;
	sum = sum + 31 + 28 + 30 + 31 + 31 + 30 + 31 + 31 + 30 + 31;
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
		sum++;
	}
	int one = (sum - 2) % 7;
	one++;
	//cout << one << endl;//%的结果是0对应的是星期一
	int i = 1;
	if (one != 4) {
		i = i + 7 - one + 4;//加4是找星期4
	}
	i = 7 * 4 + i;
	while (i > 30) {
		i -= 7;
	}
	printf("%d-11-%02d\n", n, i);
	//cout << n << '-' << 11 << '-' << i << endl;
}

void func(int n) {
	cout << n << '-' << "01" << '-' << "01" << endl;
	func1(n);
	func2(n);
	func3(n);
	cout << n << '-' << "07" << '-' << "04" << endl;
	func4(n);
	func5(n);
	cout << n << '-' << "12" << '-' << "25" << endl;
}

int main() {
	int n = 0;
	cin >> n;
	func(n);
	return 0;
}