#include<iostream>
#include<string>

using namespace std;


//计算sum函数
int HowMany(int i, int j, string s1, string s2) {
	int sum = 0;
	while ( i < s1.size() && j < s2.size()) {
		if (s1[i] == s2[j]) {
			sum++;
			i++;
			j++;
		}
		else {
			break;
		}
	}
	return sum;
}

//交换最大值
int Max(int sum, int count) {
	if (sum > count) {
		return sum;
	}
	return count;
}


//寻找第一个相等的下标
int Find(int i, int j, string s1, string s2) {
	for (; j < s2.size(); j++) {
		if (s1[i] == s2[j]) {
			return j; //返回s2第一个和s1的i相等的元素下标
			break;
		}
	}
	return -1;//没有相等的
}







int func(string s1, string s2) {
	int i = 0;
	int count = 0;
	if (s1.size() > s2.size()) {
		swap(s1, s2);
	}

	
	int p1 = 0, q1 = 0;
	
	while (i < s1.size()) {
		int j = -1;
		int sum = 0;
		if (j = Find(i, 0, s1, s2)) {//返回s2第一个和s1的i相等的元素下标

			sum = HowMany(i, j, s1, s2);//返回有几个连续相等的元素
			count = Max(sum, count); //看那个大，把大的存在count里面
			//i += sum;
			sum = 0;
			
		}

		if (j < s2.size()) {
			if ( (j = Find(i, j + sum, s1, s2)) != -1) {
				sum = HowMany(i, j , s1, s2);//返回有几个连续相等的元素
				count = Max(sum, count);
				//i += sum;
				sum = 0;
				
			}	
		}
		i++;
	}

	return count;

}



int main() {
	string s1, s2;
	/*while (cin >> s1 >> s2) {
		cout << func(s1, s2) <<endl;
	}*/


	cin >> s1 >> s2;
	cout <<func(s1, s2);
	return 0;
}


