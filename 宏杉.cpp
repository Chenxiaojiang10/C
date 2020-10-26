#include<iostream>
#include<vector>

using namespace std;

bool zhishu(int n) {
	if (n <= 1)
		return false;
	int i = 2;
	while (i < (n / 2)) {
		if (n % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}


void func(int n) {
	int m = n;
	vector<int> arr;
	int i = 2;
	while (i <= n) {
		if (zhishu(i) && (n % i == 0)) {
			n /= i;
			arr.push_back(i);
			i = 2;
		}
		else {
			i++;
		}

	}
	cout << m << '=';
	cout << arr[0];
	if (arr.size() > 1) {
		for (int j = 1; j < arr.size(); j++) {
			cout << '*' << arr[j];
		}
	}
	
	cout << endl;
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		func(n);
	}

	return 0;
}