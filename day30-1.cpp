//#include<iostream>
//#include<string>
//
////���ܷ�ʽ����ĸ��ǰ��5λ
//using namespace std;
//void func(string s) {
//	int i = 0;
//	while (i < s.size()) {
//		if (s[i] == ' ') {
//			i++;
//			continue;
//		}
//		if (s[i] <= 'E') {
//			s[i] = s[i] + 26 - 5;
//		}
//		else {
//			s[i] = s[i] - 5;
//		}
//		i++;
//	}
//	cout << s << " ";
//}
//
//
//int main() {
//	string s;
//	
//	while (getline(cin, s)) {
//		func(s);
//		cout << endl;
//	}
//	return 0;
//}