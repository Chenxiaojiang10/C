//#include<iostream>
//
//using namespace std;
////Ѱ�ҹ������ż���������������
//bool Odd(int a) {
//	int i = 2;
//	int s = sqrt(a);
//	while (i <= s) {
//		if (a % i == 0) {
//			return false;
//			break;
//		}i++;
//	}
//	
//	return true;
//	
//}
//
//void func(int k) {
//	int a = k / 2;
//	if (a % 2 == 0) {
//		a++;
//	}
//	int b = k - a;
//	while (a < k) {
//		if (Odd(a) && Odd(b)) {
//			cout << b << endl;
//			cout << a << endl;
//			
//			break;
//		}
//		else {
//			a += 2;
//			b = k - a;
//		}
//
//	}
//	
//}
//
//int main() {
//	int a = 0;
//	while (cin >> a) {
//		func(a);
//	}
//	return 0;
//}