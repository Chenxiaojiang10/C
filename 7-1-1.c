#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�������ַ���������������ִ�
void func(char* str, int size) {
	char* tmp = (char*)malloc(size + 1);
	int prev = 0;
	int end = 0;
	int i = 0;
	int m = 0;
	int n;
	while (i < size) {
		//�ҵ������ִ��Ŀ�ͷ��
		if (str[i] <= '9' && str[i] >= '0') {
			prev = i;
			end = i;
			i++;
			//�����ִ���β��
			while (str[i] <= '9' && str[i] >= '0') {
				end++;
				i++;
			}
			int s = end - prev;
			//���������Ӵ���֮ǰ�����Ӵ��󣬾Ϳ�������ʱ�ַ�����
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

