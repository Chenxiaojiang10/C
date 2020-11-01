//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//void func(int n) {
//	if (n < 128) {
//		vector<int> arr(7, 0);
//		int i = 0;
//		while (n) {
//			if (n % 2 != 0) {
//				arr[i] = 1;
//			}
//			else {
//				arr[i] = 0;
//			}
//			n /= 2;
//			i++;
//		}
//		cout << 1;
//		for (int i = 6; i >= 0; i--) {
//			cout << arr[i];
//		}
//		cout << endl;
//	}
//	else if (n < 32768) {
//		vector<int> arr(15, 0);
//		int i = 0;
//		while(n){
//			if (i == 7) {
//				i++;
//				continue;
//			}
//			if (n % 2 != 0) {
//				arr[i] = 1;
//			}
//			else {
//				arr[i] = 0;
//			}
//			n /= 2;
//			i++;
//		}
//		arr[7] = 1;
//		cout << 0;
//		for (int i = 14; i >= 0; i--) {
//			cout << arr[i];
//		}
//		cout << endl;
//	}
//}
//
//
//int main() {
//	int n;
//	while (cin >> n) {
//		func(n);
//
//
//
//	}
//
//
//
//	return 0;
//}