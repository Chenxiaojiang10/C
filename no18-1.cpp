//#include<iostream>
//
//#include<string>
//using namespace std;
//
//void StrToInt(string& str) {
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == ' ') {
//			continue;
//		}
//		else if (str[i] >= '0' && str[i] <= '9') {
//			break;
//		}
//		else if (str[i] == '-')
//			continue;
//		else {
//			cout << '0' << endl;
//			return;
//		}
//	}
//
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == ' ') {
//			continue;
//			auto p = str.find(str[i]);
//			str.erase(p, 1);
//		}
//		else if (str[i] == '-' || str[i] == '+') {
//			continue;
//		}
//		else if (str[i] >= '0' && str[i] <= '9') {
//			continue;
//		}
//		else {
//			str.erase(i);
//		}
//	}
//
//	cout << str << endl;
//
//}
//
//void test(string& s) {
//
//	while (1) {
//		size_t pos = s.find(' ');
//		if (pos == string::npos) {
//			break;
//		}
//		s.erase(pos, 1);
//	}
//	
//	
//	int a = stoi(s, nullptr, 16);
//	cout << a << endl;
//
//
//}
//
//
//int main() {
//	string s;
//	while (getline(cin, s)) {
//		test(s);
//		//StrToInt(s);
//
//
//
//	}
//
//
//	return 0;
//}