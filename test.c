#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define row 3
#define col 3
int Menu() {
	printf("=================================\n");
	printf("欢迎来到三子棋!\n");
	printf("1.输入1开始游戏!\n");
	printf("2.输入2退出游戏！\n");
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
			printf("|   %c ", chessBoard[i][j]);//%c打印一个字符，%s打印一个字符串
		}
		printf("|\n");
	}
	printf("-------------------\n");
}

void playerMove(char chessBoard[row][col]) {
	printf("轮到玩家落子！\n");
    //对用户输入的数据进行判断
	while (1) {
		printf("请输入你要落得子（r c）：\n");
		int r = 0, c = 0;
		scanf("%d %d", &r, &c);
		if (r < 0 || r >= row || c < 0 || c >= col) {
			printf("你的输入有误！\n");	
			continue;
		}
		//判断用户输入的位置是否已经有子了！
		if (chessBoard[r][c] != ' ') {
			printf("该位置已经有子了！\n");
			continue;
		}
		chessBoard[r][c] = 'x';
		break;
	}
	
} 

//返回值表示游戏状况
//1.返回x玩家获胜
//2.返回o电脑获胜
//3.返回空格游戏还没结束
//4.返回p就是平局
char Check(char chessBoard[row][col]) {
	int i = 0, j = 0;
	//判断有没有哪一行是连成一串
	for (; i < row; i++) {
		if (chessBoard[i][0]!=' ' && chessBoard[i][i] == chessBoard[i][i+1]
			&& chessBoard[i][i+2] == chessBoard[i][i + 1]) {
			return chessBoard[i][0];
		}
	}
	//判断有没有那一列成一串
	for (i = 0; i < row; i++) {
		if (chessBoard[i][i] != ' ' && chessBoard[i][i] == chessBoard[i + 1][i] 
			&& chessBoard[i + 2][i] == chessBoard[i][i + 1]) {
			return chessBoard[0][i];
		}
	}
	//判断对角线有没有成一串
	if (chessBoard[1][1] != ' ' && chessBoard[0][0] == chessBoard[1][1] &&
		chessBoard[2][2] == chessBoard[1][1]) {
		return chessBoard[1][1];//不论左对角线还是右对角线都会有（1，1）坐标
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
//判断棋盘是否满了，满了返回1，否则返回0
int isFull(char chessBoard[row][col]) {
	//查找有没有空格
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (chessBoard[i][j] == ' ') {
				return 0;
			}
		}
	}
	//所有位置找完都没有空格就返回1
	return 1;
}
void computerMove(char chessBoard[row][col]) {
	//电脑随机落子
	printf("轮到电脑落子！\n");
	while (1) {
		int r = rand() % row;
		int c = rand() % col;
		//判断这个位置是否有子了
		if (chessBoard[r][c] != ' ') {
			continue;
		}
		chessBoard[r][c] = 'o';
		break;
	}
}
	

void Game() {
	//1.创建并初始化一个棋盘（字符类型二维数组）
	char chessBoard[row][col] = { 0 };
	Init(chessBoard);
	char winner;
	while (1) {
		//2.先打印棋盘
		Print(chessBoard);
		//3.提示玩家落子(玩家用x表示）
		playerMove(chessBoard);
		//4.检查游戏是否结束
		if (Check(chessBoard)){
			int i=0;
		}
		//5.电脑进行落子（电脑用o表示）
		computerMove(chessBoard);
		//6.检查游戏是否结束
		winner=Check(chessBoard);
		if (winner != ' ') {
			break;
		}		
		//7.回到2循环执行
	}
	if (winner == 'x') {
		printf("玩家获胜！\n");
	}
	else if (winner == 'o') {
		printf("电脑获胜！\n");
	}
	else if (winner == 'p') {
		printf("平局!\n");
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
			printf("输入有误!\n");
		}
	}
	return 0;
}