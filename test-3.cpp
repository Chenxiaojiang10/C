//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
////24点游戏规则
//int suanfa(int a, int b, int flag) {
//	if (flag == 0) {
//		return a + b;
//	}
//	else if (flag == 1) {
//		return a - b;
//	}
//	else if (flag == 2) {
//		return a * b;
//	}
//	else {
//		return a / b;
//	}
//}
//
//
//
//
//
//void func(int a, int b, int c, int d) {
//	int sum = 0;
//	for (int i = 0; i < 4; i++) {
//		sum = suanfa(a, b, i);
//		for (int j = 0; j < 4; j++) {
//			sum = suanfa(sum, c, j);
//			for (int k = 0; k < 4; k++) {
//				sum = suanfa(sum, d, k);
//				if (sum == 24) {
//					cout << "true" << endl;
//					return;
//				}
//			}
//		}
//	}
//	cout << "false" << endl;
//}
//
//
//int main() {
//	vector<int> arr(4);
//	int a;
//	for (int i = 0; i < 4; i++) {
//		cin >> a;
//		arr.push_back(a);
//	}
//	
//	sort(arr.begin(), arr.end());
//	do {
//		func(arr[0], arr[1], arr[2], arr[3]);
//	} while (next_permutation(arr.begin(), arr.end()));
//	return 0;
//}