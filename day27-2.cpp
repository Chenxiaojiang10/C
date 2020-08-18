#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
//判断是否构成三角形
bool func(int a, int b, int c) {
	if (a + b > c&& a + c > b&& b + c > a) {
		return true;
	}
	return false;
}
//不用加减乘除实现两整数的加法
int Add(int num1, int num2)
{
	int a = num1, b;
	while (a != 0) {
		a = (num1 & num2) << 1;
		b = num1 ^ num2;
		num1 = a;
		num2 = b;
	}
	return num2;
}

int Add2(int num1, int num2)
{
	string s1(num1, 'a');
	string s2(num2, 'b');
	for (auto& p : s2) {
		s1.push_back(p);
	}
	return s1.size();
}

int main() {

	/*int a, b, c;
	cin >> a >> b >> c;
	if (func(a, b, c)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}*/
	int t, y;
	cin >> t >> y;
	cout << Add2(t, y) << endl;
	
	return 0;
}