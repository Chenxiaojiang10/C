#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void func(vector<char> a, vector<char> b, int n, int m) {
	vector<vector<int>> arr(n + 1);
	for (int i = 0; i < n + 1; i++) {
		arr[i].resize(m + 1, 0);
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == b[j - 1]) {//这里减去一是因为这个二维数组长宽比原始字符串多一位
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << arr[n][m] << endl;
}



int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<char> arr1(n);
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		vector<char> arr2(m);
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		func(arr1, arr2, n, m);
	}
	return 0;
}