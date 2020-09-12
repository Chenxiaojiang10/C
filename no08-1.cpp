//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
////从键盘接收多个字符串，每个不超过100，并看他们是否符合两种排序顺序
//int func1(char* str[], int n) {
//	int i = 0;
//	while (i < n - 1) {
//		if (strcmp(*(str + i), *(str + i + 1)) > 0) {
//			return 0;
//		}
//		i++;
//	}
//	return 1;
//}
//
//int func2(char* str[], int n) {
//	int i = 0;
//	while (i < n - 1) {
//		if (strlen(*(str + i)) > strlen(*(str + i + 1))) {
//			return 0;
//		}
//		i++;
//	}
//	return 1;
//}
//
//void cinStr(char* str[], int n) {
//	int i = 0, j = 0;
//	char tmp[100];
//	for (i; i < n; ++i) {
//		scanf("%s", tmp);
//		str[i] = new char[10];
//		strcpy(str[i], tmp);
//	}
//}
//
//
//int main() {
//	int n = 0;
//	cin >> n;
//	char** p = new char*[n];
//	cinStr(p, n);
//	int a = func1(p, n);
//	int b = func2(p, n);
//	if (a == 1 && b == 1) {
//		cout << "both" << endl;
//	}
//	else if (b == 1) {
//		cout << "lengths" <<endl;
//	}
//	else if (a == 1) {
//		cout << "lexicographically" << endl;
//	}
//	else {
//		cout << "none" << endl;
//	}
//	return 0;
//}