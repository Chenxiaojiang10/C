//#include<iostream>
//#include<vector>
////С�׵�����֮·
//using namespace std;
//int gcd(int m, int n) {
//	if (n == 0)
//		return m;
//	else
//		return gcd(n, m % n);
//}
//
////���������
//int GCD(int a, int b) {
//	//���ٳ���һ������
//	while (a % 2 == 0 && b % 2 == 0) {
//		a /= 2;
//		b /= 2;
//	}
//	if (a < b) {
//		swap(a, b);
//	}
//	int c = b;
//	while (1) {
//		c = a - b;
//		if (c < b) {
//			a = b;
//			b = c;
//		}
//		else if (c > b) {
//			a = c;
//			b = b;
//		}
//		else {
//			return c;
//		}
//	}
//	return 1;
//}
//
//int func(int n, int a, vector<int> arr) {
//	int i = 0;
//	while (i < arr.size()) {
//		if (a >= arr[i]) {
//			a += arr[i];
//		}
//		else {
//			a += gcd(a, arr[i]);
//		}
//		i++;
//	}
//	return a;
//}
//
//int main() {
//	int n = 0;//������
//	int a = 0;//��ʼս����
//	while (cin >> n >> a) {
//		vector<int> arr(n);
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		int end = func(n, a, arr);
//		cout << end << endl;
//	}
//
//	/*for (int i = 0; i < n; i++) {
//		cout << arr[i] << endl;
//	}*/
//	return 0;
//}