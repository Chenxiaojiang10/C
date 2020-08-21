#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//收件人列表
//输入二维字符串数组，我们把这些弄成一个长的字符串输出

int main() {
	int n = 0;
	string s;
	string str;
	while (cin >> n) {
		s.clear();
		for (int i = 0; i <= n; i++) {
			str.clear();
			getline(cin, str);
			if (str.find(',') != -1 || str.find(' ') != -1) {
				if (s.size() == 0) {
					s.push_back('"');
					s += str;
					s.push_back('"');
				}
				else {
					s.push_back(',');
					s.push_back(' ');
					s.push_back('"');
					s += str;
					s.push_back('"');
				}
			}
			else {
				if (s.size() == 0) {
					s = str;
				}
				else {
					s.push_back(',');
					s.push_back(' ');
					s += str;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}