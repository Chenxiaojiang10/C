#include<iostream>

using namespace std;
//�Ա����꣬����һ�����ڵ����������׬��ɱǮ
bool notsushu(int n) {
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
		return false;
	}
	return true;
}

bool isrun(int n) {
	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) {
		return true;
	}
	return false;
}

int MandD(int a,int b,int c,int y,int z) {
	int sum = 0;
	int first;
	int second;
	int count = 0;
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y - b == 0) {//ͬһ��
		sum = z - c + 1;
		if (notsushu(y)) {
			sum *= 2;
		}
	}
	else {
		if (isrun(a)) {
			arr[2] = 29;
		}
		first = arr[b] - c + 1;
		if (notsushu(b)) {
			first *= 2;
		}

		second = z;
		if (notsushu(y)) {
			second *= 2;
		}

		for (int i = b + 1; i < y; i++) {
			if (notsushu(i)) {
				count = count + arr[i] * 2;
			}
			else {
				count = count + arr[i];
			}
		}
		sum = first + second + count;
	}
	cout << sum << endl;
	return sum;
}

void func(int a, int b, int c, int x, int y, int z) {
	int sum = 0;
	int num = 0;
	int first;
	int second;
	int fool = 0;
	int count = 0;
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int holdyear = 579;
	//ͬһ��
	if (x - a == 0) {
		cout << MandD(a,b,c,y,z) << endl;
	}
	//����������
	else if (x - a > 0) {
		if (y > b || (y == b && z >= c)) {//�ڶ���������ڱȵ�һ���
			//�ټ���һ����ģ�
			if (b == 1) { //�����һ���������һ�£���ô���Ͱ���2�£���һ�����ǲ�������
				for (int i = a; i < x; i++) {
					if (isrun(i)) {
						fool++;
					}
					num++;
				}
			}
			else {
				for (int i = a + 1; i <= x; i++) {
					if (isrun(i)) {
						fool++;
						
					}
					num++;
				}
			}
			sum = MandD(a, b, c, y, z) + (holdyear * num) + fool;
		}
		else {
			//һ�����ȥ����֮�
			if (isrun(a)) {
				arr[2] = 29;
			}
			first = arr[y] - z + 1;
			if (notsushu(y)) {
				first *= 2;
			}

			second = c;
			if (notsushu(y)) {
				second *= 2;
			}

			//���꣬��������
			if (b == 1) { //�����һ���������һ�£���ô���Ͱ���2�£���һ�����ǲ�������
				for (int i = a; i < x; i++) {
					if (isrun(i)) {
						fool++;
						
					}
					num++;
				}
			}
			else {
				for (int i = a + 1; i <= x; i++) {
					if (isrun(i)) {
						fool++;
						
					}
					num++;
				}
			}
			sum = first + second;
			sum = (holdyear * num + fool) - sum;
			
		}
		cout << sum << endl;
	}
}


int main(){
	int a, b, c;
	int x, y, z;
	
	cin >> a >> b >> c;
	cin >> x >> y >> z;
	func(a, b, c, x, y, z);
	return 0;
}