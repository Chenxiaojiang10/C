
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
//	int N = arr1.size();  //行
//	int M = m + 1;  //列
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
//		//多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
//		const int M = m + 1;
//		vector<int> result;
//		//初始化所有位置为0，第一行都为0，初始条件
//		result.resize(M, 0);
//	
//			//这里商品的索引位置不需要偏移，要和未优化的方法区分开
//			//这里的i-1理解为上一行，或者未更新的一维数组值
//			for (int i = 0; i != N; ++i) {
//				for (int j = M - 1; j > 0; --j) {
//					//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
//					if (A[i] > j) {
//						result[j] = result[j];
//					}
//					//如果可以装下，分两种情况，装或者不装
//					//如果不装，则即为(i-1, j)
//					//如果装，需要腾出放第i个物品大小的空间： j - A[i],装入之后的最大价值即为(i - 1, j
//					//-A[i - 1]) + 第i个商品的价值V[i]
//						//最后在装与不装中选出最大的价值
//					else {
//						int newValue = result[j - A[i]] + V[i];
//						result[j] = max(newValue, result[j]);
//					}
//				}
//			}
//		//返回装入前N个商品，物品大小为m的最大价值
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
//	//int num = 0;//num记录物品总件数
//	while (cin >> n >> m) {
//		vector<int> arr1;//记录物品价格
//		vector<int> arr2;//记录他的魅力值
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