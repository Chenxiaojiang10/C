#include<iostream>
#include<string>
using namespace std;
//分数计算器，很烦，没做完

//最大公约数
int GCD(int x, int y)
{
	int r = x % y;
	while (r) {
		x = y;
		y = r;
		r = x % y;
	}
		
	return y;
}
//最小公倍数
int LCM(int a, int b) {
	return a  * b / GCD(a, b);
}

void func(string s1, string s2) {
	int a1 = 0;
	int	b1 = 0;
	int a2 = 0;
	int	b2 = 0;
	int sum1 = 0;
	int sum2 = 0;
	string str1;
	string str2;
	auto pos1 = s1.find('/');
	auto pos2 = s2.find('/');
	int a11, a22;//分子的替身，打印a11，a22上，计算a1，a2上。
	//cout << pos1 << '='<< (int)pos2 << endl;
	//====s1的=====
	//非负数的情况（分子）
	int lo = 1;
	if (s1[0] != '-') {
		for (int i = (int)(pos1 - 1); i >= 0; i--) {
			a1 += (int)(s1[i] - '0') * lo;
			lo *= 10;
		}
		//cout << a1 << endl;
	}
	//负数的情况（分子）
	else if (s1[0] == '-') {
		for (int i = (int)(pos1 - 1); i > 0; i--) {
			a1 += (int)(s1[i] - '0') * lo;
			lo *= 10;
		}
		a1 = a1 * -1;
		//cout << a1 << endl;
	}
	lo = 1;
	for (int i = s1.size() - 1; i > (int)pos1; i--) {
		b1 += (int)(s1[i] - '0') * lo;
		lo *= 10;
	}
	//cout << b1 << endl;

	a1 = a1 / GCD(a1, b1);
	b1 = b1 / GCD(a1, b1);
	int c1 = a1 / b1;
	if (c1 != 0) {
		a11 = a1 - c1 * b1;
	}

	



	//====s2的=====s2
	//非负数的情况
	lo = 1;
	if (s2[0] != '-') {
		for (int i = (int)(pos2 - 1); i >= 0; i--) {
			a2 += (int)(s2[i] - '0') * lo;
			lo *= 10;
		}
		//cout << a2 << endl;
	}
	//负数的情况（分子）
	else if (s2[0] == '-') {
		for (int i = (int)(pos2 - 1); i > 0; i--) {
			a2 += (int)(s2[i] - '0') * lo;
			lo *= 10;
		}
		a2 = a2 * -1;
		//cout << a2 << endl;
	}
	lo = 1;
	for (int i = s2.size() - 1; i > (int)pos2; i--) {
		b2 += (int)(s2[i] - '0') * lo;
		lo *= 10;
	}
	//cout << b2 << endl;
	
	//把两个数约分成最简模式
	
	a2 = a2 / GCD(a2, b2);
	b2 = b2 / GCD(a2, b2);
	
	int c2 = a2 / b2;
	
	
	if (c2 != 0) {
		a22 = a2 - c2 * b2;
	}
	//计算结果
	int res1 = 0;
	int res2 = 0;

	res2 = LCM(b1, b2);//结果的分母=两数的最大公约数
	int sub = (a1 * (res2 / b1)) - (a2 * (res2 / b2));//加运算
	int add = (a1 * (res2 / b1)) + (a2 * (res2 / b2));//减运算
	//把结果划到最简模式
	sub = sub / GCD(sub, res2);
	add = add / GCD(add, res2);
	int res2_sub = res2 / GCD(sub, res2);
	int res2_add = res2 / GCD(add, res2);
	int c_sub = res2_sub / res2;
	int c_add = res2_add / res2;

	int aux = pow(10, (int)pos1);
	//把数字再装回字符串中str1
	if (a1 == 0) {
		str1.push_back('0');
	}
	else if (a1 != 0 && s1[0] == '-') {
		str1.push_back('(');
		str1.push_back('-');
		if (c1 > 0) {
			str1.push_back(c1);
			str1.push_back(' ');
		}
		while (a1 > 0) {
			str1.push_back((a1 / aux) + '0');
			a1 %= aux;
			aux /= 10;
		}
		str1.push_back('/');
		while (b1 > 0) {
			str1.push_back((b1 / aux) + '0');
			b1 %= aux;
			aux /= 10;
		}
		str1.push_back(')');
	}
	else {
		if (c1 > 0) {
			str1.push_back(c1);
			str1.push_back(' ');
		}
		while (a1 > 0) {
			str1.push_back((a1 / aux)+'0');
			a1 %= aux;
			aux /= 10;
		}
		str1.push_back('/');
		while (b1 > 0) {
			str1.push_back((b1 / aux)+'0');
			b1 %= aux;
			aux /= 10;
		}
	}

	cout << str1 << endl;


	cout << a1 << '/' << b1 << '+' << a2 << '/' << b2 << '=' << add << '/' << res2 << endl;

}

int main() {
	string s1;
	string s2;
	while (cin >> s1) {
		cin >> s2;
		func(s1, s2);
	}
	
	
	return 0;
}