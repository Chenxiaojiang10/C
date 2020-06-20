//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int> st;
//		int pushidx = 0;
//		int popidx = 0;
//		while (pushidx < pushV.size()) {
//			st.push(pushV[pushidx++]);
//			while (!st.empty() && st.top() == popV[popidx]) {
//				st.pop();
//				popidx++;
//			}
//		}
//		return st.empty();
//	}
//};