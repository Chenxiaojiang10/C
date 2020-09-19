//#include<iostream>
//#include<cstring>
//using namespace std;
////求最大连续的比特数
//int arr[8] = { 0 };
//
//void bite(int a) {
//	int i = 0;
//	if (a >= 0) {  //整数转换成比特数组
//		while (a != 0) {
//			arr[i] = a % 2;
//			a /= 2;
//			i++;
//		}
//		/*for (auto& p : arr) {
//			cout << p;
//		}
//		cout << endl;*/
//	}
//	else {   //负数处理成比特数组
//		a = a ^ 255;   //反码
//		a++;		//补码
//		a = -1 * a;  //为了把数组里的-1变成1
//		while (a != 0) {
//			arr[i] = a % 2;
//			a /= 2;
//			i++;
//		}
//		arr[7] = 1;   //这一步保证负数最高位是1
//		/*for (auto& p : arr) {
//			cout << p ;
//		}
//		cout << endl;*/
//	}
//	
//}
//
//
//void func(int a) {
//	int i, j;
//	int* p = arr;
//	
//	int num = 0;  //存最长连续的1的序列的个数
//	while (p <= &arr[7]) {
//		if (*p == 1) {
//			int count = 0;
//			for (; *p != 0; p++) {
//				count++;  //记录这次找到的连续1的序列个数
//			}
//			if (count > num) {  //看有没有之前找到的长
//				num = count;
//			}
//		}
//		else {
//			p++;
//		}
//	}
//	cout << num << endl;
//}
//
//
//int main() {
//	int a = 0;
//	while (cin >> a) {
//		bite(a);
//		func(a);
//		memset(arr, 0x00, sizeof(int) * 8);  //数组一次用完一定要清空一下
//	}
//	return 0;
//}
