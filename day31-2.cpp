#include<iostream>
#include<vector>
#include<cmath>
//打印出一个整数的所有素因子，不会超时
using namespace std;
void func(int n, vector<int> arr) {
	int k = (int)sqrt(n);
	int m = n;
	int i;
	for (i = 2; i <= k; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				arr.push_back(i);
				n /= i;
			}
		}
	}
	if (n != 1) {
		arr.push_back(n);
	}
	cout << m << ' ' << '=' << ' ' << arr[0];
	for (i = 1; i < arr.size(); i++) {
		cout << ' ' << '*' << ' ' << arr[i];
	}
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> arr;
	func(n, arr);
	return 0;
}
