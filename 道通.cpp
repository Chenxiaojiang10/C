//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//void func1(vector<string>& str, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (strcmp(str[j].c_str(), str[j + 1].c_str()) > 0) {
//				string tmp = str[j];
//				str[j] = str[j + 1];
//				str[j + 1] = tmp;
//			}
//		}
//	}
//	for (auto e : str) {
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void func2(vector<string>& str, int n) {
//	
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (str[j].size() > str[j + 1].size()) {
//				string tmp = str[j];
//				str[j] = str[j + 1];
//				str[j + 1] = tmp;
//			}
//		}
//	}
//	for (auto e : str) {
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<string> str(n);
//		for (int i = 0; i < n; i++) {
//			cin >> str[i];
//		}
//		func1(str, n);
//		func2(str, n);
//
//	}
//	return 0;
//}
//
//
