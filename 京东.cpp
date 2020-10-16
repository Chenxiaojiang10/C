//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//int func(vector<vector<int>> arr, vector<int> tmp, int n) {
//	for (int i = 0; i < tmp.size() / 2; i++) {
//		if (arr[tmp[i]][tmp[i + 1]] == 1) {
//			return 1;
//		}
//		else {
//			return -1;
//		}
//	}
//	
//
//
//}
//
//
//int main() {
//	int n, m, p;
//	cin >> n >> m >> p;
//	vector<int> tmp(2*m);
//	for (int i = 0; i < 2 * m; i++) {
//		cin >> tmp[i];
//	}
//	
//	//构造二维数组
//	vector<vector<int>> arr(n);
//	for (int i = 0; i < n; i++) {
//		arr[i].resize(n, 0);
//	}
//	for (int i = 0; i < tmp.size() / 2; i += 2) {
//		arr[tmp[i]][tmp[i + 1]] = 1;
//	}
//	
//	vector<int> tmp2(2 * p);
//	for (int i = 0; i < 2 * p; i++) {
//		cin >> tmp2[i];
//	}
//
//	if (func(arr, tmp, n)) {
//		cout << "YES" << endl;
//	}
//	else {
//		cout << "NO" << endl;
//	}
//	return 0;
//}
