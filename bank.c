#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int x = 0;
int n = 0;//��������
int p = 0;//����Ľ�����
int b = 0;//������Դ��
int request[10][3] = { 0 };
//�˵�����
int Menu() { 
	printf("-------------------\n");
	printf("����1��ʼ����Դ��\n");
	printf("����2��ӡ�����\n");
	printf("����3������Դ��\n");
	printf("����4���ð�ȫ���㷨��\n");
	printf("����0�˳�����\n");
	printf("-------------------\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}

//��ӡ��ȫ���к���
void PrintArr(int arr[10],int n) {
	printf("========================\n");
	printf("|��ȫ����Ϊ��");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("|\n");
	printf("========================\n");
	printf("\n");
}

//��ӡ����
void Print(int available[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	printf("������     MAX����     Allocation����     Need����     Availbble����\n");
	printf("p[0]        %d %d %d           %d %d %d           %d %d %d        %d %d %d\n",
		max[0][0],max[0][1],max[0][2],allocation[0][0],allocation[0][1],allocation[0][2],
		need[0][0],need[0][1],need[0][2],available[0],available[1],available[2]);
	int i;
	for (i = 1; i < n; i++) {
		printf("p[%d]        %d %d %d           %d %d %d           %d %d %d \n",
			i,max[i][0], max[i][1], max[i][2], allocation[i][0], allocation[i][1], allocation[i][2],
			need[i][0], need[i][1], need[i][2]);
	}
}

//����available������
void GengXin(int available[3],int available111[3], int allocation[10][3], int n) {
	
	int sum0 = 0;
	int sum2 = 0;
	int sum1 = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		sum0 += allocation[i][0];
		sum1 += allocation[i][1];
		sum2 += allocation[i][2];
	}
	available[0] = available111[0] - sum0;
	available[1] = available111[1] - sum1;
	available[2] = available111[2] - sum2;
}

void HuanYuan(int available[3], int need[10][3], int request[10][3], int allocation[10][3], int p) {
	int i;
	for (i = 0; i < 3; i++) {
		available[i] = available[i] + request[p][i];
		allocation[p][i] = allocation[p][i] - request[p][i];
		need[p][i] = need[p][i] + request[p][i];
	}
}


//��ȫ���㷨
void AnQuan(int available[3], int available111[3], int need[10][3], int allocation[10][3],int n) {
	int finish[5] = { 0 };//finish��i��=0��ʾû���㹻����Դ������
	int work[3] = { 0 };
	int need111[10][3] = { 0 };
	int allocation111[10][3] = { 0 };
	memcpy(work, available, sizeof(int) * 3);
	memcpy(need111, need, sizeof(int) * (n*3));//Ū����������,��need��ֵ������need111
	memcpy(allocation111, allocation, sizeof(int) * (n*3));
	int i, j;
	int	m = 1;
	int k = 0;//Э���ǰ�ȫ����
	int arr[10] = { 0 };//������������ǰ�ȫ����
	
	for (i = 0; i < n; i++) {
		m = 1;
		for (j = 0; j < 3; j++) {
			if (finish[i] != 0 || need111[i][j] > work[j]) {
				m = 0;   
				break;
			} 
			else {
				work[j] += allocation[i][j];//�ͷų���ռ�õ���Դ��
			}
		}
		if (m == 1) {
			finish[i] = 1;
			arr[k] = i;
			k++;
			i = -1;//�ְ�Ѱ�ҵ�ָ�벦�ص�һ������
		}
		if (k == 5) {  //����¼��ȫ���е����������ڽ�������ʱ�����ѭ��
			break;
		}
	}

	int count = 0;
	for (i = 0; i < n; i++) {
		count += finish[i];   //�����һ��finish����0����ô���ǵ��ܺ�count�϶�С��n
	}
	if (count < n) {
		HuanYuan(available, need, request, allocation, p);
		printf("***********************************\n");
		printf("������3��û���ҵ���ȫ���У�����ʧ�ܣ�\n");
		printf("***********************************\n");
	}
	else if(count == n) {   //�ҵ���ȫ�����ˣ��ǾͰѸոչ������󿽱���ԭ���ľ���
		memcpy(need, need111, sizeof(int) * (n * 3));
		memcpy(allocation, allocation111, sizeof(int) * (n * 3));
		/*for (i = 0; i < n; i++) {
			available[i] = work[][] = allocation[][];
		}*/
		//����available����
		GengXin(available, available111, allocation, n);
		PrintArr(arr,n);
	}
}


//��������ĸ�����Դ����ȷ��request����
void QingQiu(int request[10][3],int p) {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &request[p][i]);
	}
}

