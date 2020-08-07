#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//找数组中出现次数超过一半的那个数

class Solution {
public:
	//排个序，如果存在出现次数超过一半的数，那么最中间呢个肯定就是了
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) return 0; sort(numbers.begin(), numbers.end());
		// 排序，取数组中间那个数        
		int middle = numbers[numbers.size() / 2];
		int count = 0; // 出现次数 
		for (size_t i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == middle) ++count;
		}
		if (count >= (int)numbers.size() / 2) {
			return middle;
		}
		return 0;
	}
};
int main() {
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(9);
	arr.push_back(9);
	arr.push_back(2);
	arr.push_back(9);
	Solution v;
	int u = v.MoreThanHalfNum_Solution(arr);
	printf("%d", u);
	return 0;
}




	

