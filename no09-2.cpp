//#include<iostream>
//#include<cstdio>
//#include<vector>
//using namespace std;
//
//
//
//
//
//
//
//void yanghui(int* arr[], int max) {
//	int j;
//	int i;
//	*(*(arr + 0) + 0) = 1;
//	for (i = 1; i < max; i++) {
//		*(*(arr+i)+0) = 1;
//		
//		for (j = 1; j <= i; j++) {
//			*(*(arr + i) + j) = *(*(arr + i - 1) + j) + *(*(arr + i - 1) + j - 1);
//		}
//	}
//	//´òÓ¡
//	for (i = 0; i < 10; i++) {
//		for (j = 0; j < i; j++) {
//			cout << *(*(arr + i) + j) << endl;
//		}
//		printf("\n");
//	}
//}
//
//
//
//int bigger(int n, int m) {
//	return n > m ? n : m;
//}
//
//int main() {
//	int n = 0;
//	int m = 0;
//	cin >> n >> m;
//
//	int max = bigger(n, m);
//
//	int** p = new int*[max];
//	for (int i = 0; i < max; ++i) {
//		p[i] = new int[max];
//	}
//	memset(p, 0x00, max * max * 4);
//	yanghui(p,max);
//
//
//	
//	return 0;
//}

////Ñî»ÔÈý½Ç
//#include<iostream>
//
//using namespace std;
//int Go(int m, int n) {
//	if (m < 0 || n < 0) {
//		return 0;
//	}
//	else if (n == 1 || m == 1) {
//		return 1;
//	}
//	else
//		return Go(n - 1, m) + Go(n, m - 1);
//}
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	m++;
//	n++;
//	//Go( m, n);
//	cout << Go(m, n) << endl;
//	system("pause");
//	return 0;
//}
