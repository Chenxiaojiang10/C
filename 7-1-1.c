#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//输出这个字符串中最长的连续数字串
void func(char* str, int size) {
	char* tmp = (char*)malloc(size + 1);
	int prev = 0;
	int end = 0;
	int i = 0;
	int m = 0;
	int n;
	while (i < size) {
		//找到了数字串的开头了
		if (str[i] <= '9' && str[i] >= '0') {
			prev = i;
			end = i;
			i++;
			//找数字串的尾吧
			while (str[i] <= '9' && str[i] >= '0') {
				end++;
				i++;
			}
			int s = end - prev;
			//如果这个数子串比之前的数子串大，就拷贝到临时字符串中
			if (m <= s) {
				for (n = 0; n <= s; n++) {
					tmp[n] = str[prev];
					prev++;
				}
				tmp[n] = '\0';
				m = n;
			}
		}
		i++;
	}
	printf("%s", tmp);
}
int main() {
	char str[255] = { 0 };
	gets(str);
	int size = strlen(str);
	func(str, size);
	return 0;
}

