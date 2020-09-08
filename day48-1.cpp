//#include<iostream>
//#include<vector>
//using namespace std;
////左右最值的差值
//class MaxGap {
//public:
//	int maxfunc(vector<int> a, int begin, int end) {
//		int max = a[begin];
//		for (int i = begin; i <= end; i++) {
//			if (a[i] > max) {
//				max = a[i];
//			}
//		}
//		return max;
//	}
//
//	int findMaxGap(vector<int> A, int n) {
//		// write code here
//		int a, b;
//		vector<int> tmp;
//
//		for (int i = 0; i <= n - 2; i++) {
//			a = maxfunc(A, 0, i);
//			b = maxfunc(A, i + 1, n - 1);
//			int c = a - b;
//			if (c < 0) {
//				c *= -1;
//			}
//			tmp.push_back(c);
//		}
//		int max = 0;
//		for (int i = 0; i < tmp.size(); i++) {
//			if (tmp[i] > max) {
//				max = tmp[i];
//			}
//		}
//		return max;
//	}
//};
//
//int main() {
//	vector<int> arr = { 28,75,38,44,66,1 };
//	MaxGap m;
//	cout << m.findMaxGap(arr, 6) << endl;
//
//
//	return 0;
//}