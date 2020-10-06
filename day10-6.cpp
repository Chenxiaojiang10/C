#include<iostream>
#include<vector>
#include<string>
//字节跳动 ：万万没想到之聪明的编辑
using namespace std;

void func(string str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (it < str.end() - 2 && *it == *(it + 1) && *(it + 1) == *(it + 2)) { //AAA变成AA
			str.erase(it);
			it = str.begin();
			
		}
		else if (it < str.end() - 3 && *it == *(it + 1) && *(it + 2) == *(it + 3)) {  //AABB变成AAB
			str.erase(it + 2);
			it = str.begin();
			
		}
		else { 
			it++; 
		}
	}
	cout << str << endl;
}

//ssgllnggiaakhhlssobkkiuuyiisffwttjabzzxiimoobtt

//ssglnngiiakkhlssobkkiuuyiisffwttjabzzxiimoobttt

int main() {
	int n = 0;
	while (cin >> n) {
		vector<string> str(n);
		cin.clear(); //清除错误标记
		cin.ignore(); //清空缓冲区
		for (int i = 0; i < n ; i++) {
			getline(cin, str[i]);
		}
		for (int i = 0; i < n; i++) {
			func(str[i]);
		}
	}

	return 0;
}
