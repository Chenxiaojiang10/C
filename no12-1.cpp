//#include<iostream>
//#include<vector>
////�����Ʋ��룻�����ⲻ�����ñ��취���ύ��ͨ������֪��Ϊɶ
////m<<=j;
////return n|m;����
//using namespace std;
//class shabi
//{
//public:
//	
//	int func(int k) {   //��2��k�η�
//		int n = 1;
//		for (int i = 0; i < k; i++) {
//			n *= 2;
//		}
//		return n;
//	}
//
//	int binInsert(int n, int m, int j, int i) {
//		vector<int> a1, a2;
//		while (n > 0) {
//			a1.push_back(n % 2);
//			n /= 2;
//		}
//		while (m > 0) {
//			a2.push_back(m % 2);
//			m /= 2;
//		}
//
//		int p = 0;
//		for (; j <= i; j++) {
//			a1[j] = a2[p];
//			p++;
//		}
//
//		int k = 0;
//		int sum = 0;
//		while (k < (int)a1.size()) {
//			if (a1[k] != 0) {
//				sum = sum + func(k);
//			}
//			k++;
//		}
//		return sum;
//	}
//};
//
//
//
//
//
//int main() {
//	//cout << func(3) << endl;
//	shabi s;
//	int b = s.binInsert(1024, 19, 2, 6);
//	cout << b << endl;
//	return 0;
//}
