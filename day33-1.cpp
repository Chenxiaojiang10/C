#include<iostream>
#include<string>

using namespace std;
//剪画布条,就是查找第一个字符串中有几个第二个字符串
void func(string s, string s1) {
	int sum = 0;
	while (1) {
		auto p = s.find(s1);
		if (p == -1) {
			break;
		}
		s.erase(p, s1.size());
		sum++;
	}
	cout << sum << endl;
}


int main() {
	string s;
	string s1;
	while (cin >> s) {
		cin >> s1;
		func(s, s1);
	}
	

	return 0;
}
