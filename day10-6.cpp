#include<iostream>
#include<vector>
#include<string>
//�ֽ����� ������û�뵽֮�����ı༭
using namespace std;

void func(string str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (it < str.end() - 2 && *it == *(it + 1) && *(it + 1) == *(it + 2)) { //AAA���AA
			str.erase(it);
			it = str.begin();
			
		}
		else if (it < str.end() - 3 && *it == *(it + 1) && *(it + 2) == *(it + 3)) {  //AABB���AAB
			str.erase(it + 2);
			it = str.begin();
			
		}
		else { 
			it++; 
		}
	}
	cout << str << endl;
}

//ssgllnggiaakhhlssobkkiuuyiisffwttjabzzxiimoobtt

//ssglnngiiakkhlssobkkiuuyiisffwttjabzzxiimoobttt

int main() {
	int n = 0;
	while (cin >> n) {
		vector<string> str(n);
		cin.clear(); //���������
		cin.ignore(); //��ջ�����
		for (int i = 0; i < n ; i++) {
			getline(cin, str[i]);
		}
		for (int i = 0; i < n; i++) {
			func(str[i]);
		}
	}

	return 0;
}
