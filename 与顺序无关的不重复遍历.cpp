//#include<iostream>
//#include<vector>
//#include<stack>
//
////将1，2，3，4，遍历出来
////1-2-3
////1-2-4
////1-3-4
////2-3-4
//void func(vector<int> arr, int n, stack<int> st, int index, vector<int> tmp) {
//
//	if (st.size() == 3) {
//		cout << st.top() << "-";
//		st.pop();
//		cout << st.top() << "-";
//		st.pop();
//		cout << st.top() << endl;
//		st.pop();
//		return;
//	}
//
//
//
//	for (int i = index; i < n; i++) {
//		if (tmp[i] == 0) {
//			st.push(arr[i]);
//			tmp[i] = 1;
//			func(arr, n, st, index + 1, tmp);
//			st.pop();
//			//tmp[i] = 0;
//		}
//		
//		
//	}
//
//}
//
//
//int main() {
//	int a[4] = { 1,2,3,4 };
//	vector<int> arr(a, a+4);
//	vector<int> tmp(4, 0);
//	stack<int> st;
//	func(arr, 4, st, 0, tmp);
//	return 0;
//}