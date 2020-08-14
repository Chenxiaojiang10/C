#include<iostream>
#include<vector>
//动态规划，年终奖
using namespace std;


class Bonus {
public:
	int getMost(vector<vector<int>> board) {
		// write code here
		int i = 0;
		int j = 0;
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				else if (i == 0) {
					board[i][j] += board[i][j - 1];
				}
				else if (j = 0) {
					board[i][j] += board[i - 1][j];
				}
				else {
					int temup = board[i - 1][j];
					int templeft = board[i][j - 1];
					if (temup > templeft) { 
						board[i][j] += temup; 
					}
					else {
						board[i][j] += templeft;
					}
				}
			}
		}
		return board[5][5];
	}
};

int main() {
	vector<vector<int>> b(6);
	for (int i = 0; i < 6; i++) {
		b[i].resize(6);
	}

	return 0;
}