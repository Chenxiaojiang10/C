//#include<iostream>
//#include<vector>
//using namespace std;
////˳ʱ���ӡһ������
//class Printer {
//public:
//	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
//		// ˼·���Ƚ������һȦ�����ݣ��ٽ�������һȦ�����ݣ�Ȼ��������С����
//		//���ĸ�����ߵı߿�
//		int head = 0;//���ϱߺ��ŵı�
//		int end = n - 1;//���±ߺ��ŵı�
//		int left = 0;//��������ŵı�
//		int right = m - 1;//���ұ����ŵı�
//		vector<int> arr;
//		//ֻҪ�����±߻������ұ߽�����ѭ��
//		while (head < end && left < right) {
//			if (head != end && left != right) {
//				//������Ȧ��������
//				for (int i = left; i <= right; i++) {
//					arr.push_back(mat[head][i]);
//				}
//				//������Ȧ�ұ�����
//				for (int i = head + 1; i < end; i++) {
//					arr.push_back(mat[i][right]);
//				}
//				//������Ȧ�±ߵ�����
//				for (int i = right; i >= left; i--) {
//					arr.push_back(mat[end][i]);
//				}
//				//������Ȧ��ߵ�����
//				for (int i = end - 1; i > head; i--) {
//					arr.push_back(mat[i][left]);
//				}
//			}
//			//��Ȧ
//			head++;
//			end--;
//			left++;
//			right--;
//		}
//		//n==m��������������ʣ��һ������Ԫ��
//		if (head == end && left == right) {
//			arr.push_back(mat[n / 2][m / 2]);
//			return arr;
//		}
//		//mΪ������nΪż��������ʣ���м�һ�е�һЩ����
//		if (head == end && left != right) {
//			for (int i = left; i <= right; i++) {
//				arr.push_back(mat[n / 2][i]);
//			}
//			return arr;
//		}
//		//nΪ������mΪż������ʣ�����м�һ�е�һЩ����
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