#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iostream>
#include <sstream>
using namespace std;
//数据库连接池
void func(vector<int> arr) {
	int sum = 1;//连接池初始为1
	int max = sum; //记录峰值
	vector<int> a1;
	int i = 0;
	while (i < arr.size() / 2) {
		if (arr[i * 2 + 1] == 0) {
			if (sum == 0) {  //当连接池没有连接了，就给连接池增加一个
				sum++;
				max++;
			}
			sum--;
		}
		else {
			sum++;
		}
		i++;
	}
	cout << max << endl;


}


int main() {
	int n;
	vector<int> arr;
	string s1;
	string s2;
	while (cin >> n) {
		arr.clear();

		while (n > 0) {
			cin >> s1 >> s2;
			arr.push_back((int)s1[0]);
			if (s2[0] == 'd') {
				arr.push_back(1);   //1代表断开
			}
			else {
				arr.push_back(0);  //0代表连接
			}
			n--;
		}
		func(arr);
	}
	return 0;
}

