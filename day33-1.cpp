#include<iostream>
#include<string>

using namespace std;
//��������,���ǲ��ҵ�һ���ַ������м����ڶ����ַ���
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
