//static string str[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//class Solution {
//public:
//	void func(string& digits, vector<string>& ch, string cur, int dep) {
//		//结束一个答案，向上回溯，寻找l其他答案
//		if (dep == digits.size()) {
//			if (!cur.empty())
//				ch.push_back(cur);
//			return;
//		}
//		//找到当前字符在string映射表中的位置
//		int tmp = digits[dep] - '0';
//		string s = str[tmp];
//		//遍历每一种可能的组合
//		for (auto& e : s) {
//			func(digits, ch, cur + e, dep + 1);
//		}
//	}
//	vector<string> letterCombinations(string digits) {
//		vector<string> ch;
//		func(digits, ch, "", 0);
//		return ch;
//	}
//};