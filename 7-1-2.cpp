#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�������г��ִ�������һ����Ǹ���

class Solution {
public:
	//�Ÿ���������ڳ��ִ�������һ���������ô���м��ظ��϶�������
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) return 0; sort(numbers.begin(), numbers.end());
		// ����ȡ�����м��Ǹ���        
		int middle = numbers[numbers.size() / 2];
		int count = 0; // ���ִ��� 
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




	

