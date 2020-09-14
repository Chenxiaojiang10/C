//#include<iostream>
//#include<vector>
//using namespace std;
////检查三子棋是否获胜
//class Board {
//public:
//	bool checkBian(vector<vector<int> > a) {
//		int aa = a[0][0] + a[0][1] + a[0][2];
//		int b = a[0][0] + a[1][0] + a[2][0];
//		int c = a[2][0] + a[2][1] + a[2][2];
//		int d = a[0][2] + a[1][2] + a[2][2];
//		if (aa == 3 || aa == -3) {
//			return true;
//		}
//		else if (b == 3 || b == -3) {
//			return true;
//		}
//		else if (b == 3 || b == -3) {
//			return true;
//		}
//		else if (d == 3 || d == -3) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	
//	bool checkMid(vector<vector<int> > board) {
//		int n = board[1][1];
//		if (board[0][0] + board[2][2] == 2 * n) {
//			return true;
//		}
//		else if (board[0][1] + board[2][1] == 2 * n) {
//			return true;
//		}
//		else if (board[1][2] + board[0][2] == 2 * n) {
//			return true;
//		}
//		else if (board[1][0] + board[1][2] == 2 * n) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//
//	bool checkWon(vector<vector<int> > board) {
//		// write code here
//		if (checkBian(board)) {
//			return true;
//		}
//		if (board[1][1] != 0) {
//			if (checkMid(board)) {
//				return true;
//			}
//		}
//		return false;
//
//	}
//};