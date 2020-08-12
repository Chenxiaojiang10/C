#include<iostream>

//喝汽水问题，3个瓶子换一个没喝的汽水
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