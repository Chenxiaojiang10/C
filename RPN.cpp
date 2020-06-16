class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const auto& str : tokens) {
			//运算符
			if (str == "+" || str == "-"
				|| str == "/" || str == "*") {
				//左操作数
				int right = st.top();
				st.pop();
				//右操作数
				int left = st.top();
				st.pop();
				if (str == "+") {
					st.push(left + right);
				}
				else if (str == "-") {
					st.push(left - right);
				}
				else if (str == "/") {
					st.push(left / right);
				}
				else if (str == "*") {
					st.push(left * right);
				}
			}
			//操作数
			else {
				st.push(stoi(str));
			}
		}
		return st.top();
	}
};