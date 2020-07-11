//#include<iostream>
////最近的构成斐波那契de步数
//using namespace std;
//int func(int x) {
//	int a = 0;
//	int b = 1;
//	int c = 1;
//	if (x == 1) {
//		return 0;
//	}
//	while (a < x) {
//		a = b + c;
//		c = b;
//		b = a;
//	}
//	return (a - x) < (x - c) ? (a - x) : (x - c);
//}
//
//int main() {
//	int a;
//	cin >> a;
//	cout << func(a) << endl;
//	return 0;
//}