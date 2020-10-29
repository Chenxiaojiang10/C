#include<iostream>
#include<string>
#include<vector>

using namespace std;


//n*n矩阵顺时针旋转90°
vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
	// write code here
	int x = matrix.size();//行
	//int y = matrix[0].size();//列

	vector<vector<int>> arr(x);
	for (int i = 0; i < x; i++) {
		arr[i].resize(x);
	}

	for (int i = 0, n = x - 1; i < x; i++, n--) {
		for (int j = 0, m = 0; j < x; j++, m++) {
			arr[m][n] = matrix[i][j];
		}
	}
	return arr;
}


//二进制取反输出十进制
int ConvertData(int originData) {
	// write code here
	string s;
	int a = originData;
	while (a) {
		if (a % 2 != 0) {
			s.push_back('1');
		}
		else {
			s.push_back('0');
		}
		a /= 2;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			s[i] = '1';
		}
		else {
			s[i] = '0';
		}
	}
	reverse(s.begin(), s.end());
	int num = 0;
	int k = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			num += k;
		}
		k *= 2;
	}
	return num;
}

int main() {


	vector<vector<int>> a = { {0,1,2},{3,4,5},{6,7,8} };
	vector<vector<int>> b = RotateMatrix(a);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << ' ' ;
		}
		cout << endl;
	}
	return 0;
}