//#include<iostream>
//#include<string>
////����ǿ�ȵȼ�
//using namespace std;
//
//int pwLen(string pw) {   //���볤�ȵ÷�
//	int s = pw.size();
//	if (s <= 4) {
//		return 5;
//	}
//	else if (s <= 7) {
//		return 10;
//	}
//	else {
//		return 25;
//	}
//}
//
//int pwLetter(string pw) {  //������ĸ����÷�
//	int let = 0;
//	int lowlet = 0;
//	for (auto& s : pw) {
//		if (s >= 'a' && s <= 'z') {
//			lowlet = 1;
//		}
//		if (s >= 'A' && s <= 'Z') {
//			let = 1;
//		}
//	}
//	if (let + lowlet == 0) {  //û����ĸ
//		return 0;
//	}
//	else if (let + lowlet == 1) {   //ֻ�д�д����Сд��ĸ
//		return 10;
//	}
//	else if (let + lowlet == 2) {   //��Сд����
//		return 20;
//	}
//}
//
//int pwNum(string pw) {   //���ֵ����
//	int num = 0; 
//	for (auto& s : pw) {
//		if (s >= '0' && s <= '9') {
//			num++;
//		}
//	}
//	if (num == 0) {   //û������
//		return 0;
//	}
//	else if (num == 1) {  //ֻ��һ������
//		return 10;
//	}
//	else {   //2����������
//		return 20;
//	}
//}
//
//int pwSymbol(string pw) {   //�������
//	int n = 0;
//	for (auto& s : pw) {
//		if (s >= '!' && s <= '/') {
//			n++;
//		}
//		else if (s >= ':' && s <= '@') {
//			n++;
//		}
//		else if (s >= '[' && s <= 96) {
//			n++;
//		}
//		else if (s >= 123 && s <= 126) {
//			n++;
//		}
//	}
//	if (n == 0) {   //û���������
//		return 0;
//	}
//	else if (n == 1) {  //ֻ��һ������
//		return 10;
//	}
//	else {   //�ж������
//		return 25;
//	}
//}
//
//int reward(string pw) {
//	int a = pwLetter(pw);
//	int b = pwNum(pw);
//	int c = pwSymbol(pw);
//	int e = pwLen(pw);
//	int d = 0;
//	if (a == 20 && b > 0 && c > 0) {   //��Сд��ĸ�����ֺͷ���
//		d = 5;
//	}
//	else if (a > 0 && b > 0 && c > 0) {  //��ĸ�����ֺͷ���
//		d = 3;
//	}
//	else if (a > 0 && b > 0 ) {  //ֻ����ĸ������
//		d = 2;
//	}
//	return a + b + c + d + e;  //��󷵻���Щ��������ֵ���ܺ�
//}
//
//void safeLevel(string pw) {
//	int sum = reward(pw);   //��¼�ɼ�
//	if (sum >= 90) {
//		cout << "VERY_SECURE" << endl;
//		return;
//	}
//	else if (sum >= 80) {
//		cout << "SECURE" << endl;
//		return;
//	}
//	else if (sum >= 70) {
//		cout << "VERY_STRONG" << endl;
//		return;
//	}
//	else if (sum >= 60) {
//		cout << "STRONG" << endl;
//		return;
//	}
//	else if (sum >= 50) {
//		cout << "AVERAGE" << endl;
//		return;
//	}
//	else if (sum >= 25) {
//		cout << "WEAK" << endl;
//		return;
//	}
//	else if (sum >= 0) {
//		cout << "VERY_WEAK" << endl;
//		return;
//	}
//}
//int main() {
//	string pw;
//	while (cin >> pw) {  //����ѭ�����룬����ͨ��
//		safeLevel(pw);
//	}
//	return 0;
//}