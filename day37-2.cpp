#include<iostream>
#include<string>
#include<vector>
using namespace std;
//mkdir�Ĺ���
void func(vector<string> arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i].size() > arr[j].size()) {
				//��֤�̵����ϱ�
				swap(arr[i], arr[j]);
			}
			int l;
			for (l = 0; l < arr[i].size(); l++) {  //�ж������ַ����Ƿ���С�εķ�Χ�����
				if (arr[i][l] != arr[j][l]) {
					break;
				}
			}
			if (l == arr[i].size() && (arr[j][l] == '/' || (arr[i].size() == arr[j].size()))) {  //�����һ���ַ������Ӵ����Ǿ�ɾ������ַ���
				arr[i].clear();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i].size() != 0) {
			cout << "mkdir -p " << arr[i] << endl;
		}
	}
}

int main() {
	int n = 0;
	while (cin >> n) {
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		func(arr, n);
	}
	return 0;
}