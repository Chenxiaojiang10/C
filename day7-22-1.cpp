#include<iostream>
#include<vector>
//洗牌
using namespace std;

vector<int> func(vector<int> a) {
	int ban = a.size() / 2;
	int* a1 = new int[ban];
	int* a2 = new int[ban];
	for (int i = 0; i < ban; i++) {
		a1[i] = a[i];
		a2[i] = a[i + ban];
	}
	for (int i = 0, j = 0; i < ban; i++, j++) {
		a[j] = a1[i];
		j++;
		a[j] = a2[i];
	}
	return a;
}

int main() {
	int h = 0;//有几组数据
	cin >> h;
	vector<vector<int>> a(h);
	int i = 0;

	while (i < h) {
		int n = 0;//每组2*n个数据
		int k = 0;//洗几遍
		cin >> n >> k;
		a[i].resize(2 * n);
		for (int j = 0; j < 2 * n; j++) {
			cin >> a[i][j];
		}
		int l = 0;
		while (l < k) {
			a[i] = func(a[i]);
			l++;
		}
		i++;
	}
	for (i = 0; i < h; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}