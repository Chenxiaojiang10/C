//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
////�ҵĺ��������ԣ������ύ��ͨ��
//int func(int n, vector<int> a, vector<int> b) {
//	int sum1 = 0;
//	int i;
//	for (i = 0; i < n; i++) {  //����ڶ�������Ϊ0����Ӧλ������һ��ֵ������
//		if (b[i] == 0) {
//			sum1 += a[i];
//		}
//	}
//	sum1++;  
//
//
//
//	int m = n - 1;
//	int sum2 = 0;
//	int count = 0;//ͳ���м�λ�������鶼��Ϊ0
//	for (i = 0; i < n; i++) {
//		if (a[i] != 0 && b[i] != 0) {
//			count++;
//		}
//		if (a[i] == 0) {   
//			sum2 += b[i];//��������ĸ�����һΪ0�Ķ�Ӧλ������
//		}
//	}
//	sort(b.begin(), b.end());
//	for (i = 0; i < count - 1; i++) {  //�ٸ���count���ϵڶ�������ĺ󼸸��������
//		sum2 += b[m];
//		m--;
//	}
//	sum2++;
//	return sum1 + sum2;
//
//
//}
//
////��ȷ��
//int findMinimum(int n, vector<int> left, vector<int> right) {
//	int ans = 0;
//	int ls = 0, rs = 0;
//	int lmin = 27, rmin = 27;  //�߽�ֵ��26
//	for (int i = 0; i < n; i++)
//	{
//		if (left[i] * right[i] == 0)
//		{
//			ans += left[i] + right[i];    //������Ϊ��һ��Ϊ0������ֱ�Ӽ������ͺ���
//		}
//		else
//		{
//			ls += left[i];              //������߳���Ϊ����Ǽ�����ܺ�
//			rs += right[i]; 			  //�ұ��ܺ�
//			lmin = min(lmin, left[i]);    //��ߵ���Сֵ
//			rmin = min(rmin, right[i]);	 //�ұߵ���Сֵ
//		}
//	}
//	return ans + min(ls - lmin + 1, rs - rmin + 1) + 1;  //0������+��С�ó�������+�����ó���1
//}
//
//int main() {
//	int n = 4;
//	vector<int> a, b;
//	a.push_back(1);
//	a.push_back(0);
//	a.push_back(1);
//	a.push_back(1);
//
//	b.push_back(1);
//	b.push_back(1);
//	b.push_back(1);
//	b.push_back(1);
//	cout << func(n, a, b) << endl;
//	return 0;
//}
