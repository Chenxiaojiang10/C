#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
	int size = strlen(s);
	if (size == 0) {
		return 0;
	}
	int red = 0; //ǰ��ָ�룬blkָ�򵥴����һ����ĸ��red��ǰ��
	int blk = size - 1;
	if (s[blk] == ' ') {  //�ַ�������пո�
		while (blk >= 0 && s[blk] == ' ') {  //blk��ǰ�ҵ�һ�����ǿո��λ��
			--blk;
		}
		if (blk < 0) {  //���1��blkԽ���ˣ���ô�ַ���ȫΪ�ո񣬷���0
			return 0;
		}
		for (red = blk; red >= 0; red--) {
			if (s[red] == ' ') {
				return blk - red;  //���2���ַ�������пո񣬲������һ������ǰ��Ҳ�пո�
			}
		}
		return blk + 1;  //���3���ַ�������пո񣬵���ǰ��û�пո�
	}
	else {  //�ַ������û�пո�
		for (red = size - 1; red >= 0; red--) {
			if (s[red] == ' ') {
				return blk - red;  //���4���ַ������û�пո񣬵������һ������ǰ���пո�
			}
		}
		return size;  //���5���ַ������û�пո�����ǰ��Ҳû�пո�
	}
}

int main() {
	char* s = "hjkhkj ljja ";
	int sum = lengthOfLastWord(s);
	printf("%d\n", sum);
	return 0;
}


