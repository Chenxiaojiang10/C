#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void DFS(vector<int> arr, int n, int d, int index, vector<int> tmp, stack<int> st, int& ret) {
	if (st.size() == 3) {
		int head = st.top();
		st.pop();
		st.pop();
		int rear = st.top();
		st.pop();

		if (head - rear <= d) {
			ret++;
			return;
		}
		else {
			return;
		}
	}


	for (int i = index; i < n; i++) {

		
		if (tmp[i] == 0) {
			if (st.size() > 0) {
				if (st.top() - arr[i] > d) {
					return;
				}
			}
			st.push(arr[i]);
			tmp[i] = 1;
			DFS(arr, n, d, index + 1, tmp, st, ret);
			st.pop();
		}
	}

}


void func(vector<int> arr, vector<int>& qwe, int i, int d) {
	qwe.clear();
	int n = arr.size();
	int max = arr[i] + 2 * d;
	for (int j = i; j < n; j++) {
		if (arr[j] > max) {
			break;
		}
		qwe.push_back(arr[j]);
	}

	//return qwe;
}


int main() {
	int n = 0;
	int d = 0;
	
	while (cin >> n >> d) {
		stack<int> st;
		int ret = 0;
		int index = 0;
		vector<int> arr(n, 0);
		vector<int> tmp(n, 0);  //1代表用过了，0代表没用过
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<int> qwe;
		for (int i = 0; i < n ; i++) {


			func(arr, qwe, i, d);
			DFS(qwe, n, d, index, tmp, st, ret);
			

		}


		cout << ret << endl;
	}

	return 0;
}









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