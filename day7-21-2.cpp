#include<iostream>
#include<string>

using namespace std;


//����sum����
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

//�������ֵ
int Max(int sum, int count) {
	if (sum > count) {
		return sum;
	}
	return count;
}


//Ѱ�ҵ�һ����ȵ��±�
int Find(int i, int j, string s1, string s2) {
	for (; j < s2.size(); j++) {
		if (s1[i] == s2[j]) {
			return j; //����s2��һ����s1��i��ȵ�Ԫ���±�
			break;
		}
	}
	return -1;//û����ȵ�
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
		if (j = Find(i, 0, s1, s2)) {//����s2��һ����s1��i��ȵ�Ԫ���±�

			sum = HowMany(i, j, s1, s2);//�����м���������ȵ�Ԫ��
			count = Max(sum, count); //���Ǹ��󣬰Ѵ�Ĵ���count����
			//i += sum;
			sum = 0;
			
		}

		if (j < s2.size()) {
			if ( (j = Find(i, j + sum, s1, s2)) != -1) {
				sum = HowMany(i, j , s1, s2);//�����м���������ȵ�Ԫ��
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


