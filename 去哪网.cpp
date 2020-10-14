#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isTong(vector<string> arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i][0] != arr[i + 1][0]) {
			return false;
		}
	}
	return true;
}

bool huangjia(vector<int> tmp) {
	if (tmp[1] > 0 && tmp[10] > 0 && tmp[11] > 0 && tmp[12] > 0 && tmp[13] > 0) {
		return true;
	}
	return false;
}

bool tonghuashun(vector<int> tmp) {
	for (int i = 2; i < 10; i++) {
		if (tmp[i] > 0 && tmp[i + 1] > 0 && tmp[i + 2] > 0 && tmp[i + 3] > 0 && tmp[i + 4] > 0) {
			return true;
		}
	}
	return false;
}

bool sitiao(vector<int> tmp) {
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 4) {
			return true;
		}
	}
	return false;
}

bool hulu(vector<int> tmp) {
	int a = -1;
	int b = -1;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 3) {
			a = 1;
		}
		if (tmp[i] == 2) {
			b = 1;
		}
	}
	if ((a + b) == 2) {
		return true;
	}
	return false;
}

bool shunzi(vector<int> tmp) {
	if (tmp[1] > 0 && tmp[10] > 0 && tmp[11] > 0 && tmp[12] > 0 && tmp[13] > 0) {
		return true;
	}
	for (int i = 2; i < 10; i++) {
		if (tmp[i] > 0 && tmp[i + 1] > 0 && tmp[i + 2] > 0 && tmp[i + 3] > 0 && tmp[i + 4] > 0) {
			return true;
		}
	}
	return false;
}

bool santiao(vector<int> tmp) {
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 3) {
			return true;
		}
	}
	return false;
}

bool liangdui(vector<int> tmp) {
	int k = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 2) {
			k++;
		}
	}
	if (k == 2) {
		return true;
	}
	return false;
}

bool yidui(vector<int> tmp) {
	int k = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 2) {
			k++;
		}
	}
	if (k == 1) {
		return true;
	}
	return false;
}

void func(vector<string>& arr, int n) {
	vector<int> tmp(14, 0);
	for (int i = 0; i < n; i++) {
		if (arr[i].size() == 3) {
			tmp[10]++;
		}
		else if (arr[i][1] == 'A') {
			tmp[1]++;
		}
		else if(arr[i][1] == 'J'){
			tmp[11]++;
		}
		else if (arr[i][1] == 'Q') {
			tmp[12]++;
		}
		else if (arr[i][1] == 'K') {
			tmp[13]++;
		}
		else {
			int o = (int)(arr[i][1] - '0');
			tmp[o]++;
		}
	}
	

	if (n >= 5 && isTong(arr, n)) {
		if (huangjia(tmp)) {
			cout << "HuangJiaTongHuaShun" << endl;
			return;
		}
		if (tonghuashun(tmp)) {
			cout << "TongHuaShun" << endl;
			return;
		}
	}

	if (sitiao(tmp)) {
		cout << "SiTiao" << endl;
		return;
	}

	if (hulu(tmp)) {
		cout << "HuLu" <<endl;
		return;
	}

	if (isTong(arr, n)) {
		cout << "TongHua" << endl;
		return;
	}

	if (shunzi(tmp)) {
		cout << "ShunZi" << endl;
		return;
	}

	if (santiao(tmp)) {
		cout << "SanTiao" << endl;
		return;
	}
	
	if (liangdui(tmp)) {
		cout << "LiangDui" << endl;
		return;
	}

	if (yidui(tmp)) {
		cout << "YiDui" << endl;
		return;
	}
	cout << "GaoPai" << endl;
	return;
}


int main() {
	int n;
	while (cin >> n) {
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		func(arr, n);
	}




	return 0;
}