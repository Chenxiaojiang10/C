#include<iostream>
#include<string>
//将字符串转成int整数
using namespace std;


class Solution {
public:

	bool NotIsNumber(char s) {
		if ((s > '0' && s < '9') || s == ' ' || s == '-' || s == '+') {
			return false;
		}
		return true;
	}

	int StrToInt(string str) {
		int flag = 1;//正数
		int i = 0;
		for (; i < (int)str.size(); i++) {
			if (str[i] != ' ') {
				break;
			}
		}
		if (str[i] == '-') {
			flag = -1;
		}

		string::reverse_iterator it = str.rbegin();
		int m = 1;
		int sum = 0;
		//cout << *(str.end() - 1 )<< endl;
		while (it != str.rend()) {
			if (NotIsNumber(*it)) {
				return 0;
			}
			if (*it == ' ' || *it == '-' || *it == '+') {
				++it;
				continue;
			}
			sum += ((int)*it - 48) * m;
			m *= 10;
			//cout << *it << endl;
			++it;
		}

		return sum * flag;
	}
};

int main() {
	
	string str("-123");
	Solution s;
	cout << s.StrToInt(str) << endl;
	return 0;
}

//1a33