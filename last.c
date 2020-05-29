#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
	int size = strlen(s);
	if (size == 0) {
		return 0;
	}
	int red = 0; //前后指针，blk指向单词最后一个字母，red往前移
	int blk = size - 1;
	if (s[blk] == ' ') {  //字符串最后有空格
		while (blk >= 0 && s[blk] == ' ') {  //blk往前找第一个不是空格的位置
			--blk;
		}
		if (blk < 0) {  //情况1：blk越界了，那么字符串全为空格，返回0
			return 0;
		}
		for (red = blk; red >= 0; red--) {
			if (s[red] == ' ') {
				return blk - red;  //情况2：字符串最后有空格，并且最后一个单词前边也有空格
			}
		}
		return blk + 1;  //情况3：字符串最后有空格，但是前边没有空格
	}
	else {  //字符串最后没有空格
		for (red = size - 1; red >= 0; red--) {
			if (s[red] == ' ') {
				return blk - red;  //情况4：字符串最后没有空格，但在最后一个单词前边有空格
			}
		}
		return size;  //情况5：字符串最后没有空格，且在前边也没有空格
	}
}

int main() {
	char* s = "hjkhkj ljja ";
	int sum = lengthOfLastWord(s);
	printf("%d\n", sum);
	return 0;
}


