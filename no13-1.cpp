//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<cstdio>
//#include<istream>
//#include<string>
//using namespace std;
////根据空格和冒号，分开拆分打印字符串
//void func(string str) {
//	vector<string> s;
//	int prev, end;
//	int i = 0;
//	char tmp[1024] = { 0 };
//	for (i = 0; i < str.size(); i++) {
//		if (str[i] == ' ' || str[i] == '"') {
//			break;
//		}
//		tmp[i] = str[i];
//	}
//	s.push_back(tmp);
//	memset(tmp, 0, 1024);
//	while (i < str.size()) {
//		if (str[i] == ' ') {
//			
//			i++;
//			prev = i;
//			
//			if (str[prev] == 34) {
//				while (i < str.size() && str[i+1] != 34) {
//					i++;
//				}
//				i++;
//			}
//			else {
//				while (i < str.size() && str[i + 1] != ' ') {
//					i++;
//				}
//			}
//			
//			end = i + 1;
//			int x = end - prev;
//			for (int j = 0; j < x; j++) {
//				tmp[j] = str[prev];
//				prev++;
//			}
//			s.push_back(tmp);
//			memset(tmp, 0, 1024);			
//		}
//		i++;
//	}
//	cout << s.size() << endl;
//	for (auto &p : s) {
//		cout << p << endl;
//	}
//}
//
//int main() {
//	string s;
//	getline(cin, s);
//	func(s);
//	return 0;
//}