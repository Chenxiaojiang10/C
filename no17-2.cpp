//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//using namespace std;
////×Ö·û´®¼Ó·¨
//void func(string s1, string s2) {
//	if (s1.size() < s2.size()) {
//		swap(s1, s2);
//	}
//	int len1 = s1.size();
//	int len2 = s2.size();
//	int g = len1 - len2;
//	reverse(s2.begin(), s2.end());
//	for (int i = 0; i < g; i++) {
//		s2.push_back('0');
//	}
//	//cout << s2 << endl;
//	reverse(s1.begin(), s1.end());
//	//cout << s1 << endl;
//
//
//
//	char* res = new char[len1 + 2];
//	memset(res, 0x00, len1 + 1);
//	char tmp = 0;
//	char flag = 0;
//	for (int i = 0; i < len1; i++) {
//		tmp = s1[i] - '0' + s2[i] - '0' + flag;
//		flag = tmp / 10;
//		res[i] = tmp % 10 + '0';
//	}
//	//cout << res << endl;
//	string r = res;
//	//cout << r << endl;
//	if (flag == 1) {
//		r.push_back('1');
//	}
//	reverse(r.begin(), r.end());
//	cout << r << endl;
//}
//
//
//
//int main() {
//	string s1;
//	string s2;
//	while (cin >> s1 >> s2) {
//		func(s1, s2);
//	}
//	return 0;
//}