//#include<iostream>
//#include<string>
//#include<cstring>
//using namespace std;
////Í¨Åä·û£¿ºÍ*
//bool func(string s1, string s2) {
//	int p1 = 0;
//	int p2 = 0;
//	int i = 0;
//	int j = 0;
//	while (i < s1.size() && j < s2.size()) {
//		while (s1[i] == '?') {
//			i++;
//			j++;
//			if (j > s2.size()) {
//				return false;
//			}
//		}
//		
//		if (s1[i] == '*') {
//			while (s1[i + 1] == '?' || s1[i + 1] == '*') {
//				i++;
//			}
//			for (j = i; j < s2.size(); j++) {
//				
//				if (s1[i + 1] == s2[j]) {
//					break;
//				}
//			}
//			if (i + 1 == s1.size() && j == s2.size()) {
//				return true;
//			}
//			else {
//				i++;
//				//j++;
//			}
//		}
//		
//
//		if (s1[i] != s2[j]) {
//			return false;
//		}
//		i++;
//		j++;
//	}
//	return true;
//}
//
//int main() {
//	string s1, s2;
//	//cin >> s1 >> s2;
//	while (cin >> s1 >> s2) {
//		if (func(s1, s2)) {
//			cout << "true" << endl;
//		}
//		else {
//			cout << "false" << endl;
//		}
//	}
//	
//	return 0;
//}