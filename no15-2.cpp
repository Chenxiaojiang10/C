//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
////我的函数，可以，但是提交不通过
//int func(int n, vector<int> a, vector<int> b) {
//	int sum1 = 0;
//	int i;
//	for (i = 0; i < n; i++) {  //如果第二个数组为0，对应位置数组一的值加起来
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
//	int count = 0;//统计有几位两个数组都不为0
//	for (i = 0; i < n; i++) {
//		if (a[i] != 0 && b[i] != 0) {
//			count++;
//		}
//		if (a[i] == 0) {   
//			sum2 += b[i];//把数组二的跟数组一为0的对应位加起来
//		}
//	}
//	sort(b.begin(), b.end());
//	for (i = 0; i < count - 1; i++) {  //再根绝count加上第二个数组的后几个大的数字
//		sum2 += b[m];
//		m--;
//	}
//	sum2++;
//	return sum1 + sum2;
//
//
//}
//
////正确答案
//int findMinimum(int n, vector<int> left, vector<int> right) {
//	int ans = 0;
//	int ls = 0, rs = 0;
//	int lmin = 27, rmin = 27;  //边界值是26
//	for (int i = 0; i < n; i++)
//	{
//		if (left[i] * right[i] == 0)
//		{
//			ans += left[i] + right[i];    //这里因为有一边为0，所以直接加起来就好了
//		}
//		else
//		{
//			ls += left[i];              //计算左边除了为零的那几组的总和
//			rs += right[i]; 			  //右边总和
//			lmin = min(lmin, left[i]);    //左边的最小值
//			rmin = min(rmin, right[i]);	 //右边的最小值
//		}
//	}
//	return ans + min(ls - lmin + 1, rs - rmin + 1) + 1;  //0的数量+最小拿出的数量+任意拿出的1
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
