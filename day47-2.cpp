//#include<iostream>
//#include<algorithm>
//#include<vector>
////马戏团，最长上升子序列
//
//
//using namespace std;
//struct user
//{
//	int w;
//	int h;
//};
//bool com_w(user p1, user p2)
//{
//	//按照体重从小到大排序 
//	if (p1.w != p2.w)
//		return p1.w <= p2.w;
//	//在体重相等的条件下，身高高的在前（在上） 
//	else
//		return p1.h > p2.h;
//}
//int main(void)
//{
//	int N;
//	int h;
//	int w;
//	int index;
//	vector<user> p;
//	while (cin >> N)
//	{
//		p.clear();
//
//		for (int i = 0; i < N; i++)
//		{
//			user pt;
//			cin >> index >> w >> h;
//			pt.w = w;
//			pt.h = h;
//			p.push_back(pt);
//		}
//		sort(p.begin(), p.end(), com_w);
//		//按照身高求最大上升子序列 
//		int dp2[N + 1];
//		int max = 0;
//		dp2[0] = 1;
//		for (int i = 1; i < N; i++)
//		{
//			dp2[i] = 1;
//			for (int j = 0; j < i; j++)
//			{
//				if (p[j].h <= p[i].h && dp2[j] + 1 > dp2[i])
//					dp2[i] = dp2[j] + 1;
//			}
//		}
//		for (int i = 0; i < N; i++)
//			if (max < dp2[i])
//				max = dp2[i];
//		cout << max << endl;
//	}
//	return 0;
//}