#include<iostream>
#include<vector>
using namespace std;
//����������λ�϶�����������ż��λ��ż��
//�����ǵ������ķ���������Ȼ���Լ���Ҳ����
void oddInOddEvenInEven(vector<int>& arr, int len) {
	//int left = 0;
	//int right = len - 1;
	//while (left <= right) {
	//	while (left < right && arr[left] % 2 != 0) {  //��ǰ�ߵ�ż��
	//		left++;
	//	}
	//	while (left < right && arr[right] % 2 == 0) {  //�Һ�ߵ�����
	//		right--;
	//	}
	//	swap(arr[left], arr[right]);  //����������������ǰ��ض������������ض���ż��
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

		//����
		       
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