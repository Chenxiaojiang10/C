//#include<iostream>
//#include<vector>
//#include <algorithm> 
////最长公共子序列（动态规划）
//using namespace std;
//int lengthOfLIS(vector<int>& nums)
//{
//	int n = nums.size();
//	if (n == 0)  return 0;
//	vector<int> dp(n, 0);
//	int res = 1;
//	for (int i = 0; i < n; i++)
//	{
//		dp[i] = 1;
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] < nums[i])
//			{
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//		}
//		res = max(res, dp[i]);
//	}
//	return res;
//}
//
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		vector<int> arr(n, 0);
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		cout << lengthOfLIS(arr) << endl;
//	}
//
//
//	return 0;
//}