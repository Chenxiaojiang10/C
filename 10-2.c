//#include<stdio.h>
//
//int main() {
//	int k[4] = { 0 };
//	for (int i = 0; i < 4; i++) {
//		k[i] = 1;    //假设i有嫌疑
//		if (((k[0] == 0) + (k[2] == 1) + (k[3] == 1) + (k[3] == 0)) == 3) {
//			printf("%c是凶手！\n", i + 'A');
//		}
//		k[i] = 0;   //经过if判断，排除i的嫌疑
//	}
//	return 0;
//}