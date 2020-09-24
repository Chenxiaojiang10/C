//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
////ÍêÈ«Êı
//bool isNum(int x) {
//	int sum = 0;
//	int a = sqrt(x);
//	int i = 2;
//	while (i <= a) {
//		if (x % i == 0) {
//			sum += i;
//			sum += x / i;
//		}
//		i++;
//	}
//	if (sum + 1 == x) {
//		return true;
//	}
//	return false;
//}
//
//
//int func(int n) {
//	int count = 0;
//	for (int i = 2; i < n; i++) {
//		if (isNum(i)) {
//			count++;
//			//cout << i << endl;
//		}
//	}
//	return count;
//}
//
//
//int main() {
//	int n = 0;
//	cin >> n;
//	cout << func(n) << endl;
//
//	return 0;
//}