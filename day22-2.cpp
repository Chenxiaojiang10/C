//#include<iostream>
//#include<string>
//using namespace std;
////�ҵ��ַ����е�һ��ֻ����һ�ε��ַ�
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		// ͳ��ÿ���ַ����ֵĴ���
//		int count[256] = { 0 };
//		int size = s.size();
//		for (int i = 0; i < size; ++i)
//			count[s[i]] += 1;
//		// �����ַ������ǰ������ֻ����һ�ε��ַ�
//		for (int i = 0; i < size; ++i)
//			if (1 == count[s[i]])
//				return i;
//		return -1;
//	}
//};
//int main() {
//	string s;
//	Solution sol;
//	while (cin >> s) {
//		int a = sol.firstUniqChar(s);
//		if (a == -1) {
//			cout << a << endl;
//		}
//		else {
//			cout << s[a] << endl;
//		}
//	}	
//	return 0;
//}