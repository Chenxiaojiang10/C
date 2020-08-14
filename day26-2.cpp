#include<iostream>
//快到碗里来
using namespace std;

bool func(double a, double b) {
	b = b * 2 * 3.14;
	if (a > b) {
		return false;
	}
	return true;
}

int main() {
	double a = 0;
	double b = 0;
	cin >> a >> b;
	if (func(a, b)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}