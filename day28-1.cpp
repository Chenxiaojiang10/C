#include<iostream>
#include<vector>
using namespace std;
//让数组奇数位上都是奇数或者偶数位是偶数
//这个题非得用它的方法做，虽然我自己的也可以
void oddInOddEvenInEven(vector<int>& arr, int len) {
	//int left = 0;
	//int right = len - 1;
	//while (left <= right) {
	//	while (left < right && arr[left] % 2 != 0) {  //找前边的偶数
	//		left++;
	//	}
	//	while (left < right && arr[right] % 2 == 0) {  //找后边的奇数
	//		right--;
	//	}
	//	swap(arr[left], arr[right]);  //交换这俩，让数组前半截都是奇数，后半截都是偶数
	//	left++;
	//	right--;
	//}
	//left = 0;
	//right = len - 1;
	//if (len % 2 != 0) {
	//	right--;
	//}
	//
	//while (left < right) {
	//	swap(arr[left], arr[right]);
	//	left += 2;
	//	right -= 2;
	//}


	//for (auto& p : arr) {
	//	cout << p << ' ';
	//}

		//这是
		       
	for (int i = 0, j = 1; i < len && j < len;) {
		if (arr[len - 1] % 2 != 0) {
			swap(arr[len - 1], arr[j]);
			j += 2;
		} 
		else { 
			swap(arr[len - 1], arr[i]);
			i += 2;
		}
	}
}

int main() {
	
	int len = 0;
	cin >> len;
	vector<int> a(len);
	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}
	oddInOddEvenInEven(a, len);
	return 0;
}