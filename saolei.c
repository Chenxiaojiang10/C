#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define row 9   //行数
#define col 9   //列数
#define mineNum 10    //地雷数

int Menu() {
	printf("=========================\n");
	printf("欢迎来到扫雷！\n");
	printf("1.开始游戏!\n");
	printf("2.退出游戏!\n");
	printf("=========================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char showMap[row][col], char mineMap[row][col]) {
	//1.把shoumap初始位置全设为*
	memset(showMap, '*', row * col);
	//2.再初始化mineMap，先把里边所有位置设成0，然后随机10个位置生成‘雷’
	memset(mineMap, '0', row * col);
	srand((unsigned int)time(NULL));
	int count = mineNum;
	while (count > 0) {
		int r = rand() % row;
		int c = rand() % col;
		if (mineMap[r][c] == '1') {
			//这个随机的位置已经是雷了
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

void Input(char showMap[row][col], int* r, int* c) {   //输出型参数，函数内部对函数外部的变量产生影响
	while (1) {
		printf("请输入坐标(行 列)：");
		scanf("%d %d", r, c);     //已经是指针了，不用取地址
		if (*r < 0 || *r >= row || *c < 0 || *c >= col) {
			printf("输入有误，请重新输入！\n");
			continue;
		}
		if (showMap[*r][*c] != '*') {
			printf("这个位置已经翻开了！");
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

int CheckBlank(int* sum) {   //每翻开一次格子，sum就加1
	*sum += 1;
	if (*sum == 71) {
		return 1;
	}
	return 0;
}

void UpdateMap(char mineMap[row][col], char showMap[row][col], int r, int c) {
	//翻开这个位置后，把这个位置的*换成数字
	int count = 0;   //这个数字就是周围八个格子的雷数之和
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
	showMap[r][c] = count + '0';   //数字转字符
	
}

void Game() {
	//1.先建立俩地图，二维数组
	char showMap[row][col] = { 0 };
	char mineMap[row][col] = { 0 };
	int sum = 0;  //用来记录翻开的格子数量
	Init(showMap, mineMap);
	while (1) {
		//2.打印地图
		PrintF(showMap);
		//3.提示玩家输入要翻开位置的坐标，并判断坐标是否合法
		int r = 0;
		int c = 0;
		Input(showMap, &r, &c);
		//4.检查翻开位置是否是雷，是则游戏结束
		if (CheckMine(mineMap, r, c)) {
			printf("游戏失败！\n");
			PrintF(mineMap);
			break;
		}
		//5.检查当前位置是否是最后一个位置，是则胜利
		if (CheckBlank(&sum)) {
			printf("游戏胜利！\n");
			break;
		}
		//6.不是就显示一个数字，这个数字是周围8个格子里雷的个数，没有雷就是0
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
		printf("输入有误!\n");
	}
	return 0;
}