#include<iostream>
#include<string>
#include<vector>
using namespace std;
//mkdir的功能
void func(vector<string> arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i].size() > arr[j].size()) {
				//保证短的在上边
				swap(arr[i], arr[j]);
			}
			int l;
			for (l = 0; l < arr[i].size(); l++) {  //判断两个字符串是否在小段的范围内相等
				if (arr[i][l] != arr[j][l]) {
					break;
				}
			}
			if (l == arr[i].size() && (arr[j][l] == '/' || (arr[i].size() == arr[j].size()))) {  //如果是一个字符串的子串，那就删除这个字符串
				arr[i].clear();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i].size() != 0) {
			cout << "mkdir -p " << arr[i] << endl;
		}
	}
}

int main() {
	int n = 0;
	while (cin >> n) {
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		func(arr, n);
	}
	return 0;
}