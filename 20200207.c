//#include<stdio.h>
//#include<string.h>
//int isLongPressedName(char* name, char* typed) {
//	int i;
//	int j = 1;
//	int n = strlen(typed);
//	int m = strlen(name);
//	if (typed[0] != name[0]) {
//		return 0;
//	}
//	for (i = 1; i < m; i++) {
//		if (typed[j] != name[i]) {
//			if (typed[j] == name[i - 1]) {
//				i--;
//				j++;
//				continue;
//			}
//			else {
//				return 0;
//			}
//		}
//		j++;
//	}
//	return 1;
//}
//
//int main() { 
//	char name[] = "aeed";
//	char typed[] = "aaed";
//	int a = isLongPressedName(name, typed);
//	printf("%d", a);
//	return 0;
//}