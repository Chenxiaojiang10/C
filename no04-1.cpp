//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int flag = -1;
//void func(int* a,int* r) {
//	r[0] = (a[0] + a[2]) / 2;
//	r[1] = (a[1] + a[3]) / 2;
//	r[2] = a[3] - r[1];
//
//
//	if (r[0] - r[1] == a[0] && r[1] - r[3] == a[1] &&
//		r[0] + r[1] == a[2] && r[1] + r[2] == a[3]) {
//		flag = 1;
//	}
//
//	
//}
//
//
//int main() {
//	int a[4] = { 0 };
//	int res[3] = { 0 };
//	for (auto& x : a)
//		cin >> x ;
//	
//	
//	func(a, res);
//	if (flag == 1) {
//		for (auto x : res)
//			cout << x << " ";
//		cout << endl;
//	}
//	else {
//		cout << "no" << endl;
//	}
//	
//	
//
//	return 0;
//}