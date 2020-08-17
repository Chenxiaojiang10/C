#include<iostream>
#include<string>
//Êý¸ù
using namespace std;
int func1(string s) {
	int m = 0;
	while (s.size() > 0) {
		m += (int)(s.back() - '0');
		s.pop_back();
	}
	return m;
}
string func2(int m) {
	string s;
	while (m > 0) {
		s.push_back((char)(m % 10 + '0'));
		m /= 10;
	}
	return s;
}

int func(string s) {
	string s1;
	int m = 0;
	if (s.size() == 1) {
		return (int)(s[0] - '0');
	}
	else {
		m = func1(s);
		while (m > 9) {
			s1 = func2(m);
			m = func1(s1);
		}
		return m;
	}
	return m;
}

int main() {
	string s;
	cin >> s;
	cout << func(s) << endl;
	return 0;
}
