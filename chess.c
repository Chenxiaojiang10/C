#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define row 3
#define col 3
int Menu() {
	printf("=================================\n");
	printf("��ӭ����������!\n");
	printf("1.����1��ʼ��Ϸ!\n");
	printf("2.����2�˳���Ϸ��\n");
	printf("=================================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char chessBoard[row][col]) {
	memset(chessBoard, ' ', row * col*sizeof(char));
	srand((unsigned int)time(0));
}

void Print(char chessBoard[row][col]) {
	for (int i = 0; i < row; i++) {
		printf("-------------------\n");
		for (int j = 0; j < col; j++) {
			printf("|   %c ", chessBoard[i][j]);//%c��ӡһ���ַ���%s��ӡһ���ַ���
		}
		printf("|\n");
	}
	printf("-------------------\n");
}

void playerMove(char chessBoard[row][col]) {
	printf("�ֵ�������ӣ�\n");
    //���û���������ݽ����ж�
	while (1) {
		printf("��������Ҫ����ӣ�r c����\n");
		int r = 0, c = 0;
		scanf("%d %d", &r, &c);
		if (r < 0 || r >= row || c < 0 || c >= col) {
			printf("�����������\n");	
			continue;
		}
		//�ж��û������λ���Ƿ��Ѿ������ˣ�
		if (chessBoard[r][c] != ' ') {
			printf("��λ���Ѿ������ˣ�\n");
			continue;
		}
		chessBoard[r][c] = 'x';
		break;
	}
	
} 

//����ֵ��ʾ��Ϸ״��
//1.����x��һ�ʤ
//2.����o���Ի�ʤ
//3.���ؿո���Ϸ��û����
//4.����p����ƽ��
char Check(char chessBoard[row][col]) {
	int i = 0, j = 0;
	//�ж���û����һ��������һ��
	for (; i < row; i++) {
		if (chessBoard[i][0]!=' ' && chessBoard[i][i] == chessBoard[i][i+1]
			&& chessBoard[i][i+2] == chessBoard[i][i + 1]) {
			return chessBoard[i][0];
		}
	}
	//�ж���û����һ�г�һ��
	for (i = 0; i < row; i++) {
		if (chessBoard[i][i] != ' ' && chessBoard[i][i] == chessBoard[i + 1][i] 
			&& chessBoard[i + 2][i] == chessBoard[i][i + 1]) {
			return chessBoard[0][i];
		}
	}
	//�ж϶Խ�����û�г�һ��
	if (chessBoard[1][1] != ' ' && chessBoard[0][0] == chessBoard[1][1] &&
		chessBoard[2][2] == chessBoard[1][1]) {
		return chessBoard[1][1];//������Խ��߻����ҶԽ��߶����У�1��1������
	}
	if (chessBoard[1][1] != ' ' && chessBoard[0][2] == chessBoard[1][1] &&
		chessBoard[1][1] == chessBoard[2][0]) {
		return chessBoard[1][1];
	}
	if (isFull(chessBoard)) {
		return 'p';
	}
	return ' ';
}
//�ж������Ƿ����ˣ����˷���1�����򷵻�0
int isFull(char chessBoard[row][col]) {
	//������û�пո�
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (chessBoard[i][j] == ' ') {
				return 0;
			}
		}
	}
	//����λ�����궼û�пո�ͷ���1
	return 1;
}
void computerMove(char chessBoard[row][col]) {
	//�����������
	printf("�ֵ��������ӣ�\n");
	while (1) {
		int r = rand() % row;
		int c = rand() % col;
		//�ж����λ���Ƿ�������
		if (chessBoard[r][c] != ' ') {
			continue;
		}
		chessBoard[r][c] = 'o';
		break;
	}
}
	

void Game() {
	//1.��������ʼ��һ�����̣��ַ����Ͷ�ά���飩
	char chessBoard[row][col] = { 0 };
	Init(chessBoard);
	char winner;
	while (1) {
		//2.�ȴ�ӡ����
		Print(chessBoard);
		//3.��ʾ�������(�����x��ʾ��
		playerMove(chessBoard);
		//4.�����Ϸ�Ƿ����
		if (Check(chessBoard)){
			int i=0;
		}
		//5.���Խ������ӣ�������o��ʾ��
		computerMove(chessBoard);
		//6.�����Ϸ�Ƿ����
		winner=Check(chessBoard);
		if (winner != ' ') {
			break;
		}		
		//7.�ص�2ѭ��ִ��
	}
	if (winner == 'x') {
		printf("��һ�ʤ��\n");
	}
	else if (winner == 'o') {
		printf("���Ի�ʤ��\n");
	}
	else if (winner == 'p') {
		printf("ƽ��!\n");
	}
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice==2) {
			printf("byebye!\n");
		}
		else {
			printf("��������!\n");
		}
	}
	return 0;
}