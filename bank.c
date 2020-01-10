#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int x = 0;
int n = 0;//几个进程
int p = 0;//请求的进程名
int b = 0;//几个资源数
int request[10][3] = { 0 };
//菜单函数
int Menu() { 
	printf("-------------------\n");
	printf("输入1初始化资源！\n");
	printf("输入2打印结果！\n");
	printf("输入3请求资源！\n");
	printf("输入4调用安全性算法！\n");
	printf("输入0退出程序！\n");
	printf("-------------------\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}

//打印安全序列函数
void PrintArr(int arr[10],int n) {
	printf("========================\n");
	printf("|安全序列为：");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("|\n");
	printf("========================\n");
	printf("\n");
}

//打印函数
void Print(int available[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	printf("进程名     MAX矩阵     Allocation矩阵     Need矩阵     Availbble矩阵\n");
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

//更新available矩阵函数
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


//安全性算法
void AnQuan(int available[3], int available111[3], int need[10][3], int allocation[10][3],int n) {
	int finish[5] = { 0 };//finish【i】=0表示没有足够的资源满足它
	int work[3] = { 0 };
	int need111[10][3] = { 0 };
	int allocation111[10][3] = { 0 };
	memcpy(work, available, sizeof(int) * 3);
	memcpy(need111, need, sizeof(int) * (n*3));//弄个工作矩阵,把need的值拷贝给need111
	memcpy(allocation111, allocation, sizeof(int) * (n*3));
	int i, j;
	int	m = 1;
	int k = 0;//协助记安全序列
	int arr[10] = { 0 };//这个数组用来记安全序列
	
	for (i = 0; i < n; i++) {
		m = 1;
		for (j = 0; j < 3; j++) {
			if (finish[i] != 0 || need111[i][j] > work[j]) {
				m = 0;   
				break;
			} 
			else {
				work[j] += allocation[i][j];//释放程序占用的资源数
			}
		}
		if (m == 1) {
			finish[i] = 1;
			arr[k] = i;
			k++;
			i = -1;//又把寻找的指针拨回第一个进程
		}
		if (k == 5) {  //当记录安全序列的数组数等于进程数的时候结束循环
			break;
		}
	}

	int count = 0;
	for (i = 0; i < n; i++) {
		count += finish[i];   //如果有一个finish等于0，那么它们的总和count肯定小于n
	}
	if (count < n) {
		HuanYuan(available, need, request, allocation, p);
		printf("***********************************\n");
		printf("错误码3：没有找到安全序列，分配失败！\n");
		printf("***********************************\n");
	}
	else if(count == n) {   //找到安全序列了，那就把刚刚工作矩阵拷贝给原本的矩阵
		memcpy(need, need111, sizeof(int) * (n * 3));
		memcpy(allocation, allocation111, sizeof(int) * (n * 3));
		/*for (i = 0; i < n; i++) {
			available[i] = work[][] = allocation[][];
		}*/
		//更新available矩阵
		GengXin(available, available111, allocation, n);
		PrintArr(arr,n);
	}
}


//输入申请的各类资源数，确定request矩阵
void QingQiu(int request[10][3],int p) {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &request[p][i]);
	}
}

//试分配函数
void FenPei(int available[3], int need[10][3], int request[10][3], int allocation[10][3], int p) {
	int i;
	for (i = 0; i < 3; i++) {
		available[i] = available[i] - request[p][i];
		allocation[p][i] = allocation[p][i] + request[p][i];
		need[p][i] = need[p][i] - request[p][i];
	}
}

//验证函数
int YanZheng(int available[3],int need[10][3],int request[10][3], int allocation[10][3],int p) {
	
	for (int i = 0; i < 3; i++) {
		if (request[p][i] > need[p][i]) {
			printf("***********************************************\n");
			printf("错误码1：请求的资源数大于其所宣布的所需最大资源数！\n");
			printf("***********************************************\n");
			return 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (request[p][i] > available[i]) {
			printf("******************************\n");
			printf("错误码2：系统无足够资源,请等待！\n");
			printf("******************************\n");
			return 0;
		}
	}
	
	//通过上边两个验证就开始试分配
	
	FenPei(available, need, request, allocation, p);
	return 1;//试分配完成后就传回去1，这样告诉后边该执行安全性算法了
 }

//请求函数
void Request(int available[3], int available111[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	
	//输入请求资源
	printf("请输入你的进程名，请求各类资源数:\n");
	
	scanf("%d", &p);
	QingQiu(request, p);

	//验证前两个要求
	int flag = YanZheng(available, need, request, allocation, p);
	//验证通过就进入试分配函数,且返回x=1

	//调用安全性算法
	if (flag == 1) {
		AnQuan(available, available111, need, allocation, n);
	}
	
}


//输入已分配矩阵函数
void Alloca(int allocation[10][3], int n) {
	int i, j;
	printf("请输入已分配allocation矩阵：\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &allocation[i][j]);
		}
		putchar('\n');
	}
}

//确定MAX矩阵函数
void Maxxx(int max[10][3], int n) {
	printf("输入它们需求的各类资源MAX数：\n");
	for (int i = 0; i < n; i++) {  //i=4
		for (int j = 0; j < 3; j++) {
			scanf("%d", &max[i][j]);
		}
		putchar('\n');
	}
}

//初始化资源函数
void Bank(int available[3], int available111[3], int need[10][3], int allocation[10][3], int max[10][3], int n) {
	//输入资源总数
	
	printf("请输入几类资源：");
	scanf("%d", &b);
	int i;
	printf("请输入各类资源总数：");
	for (i = 0; i < b;i++) {
		scanf("%d", &available[i]);
	}
	memcpy(available111, available, sizeof(int) * 3);//拷贝一份available矩阵

	//确定程序数跟他们的MAX资源数
	Maxxx(max,n);

	//输入已分配矩阵
	Alloca(allocation,n);

	//计算need矩阵的值
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < b; j++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	//更新available矩阵
	GengXin(available, available111, allocation, n);
}


int main() {
	printf("==========银行家算法==========\n");
	//菜单函数
	printf("请输入总程序数：\n");   //n=5
	
	scanf("%d", &n);
	int available[3] = { 10,10,10 };//初始三类资源的总数
	int max[10][3] = { 0 };
	int allocation[10][3] = { 0 };
	int need[10][3] = { 0 };
	int available111[3] = { 0 };//存放初始资源总数

	while (1) {
		int choice = Menu();
		if (choice == 1) {//执行初始化
			Bank(available, available111, need, allocation, max, n);
		}
		else if (choice == 3) {
			Request(available, available111, need, allocation, max, n);//请求资源
		}
		else if (choice == 2) {//打印结果
			Print(available, need, allocation, max, n);
		}
		else if (choice == 4) {//调用安全性算法
			AnQuan(available, available111, need, allocation, n);
		}
		else if (choice == 0) {//退出程序
			printf("byebye!\n");
			break;
		}
    }
	return 0;
}