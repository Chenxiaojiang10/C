#include<iostream>

//����ˮ���⣬3��ƿ�ӻ�һ��û�ȵ���ˮ
using namespace std;

int func(int n) {
	if (n == 2) {
		return 1;
	}
	if (n <= 1) {
		return 0;
	}
	
	return n / 3 + func(n / 3 + n % 3);
}

int main() {
	int n = 0;
	while (cin >> n) {
		if (n != 0) {
			cout << func(n) << endl;
		}
	}
	return 0;
}