//static string str[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//class Solution {
//public:
//	void func(string& digits, vector<string>& ch, string cur, int dep) {
//		//����һ���𰸣����ϻ��ݣ�Ѱ��l������
//		if (dep == digits.size()) {
//			if (!cur.empty())
//				ch.push_back(cur);
//			return;
//		}
//		//�ҵ���ǰ�ַ���stringӳ����е�λ��
//		int tmp = digits[dep] - '0';
//		string s = str[tmp];
//		//����ÿһ�ֿ��ܵ����
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