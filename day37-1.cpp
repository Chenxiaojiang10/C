#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<iostream>
#include <sstream>
using namespace std;
//���ݿ����ӳ�
void func(vector<int> arr) {
	int sum = 1;//���ӳس�ʼΪ1
	int max = sum; //��¼��ֵ
	vector<int> a1;
	int i = 0;
	while (i < arr.size() / 2) {
		if (arr[i * 2 + 1] == 0) {
			if (sum == 0) {  //�����ӳ�û�������ˣ��͸����ӳ�����һ��
				sum++;
				max++;
			}
			sum--;
		}
		else {
			sum++;
		}
		i++;
	}
	cout << max << endl;


}


int main() {
	int n;
	vector<int> arr;
	string s1;
	string s2;
	while (cin >> n) {
		arr.clear();

		while (n > 0) {
			cin >> s1 >> s2;
			arr.push_back((int)s1[0]);
			if (s2[0] == 'd') {
				arr.push_back(1);   //1����Ͽ�
			}
			else {
				arr.push_back(0);  //0��������
			}
			n--;
		}
		func(arr);
	}
	return 0;
}

