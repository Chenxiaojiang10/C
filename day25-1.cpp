//#include<iostream>
//#include<vector>
//using namespace std;
////星际密码
//int main(){
//	int* fei = new int[10001];//数据量比较大，建议放在堆上
//	fei[0] = 1;//我的斐波那契数列从1开始
//	fei[1] = 1;
//	//构建斐波那契数列
//	for (int i = 2; i < 10001; i++) {
//		fei[i] = fei[i - 1] + fei[i - 2];
//		fei[i] %= 10000;  //超过四位的只保留下最后四位数，这么做也是为了防止超过int的表示范围
//	}
//	int n = 0;
//	int i;
//	while (cin >> n) {
//		//接收数据
//		vector<int> arr(n);
//		for (i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		//循环打印指定的第几个斐波那契数列，注意格式
//		for (i = 0; i < n; i++) {			
//			printf("%04d", fei[arr[i]]);
//		}
//		cout << endl;
//	}
//	return 0;
//}