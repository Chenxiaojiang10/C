//#include<iostream>
//#include<vector>
//using namespace std;
////杨辉三角的变形
//void func(int n) {
//	int i, j;
//
//	//vector建二维数组
//	vector<vector<int>> arr(n);
//	for (i = 0; i < n; i++) {
//		arr[i].resize(3 + 2 * n);
//	}
//
//
//	int mid = (1 + 2 * n / 2) ;
//	for (i = 0; i < 3 + 2 * n; i++) {
//		if (i == mid) {
//			arr[0][mid] = 1;
//			continue;
//		}
//		arr[0][i] = 0;
//	}
//	for ( i = 1; i < n; i++) {
//		for (j = 0; j < 3 + 2 * n; j++) {
//			if (j == 0 || j == 3 + 2 * n - 1) {
//				arr[i][j] = 0;
//				continue;
//			}
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
//		}
//	}
//	for (i = 0; i < 3 + 2 * n; i++) {
//		if (arr[n - 1][i] != 0 && arr[n - 1][i] % 2 == 0) {
//			//cout << arr[n - 1][i] << endl;
//			cout << i -1 << endl;
//			break;
//		}
//	}
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < 3 + n * 2; j++) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		func(n);
//	}
//	return 0;
//}