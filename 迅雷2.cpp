#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	/**
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 * �����ַ���input���ַ���searchFor�����ַ���replaceWith����input���з����Ű�Χ��searchFor���滻ΪreplaceWith
	 * @param input string�ַ��� ���������������
	 * @param searchFor string�ַ��� ���ҵĹؼ���
	 * @param replaceWith string�ַ��� �����ҵ��Ĺؼ����滻Ϊ���ַ���
	 * @return string�ַ���
	 */
	string SearchAndReplace(string input, string searchFor, string replaceWith) {
		// write code here
		string str;
		for (int i = 0; i < input.size(); i++) {
			int flag = 1;
			if (input[i] == '[' && (i + searchFor.size()) < input.size()) {
				int k = i + 1;
				int p = i;
				//auto p = input.find(input[k - 1]);

				for (int j = 0; j < searchFor.size(); j++) {
					if (input[k] == searchFor[j]) {
						k++;
					}
					else {
						flag = -1;
						break;
					}
				}
				if (input[k] == ']' && flag == 1) {
					//input.erase(p,k - p);
					for (int j = 0; j < replaceWith.size(); j++) {
						str.push_back(replaceWith[j]);
					}
					i += searchFor.size() + 1;
				}

			}
			else if (int flag = -1) {
				str.push_back(input[i]);
			}
		}
		return str;
	}
};

int main() {
	char s11[] = "shabi [xunlei] 123";
	char s22[] = "xunlei";
	char s33[] = "chunshabi";
	string s1(s11, s11 + 19);
	string s2 = { "xunlei" };
	string s3 = { "shab" };
	Solution s;
	string ss = s.SearchAndReplace(s1, s2, s3);
	
	for (auto e : ss) {
		cout << e;
	}

	cout << endl;

}