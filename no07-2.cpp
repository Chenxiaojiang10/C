//class Parenthesis {
//public:
//	//判断字符串的括号是否匹配
//	bool chkParenthesis(string A, int n) {
//		// 元素个数为奇数个绝对不匹配
//		if (n % 2 != 0) {
//			return false;
//		}
//		int count = 0; //记录有多少个左括号
//		int i = 0;
//		while (A[i] != '\0') {
//			if (A[i] == ')') {
//				if (count > 0) {  //出现一个右括号，左括号记录数减一
//					count--;
//				}
//				else {
//					return false;  //只有右括号，没有左括号的情况
//				}
//			}
//			else if (A[i] == '(') {  //左括号记录数加一
//				count++;
//			}
//			else {
//				return false;   //字符串中有不是括号的字符
//			}
//			i++;
//		}
//		if (count == 0) {  //最好看左括号是否抵消了所有的右括号
//			return true;
//		}
//		return false;
//	}
//};