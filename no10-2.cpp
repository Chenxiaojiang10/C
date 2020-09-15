//#include<iostream>
//#include<string>
////密码强度等级
//using namespace std;
//
//int pwLen(string pw) {   //密码长度得分
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
//int pwLetter(string pw) {  //密码字母情况得分
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
//	if (let + lowlet == 0) {  //没有字母
//		return 0;
//	}
//	else if (let + lowlet == 1) {   //只有大写或者小写字母
//		return 10;
//	}
//	else if (let + lowlet == 2) {   //大小写都有
//		return 20;
//	}
//}
//
//int pwNum(string pw) {   //数字的情况
//	int num = 0; 
//	for (auto& s : pw) {
//		if (s >= '0' && s <= '9') {
//			num++;
//		}
//	}
//	if (num == 0) {   //没有数字
//		return 0;
//	}
//	else if (num == 1) {  //只有一个数字
//		return 10;
//	}
//	else {   //2个以上数字
//		return 20;
//	}
//}
//
//int pwSymbol(string pw) {   //特殊符号
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
//	if (n == 0) {   //没有特殊符号
//		return 0;
//	}
//	else if (n == 1) {  //只有一个符号
//		return 10;
//	}
//	else {   //有多个符号
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
//	if (a == 20 && b > 0 && c > 0) {   //大小写字母、数字和符号
//		d = 5;
//	}
//	else if (a > 0 && b > 0 && c > 0) {  //字母、数字和符号
//		d = 3;
//	}
//	else if (a > 0 && b > 0 ) {  //只有字母和数字
//		d = 2;
//	}
//	return a + b + c + d + e;  //最后返回这些函数返回值的总和
//}
//
//void safeLevel(string pw) {
//	int sum = reward(pw);   //记录成绩
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
//	while (cin >> pw) {  //做成循环输入，否则不通过
//		safeLevel(pw);
//	}
//	return 0;
//}