//�Է��亯��
void FenPei(int available[3], int need[10][3], int request[10][3], int allocation[10][3], int p) {
	int i;
	for (i = 0; i < 3; i++) {
		available[i] = available[i] - request[p][i];
		allocation[p][i] = allocation[p][i] + request[p][i];
		need[p][i] = need[p][i] - request[p][i];
	}
}

//��֤����
int YanZheng(int available[3],int need[10][3],int request[10][3], int allocation[10][3],int p) {
	
	for (int i = 0; i < 3; i++) {
		if (request[p][i] > need[p][i]) {
			printf("***********************************************\n");
			printf("������1���������Դ�������������������������Դ����\n");
			printf("***********************************************\n");
			return 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (request[p][i] > available[i]) {
			printf("******************************\n");
			printf("������2��ϵͳ���㹻��Դ,��ȴ���\n");
			printf("******************************\n");
			return 0;
		}
	}
	
	//ͨ���ϱ�������֤�Ϳ�ʼ�Է���
	
	FenPei(available, need, request, allocation, p);
	return 1;//�Է�����ɺ�ʹ���ȥ1���������ߺ�߸�ִ�а�ȫ���㷨��
 }

//������
void Request(int available[3], int available111[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	
	//����������Դ
	printf("��������Ľ����������������Դ��:\n");
	
	scanf("%d", &p);
	QingQiu(request, p);

	//��֤ǰ����Ҫ��
	int flag = YanZheng(available, need, request, allocation, p);
	//��֤ͨ���ͽ����Է��亯��,�ҷ���x=1

	//���ð�ȫ���㷨
	if (flag == 1) {
		AnQuan(available, available111, need, allocation, n);
	}
	
}


//�����ѷ��������
void Alloca(int allocation[10][3], int n) {
	int i, j;
	printf("�������ѷ���allocation����\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &allocation[i][j]);
		}
		putchar('\n');
	}
}

//ȷ��MAX������
void Maxxx(int max[10][3], int n) {
	printf("������������ĸ�����ԴMAX����\n");
	for (int i = 0; i < n; i++) {  //i=4
		for (int j = 0; j < 3; j++) {
			scanf("%d", &max[i][j]);
		}
		putchar('\n');
	}
}

//��ʼ����Դ����
void Bank(int available[3], int available111[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	//������Դ����
	
	printf("�����뼸����Դ��");
	scanf("%d", &b);
	int i;
	printf("�����������Դ������");
	for (i = 0; i < b;i++) {
		scanf("%d", &available[i]);
	}
	memcpy(available111, available, sizeof(int) * 3);//����һ��available����

	//ȷ�������������ǵ�MAX��Դ��
	Maxxx(max,n);

	//�����ѷ������
	Alloca(allocation,n);

	//����need�����ֵ
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < b; j++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	//����available����
	GengXin(available, available111, allocation, n);
}


int main() {
	printf("==========���м��㷨==========\n");
	//�˵�����
	printf("�������ܳ�������\n");   //n=5
	
	scanf("%d", &n);
	int available[3] = { 10,10,10 };//��ʼ������Դ������
	int max[10][3] = { 0 };
	int allocation[10][3] = { 0 };
	int need[10][3] = { 0 };
	int available111[3] = { 0 };//��ų�ʼ��Դ����

	while (1) {
		int choice = Menu();
		if (choice == 1) {//ִ�г�ʼ��
			Bank(available, available111, need, allocation, max, n);
		}
		else if (choice == 3) {
			Request(available, available111, need, allocation, max, n);//������Դ
		}
		else if (choice == 2) {//��ӡ���
			Print(available, need, allocation, max, n);
		}
		else if (choice == 4) {//���ð�ȫ���㷨
			AnQuan(available, available111, need, allocation, n);
		}
		else if (choice == 0) {//�˳�����
			printf("byebye!\n");
			break;
		}
    }
	return 0;
}