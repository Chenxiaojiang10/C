
//3 10
//2 2 3
//1 5 10
//2 4 12
//if (A.empty() || V.empty() || m < 1) {
//			return 0;
//		}
//*/
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int max(int a, int b) {
//	return (a >= b) ? a : b;
//}
//
//int back(vector<int> arr1, vector<int> arr2, int m) {
//	vector<int> res;
//	int N = arr1.size();  //��
//	int M = m + 1;  //��
//	
//	res.resize(M, 0);
//	
//	for (int i = 0; i < N; ++i) {
//		for (int j = M - 1; j > 0; --j) {
//			if (arr1[i] > j) {
//				res[j] = res[j];
//			}
//			else {
//				int newValue = res[j - arr1[i]] + arr2[i];
//				res[j] = max(newValue, res[j]);
//			}
//		}
//	}
//	return res[m];
//}
///*
//class Solution {
//public:
//
//	int backPackII(int m, vector<int> A, vector<int> V) {
//		if (A.empty() || V.empty() || m < 1) {
//			return 0;
//		}
//		const int N = A.size();
//		//���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
//		const int M = m + 1;
//		vector<int> result;
//		//��ʼ������λ��Ϊ0����һ�ж�Ϊ0����ʼ����
//		result.resize(M, 0);
//	
//			//������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
//			//�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
//			for (int i = 0; i != N; ++i) {
//				for (int j = M - 1; j > 0; --j) {
//					//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
//					if (A[i] > j) {
//						result[j] = result[j];
//					}
//					//�������װ�£������������װ���߲�װ
//					//�����װ����Ϊ(i-1, j)
//					//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i],װ��֮�������ֵ��Ϊ(i - 1, j
//					//-A[i - 1]) + ��i����Ʒ�ļ�ֵV[i]
//						//�����װ�벻װ��ѡ�����ļ�ֵ
//					else {
//						int newValue = result[j - A[i]] + V[i];
//						result[j] = max(newValue, result[j]);
//					}
//				}
//			}
//		//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
//		return result[m];
//	}
//};*/
//
///*
//3 10
//2 2 3
//1 5 10
//2 4 12
//*/
//int main() {
//	int n, m;
//	//int num = 0;//num��¼��Ʒ�ܼ���
//	while (cin >> n >> m) {
//		vector<int> arr1;//��¼��Ʒ�۸�
//		vector<int> arr2;//��¼��������ֵ
//		int h, h3, h2;
//		for (int l = 0; l < n; l++) {
//			cin >> h >> h2 >> h3;
//			for (int i = 0; i < h; i++) {
//				arr1.push_back(h2);
//				arr2.push_back(h3);
//			}
//		}
//		cout << back(arr1, arr2, m) << endl;
//	}
//
//
//	/*for (auto e : arr2) {
//		cout << e << endl;
//	}*/
//
//
//	return 0;
//}