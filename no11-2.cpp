//#include<iostream>
//#include<cstring>
//using namespace std;
////����������ı�����
//int arr[8] = { 0 };
//
//void bite(int a) {
//	int i = 0;
//	if (a >= 0) {  //����ת���ɱ�������
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
//	else {   //��������ɱ�������
//		a = a ^ 255;   //����
//		a++;		//����
//		a = -1 * a;  //Ϊ�˰��������-1���1
//		while (a != 0) {
//			arr[i] = a % 2;
//			a /= 2;
//			i++;
//		}
//		arr[7] = 1;   //��һ����֤�������λ��1
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
//	int num = 0;  //���������1�����еĸ���
//	while (p <= &arr[7]) {
//		if (*p == 1) {
//			int count = 0;
//			for (; *p != 0; p++) {
//				count++;  //��¼����ҵ�������1�����и���
//			}
//			if (count > num) {  //����û��֮ǰ�ҵ��ĳ�
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
//		memset(arr, 0x00, sizeof(int) * 8);  //����һ������һ��Ҫ���һ��
//	}
//	return 0;
//}
