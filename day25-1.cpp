//#include<iostream>
//#include<vector>
//using namespace std;
////�Ǽ�����
//int main(){
//	int* fei = new int[10001];//�������Ƚϴ󣬽�����ڶ���
//	fei[0] = 1;//�ҵ�쳲��������д�1��ʼ
//	fei[1] = 1;
//	//����쳲���������
//	for (int i = 2; i < 10001; i++) {
//		fei[i] = fei[i - 1] + fei[i - 2];
//		fei[i] %= 10000;  //������λ��ֻ�����������λ������ô��Ҳ��Ϊ�˷�ֹ����int�ı�ʾ��Χ
//	}
//	int n = 0;
//	int i;
//	while (cin >> n) {
//		//��������
//		vector<int> arr(n);
//		for (i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		//ѭ����ӡָ���ĵڼ���쳲��������У�ע���ʽ
//		for (i = 0; i < n; i++) {			
//			printf("%04d", fei[arr[i]]);
//		}
//		cout << endl;
//	}
//	return 0;
//}