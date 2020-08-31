#include<iostream>
#include<vector>
using namespace std;
//蘑菇阵
//要用动态规划
int yangHui(vector<int> a, int m, int n) { //
	
	int arr[40][40] = { 0 };
	int j, i = 0;
	for (i = 0; i < m + n; i++) {
		arr[i][0] = 1;
		for (int l = 0; l < a.size(); l+=2) {
			if (i == a[l] && a[l + 1] == 0) {
				arr[i][0] = 0;
				//是就置为0;
			}
		}
		for (j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			//查看这个点是不是放的蘑菇
			for (int l = 0; l < a.size(); l+=2) {  
				if (i == a[l] && j == a[l + 1]) {
					arr[i][j] = 0;
					//是就置为0;
				}
			}
		}
	}
	/*for (i = 0; i < 20; i++) {
		for (j = 0; j < i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/
	return arr[m + n - 1][n - 1];
}
int main() {
	//先构造一个完整的杨辉三角,从这个里面取分母
	int arr[40][40] = { 0 };
	int j, i = 0;
	for (i = 0; i < 40; i++) {
		arr[i][0] = 1;
		for (j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	int m, n;
	int k;
	cin >> m >> n >> k;
	vector<int> a(2 * k);
	for (int i = 0; i < 2 * k; i++) {
		cin >> a[i];
	}

	int x, y;//分子,分母
	y = arr[m + n - 1][n - 1];
	x = yangHui(a, m, n);
	
	cout << x << '/' << y << endl;
	printf("%.2f", (float)x / (float)y);

	/*for (i = 0; i < 20; i++) {
		for (j = 0; j < i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}



