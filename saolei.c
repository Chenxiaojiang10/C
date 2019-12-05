#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define row 9   //����
#define col 9   //����
#define mineNum 10    //������

int Menu() {
	printf("=========================\n");
	printf("��ӭ����ɨ�ף�\n");
	printf("1.��ʼ��Ϸ!\n");
	printf("2.�˳���Ϸ!\n");
	printf("=========================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char showMap[row][col], char mineMap[row][col]) {
	//1.��shoumap��ʼλ��ȫ��Ϊ*
	memset(showMap, '*', row * col);
	//2.�ٳ�ʼ��mineMap���Ȱ��������λ�����0��Ȼ�����10��λ�����ɡ��ס�
	memset(mineMap, '0', row * col);
	srand((unsigned int)time(NULL));
	int count = mineNum;
	while (count > 0) {
		int r = rand() % row;
		int c = rand() % col;
		if (mineMap[r][c] == '1') {
			//��������λ���Ѿ�������
			continue;
		}
		mineMap[r][c] = '1';
		count--;
	}
}

void PrintF(char showMap[row][col]) {
	int i, j;
	printf("  |");
	for (int i = 0; i < col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printf("--+------------------\n");
	for (i = 0; i < row; i++) {
		printf("%d |", i);
		for (j = 0; j < col; j++) {
			printf("%c ", showMap[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}

void Input(char showMap[row][col], int* r, int* c) {   //����Ͳ����������ڲ��Ժ����ⲿ�ı�������Ӱ��
	while (1) {
		printf("����������(�� ��)��");
		scanf("%d %d", r, c);     //�Ѿ���ָ���ˣ�����ȡ��ַ
		if (*r < 0 || *r >= row || *c < 0 || *c >= col) {
			printf("�����������������룡\n");
			continue;
		}
		if (showMap[*r][*c] != '*') {
			printf("���λ���Ѿ������ˣ�");
			continue;
		}
		break;
	}
}

int CheckMine(char mineMap[row][col], int r, int c) {
	if (mineMap[r][c] == '1') {
		return 1;
	}
	return 0;
}

int CheckBlank(int* sum) {   //ÿ����һ�θ��ӣ�sum�ͼ�1
	*sum += 1;
	if (*sum == 71) {
		return 1;
	}
	return 0;
}

void UpdateMap(char mineMap[row][col], char showMap[row][col], int r, int c) {
	//�������λ�ú󣬰����λ�õ�*��������
	int count = 0;   //������־�����Χ�˸����ӵ�����֮��
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			if (i < 0 || i >= r || c < 0 || c >= col) {
				continue;
			}
			if (mineMap[i][j] == '1') {
				count += 1;
			}
		}
	}
	showMap[r][c] = count + '0';   //����ת�ַ�
	
}

void Game() {
	//1.�Ƚ�������ͼ����ά����
	char showMap[row][col] = { 0 };
	char mineMap[row][col] = { 0 };
	int sum = 0;  //������¼�����ĸ�������
	Init(showMap, mineMap);
	while (1) {
		//2.��ӡ��ͼ
		PrintF(showMap);
		//3.��ʾ�������Ҫ����λ�õ����꣬���ж������Ƿ�Ϸ�
		int r = 0;
		int c = 0;
		Input(showMap, &r, &c);
		//4.��鷭��λ���Ƿ����ף�������Ϸ����
		if (CheckMine(mineMap, r, c)) {
			printf("��Ϸʧ�ܣ�\n");
			PrintF(mineMap);
			break;
		}
		//5.��鵱ǰλ���Ƿ������һ��λ�ã�����ʤ��
		if (CheckBlank(&sum)) {
			printf("��Ϸʤ����\n");
			break;
		}
		//6.���Ǿ���ʾһ�����֣������������Χ8���������׵ĸ�����û���׾���0
		UpdateMap(mineMap, showMap, r, c);
		
	}
	
}

int main() {
	int choice = Menu();
	if (choice == 1) {
		Game();
	}
	else if (choice == 2) {
		printf("byebye!\n");
	}
	else {
		printf("��������!\n");
	}
	return 0;
}