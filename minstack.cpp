class MinStack {
	//ื๎ะกีป
private:
	stack<int> st;
	stack<int> minst;
public:
	void push(int x) {
		if (minst.empty() || x <= minst.top()) {
			minst.push(x);
		}
		st.push(x);
	}
	void pop() {
		if (st.top() == minst.top()) {
			minst.pop();
		}
		st.pop();
	}
	int top() {
		return st.top();
	}
	int getMin() {
		return minst.top();
	}
};