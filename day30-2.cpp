//#include<iostream>
////����һ�������������ӵĸ��������ᳬʱ
//using namespace std;
//
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		int sum = 0;
//		int k = (int)sqrt(n);
//		for (int i = 2; i <= k; i++) {
//			if (n % i == 0) {
//				while (n % i == 0) {
//					n /= i;
//				}
//				sum++;
//			}
//		}
//		if (n == 1) {
//			cout << sum << endl;
//		}
//		else {
//			cout << ++sum << endl;
//		}
//	}
//	return 0;
//}