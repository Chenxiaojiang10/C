//#include<iostream>
//#include<vector>
//using namespace std;
////顺时针打印一个矩阵
//class Printer {
//public:
//	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
//		// 思路是先接收外边一圈的数据，再接收收缩一圈的数据，然后依次缩小矩阵
//		//这四个最外边的边框
//		int head = 0;//最上边横着的边
//		int end = n - 1;//最下边横着的边
//		int left = 0;//最左边竖着的边
//		int right = m - 1;//最右边竖着的边
//		vector<int> arr;
//		//只要有上下边或者左右边交错，出循环
//		while (head < end && left < right) {
//			if (head != end && left != right) {
//				//接收外圈上行数据
//				for (int i = left; i <= right; i++) {
//					arr.push_back(mat[head][i]);
//				}
//				//接收外圈右边数据
//				for (int i = head + 1; i < end; i++) {
//					arr.push_back(mat[i][right]);
//				}
//				//接收外圈下边的数据
//				for (int i = right; i >= left; i--) {
//					arr.push_back(mat[end][i]);
//				}
//				//接收外圈左边的数据
//				for (int i = end - 1; i > head; i--) {
//					arr.push_back(mat[i][left]);
//				}
//			}
//			//缩圈
//			head++;
//			end--;
//			left++;
//			right--;
//		}
//		//n==m且是奇数，最后会剩下一个中心元素
//		if (head == end && left == right) {
//			arr.push_back(mat[n / 2][m / 2]);
//			return arr;
//		}
//		//m为奇数，n为偶数，最后会剩下中间一行的一些数据
//		if (head == end && left != right) {
//			for (int i = left; i <= right; i++) {
//				arr.push_back(mat[n / 2][i]);
//			}
//			return arr;
//		}
//		//n为奇数，m为偶数，会剩下最中间一列的一些数据
//		if (left == right && head != end) {
//			for (int i = head; i <= end; i++) {
//				arr.push_back(mat[i][m / 2]);
//			}
//			return arr;
//		}
//		return arr;
//	}
//};
//
//int main() {
//	vector<vector<int>> arr(5);
//	int p = 1;
//	for (int i = 0; i < 5; i++) {
//		arr[i].resize(5);
//		for (int j = 0; j < 5; j++) {
//			arr[i][j] = p;
//			p++;
//		}
//	}
//	Printer pr;
//	vector<int> at = pr.clockwisePrint(arr, 5, 5);
//	for (auto& e : at) {
//		cout << e << endl;
//	}
//	return 0;
//}