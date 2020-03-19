#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_size 1000
typedef struct PersonInfo{     //定义一个成员结构体
	char name[1024];
	char sex[4];
	char age[10];
	char phone[1024];
	char address[1024];
}PersonInfo;

typedef struct AddressBook {     //使用数组定义若干个成员结构体
	PersonInfo persons[MAX_size];     //最大联系人数量1000
	int size;     //当前联系人数量
}AddressBook;

AddressBook address_book;     //一旦AddressesBook太大了，超出栈的存储范围，程序就崩溃了。
                              //所以创建成全局变量

void Init(AddressBook* addr) {     //初始化函数
	addr->size = 0;
	for (int i = 0; i < MAX_size; i++) {
		strcpy(addr->persons[i].name, " ");
		strcpy(addr->persons[i].address, " ");
		strcpy(addr->persons[i].sex, " ");
		strcpy(addr->persons[i].phone, " ");
		//addr->persons[i].age = 0;
	}
}

int menu(){
	
	printf("=======================\n");
	printf("1.新增联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.清空联系人\n");
	printf("6.打印联系人\n");
	printf("0.退出程序\n");
	printf("vvvvvvvvvvvvvvvvvvvvv\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}

void AddPersonInfo(AddressBook* addr) {   //增加函数
	if (addr->size > MAX_size) {
		printf("联系人已满，无法添加！\n");   //检测联系人是否已满
	}
	printf("开始添加联系人！\n");
	PersonInfo* Info = &addr->persons[addr->size];   //这样操作是为了更方便，用一个指针指向要操作的那个地方，
	//之后就可以以这个指针代替=右边那一长串了，并且可以修改原结构体的内容。
	//注意不要用PersonInfo Info  这样就是创建了局部变量，实际函数结束后就没了，原结构体内容没有发生变化。
	

	printf("请输入姓名：\n");
		scanf("%s", Info->name);
	printf("请输入性别：\n");
		scanf("%s", Info->sex);
	printf("请输入年龄：\n");
		scanf("%s", Info->age);
	printf("请输入电话：\n");
		scanf("%s", Info->phone);
	printf("请输入地址：\n");
		scanf("%s", Info->address);
	printf("添加联系人成功！\n");
	addr->size++;   //size数量增加一个
	return;
}

void DelPresonInfo(AddressBook* addr) {   //删除函数
	if (addr->size == 0) {
		printf("无法删除，联系人为空！\n");
		return;
	}
	printf("请输入你要删除的联系人的序号：");
	int i = 0;
	scanf("%d", &i);
	if (i<0 || i>addr->size) {
		printf("联系人序号输入有误！\n");
		return;
	}
	PersonInfo* last = &addr->persons[addr->size - 1];
	PersonInfo* delete = &addr->persons[i];
	*delete = *last;
	addr->size--;
	printf("删除成功！\n");
	return;
}

void FindPersonInfo(AddressBook* addr) {   //查找函数
	printf("请输入你要查找的联系人姓名：");   //按照姓名查找，重名就都打印出来
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addr->size; i++) {
		PersonInfo* Info = &addr->persons[i];
		if (strcmp(name, Info->name) == 0) {
			printf("[%d]  %s  %s  %s  %s  %s\n", i, Info->name, Info->sex, Info->age, Info->phone, Info->address);
		}
	}
	printf("查找联系人完成！\n");
	return;
}

void ModPersonInfo(AddressBook* addr) {   //修改函数
	if (addr->size == 0) {
		printf("联系人为空，无法修改!\n");
		return;
	}
	int i = 0;
	printf("请输入要修改的联系人序号：");
	scanf("%d", &i);
	if (i<0 || i>addr->size) {
		printf("联系人序号有误！\n");
		return;
	}
	
	PersonInfo* Info = &addr->persons[i];
	
	printf("请输入修改后的姓名(输入*表示不变)：");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(Info->name, name);
	}
	printf("请输入修改后性别：\n");
	scanf("%s", Info->sex);
	printf("请输入修改后年龄：\n");
	scanf("%s", Info->age);
	printf("请输入修改后电话：\n");
	scanf("%s", Info->phone);
	printf("请输入修改后地址：\n");
	scanf("%s", Info->address);
	printf("修改联系人成功！\n");
	return;
}
void ClearPersonInfo(AddressBook* addr) {   //清空函数
	printf("确定要清空吗？\n");
	printf("1表示确定，其它表示不删除\n");
	int a = 0;
	scanf("%d", &a);
	if (a == 1) {
		addr->size = 0;
		printf("删除成功！\n");
		return;
	}
	else {
		printf("删除取消！\n");
		return;
	}
	
}
void PrintPersonInfo(AddressBook* addr) {   //打印函数
	printf("打印联系人！\n");
	for (int i = 0; i < addr->size; i++) {
		PersonInfo* Info = &addr->persons[i];
		printf("[%d]  %s  %s  %s  %s  %s\n",i,Info->name,Info->sex,Info->age,Info->phone,Info->address);
	}
	printf("当前共打印 %d 条联系人信息！\n ",addr->size);
}

int main() {
	Init(&address_book);     //初始化函数
	typedef void(*Func)(AddressBook*);    //创建函数指针来实现if-else的功能
	Func func[] = {
		NULL,
		AddPersonInfo,
		DelPresonInfo,
		FindPersonInfo,
		ModPersonInfo,
		ClearPersonInfo,
		PrintPersonInfo,
	};

	while (1) {
		int choice = menu();
		if(choice < 0 || choice >= 7) {
			printf("输入有误!\n");
			continue;
		}
		if (choice == 0) {
			printf("程序结束!\n");
		}
		func[choice](&address_book);
	}
	
	return 0;
}