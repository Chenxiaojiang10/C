#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 输入字符串input，字符串searchFor，及字符串replaceWith，将input中有方括号包围的searchFor，替换为replaceWith
	 * @param input string字符串 待处理的完整数据
	 * @param searchFor string字符串 查找的关键字
	 * @param replaceWith string字符串 将查找到的关键字替换为此字符串
	 * @return string字符串
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