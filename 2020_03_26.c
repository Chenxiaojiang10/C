#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo{     //定义一个成员结构体
	char name[1024];
	char sex[4];
	char age[10];
	char phone[1024];
	char address[1024];
}PersonInfo;

typedef struct AddressBook {     //使用数组定义若干个成员结构体
	PersonInfo* persons;     //最大联系人数量1000
	int size;     //当前联系人数量
	int capacity;   //当前数组的最大容量
}AddressBook;

AddressBook address_book;     //一旦AddressesBook太大了，超出栈的存储范围，程序就崩溃了。
                              //所以创建成全局变量

void ReallocPerson(AddressBook* addr) {
	addr->capacity += 20;   //先让容量变大
	//再重新申请更大的空间
	PersonInfo* newpersons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));
	//再把原来的联系人信息拷贝到新空间上
	memcpy(newpersons, addr->persons, sizeof(PersonInfo) * addr->capacity);
	//释放掉原来的空间
	free(addr->persons);
	//在让新的空间上位
	addr->persons = newpersons;


	////也可以直接realloc解决
	//addr->persons = (PersonInfo*)realloc(addr->persons, addr->capacity * sizeof(PersonInfo));
}

void Save(AddressBook* addr) {
	FILE* fp = fopen("d:/test1.txt", "w");
	if (fp == NULL) {
		perror("打开失败\n");
		return;
	}

	for (int i = 0; i < addr->size; i++) {
		fwrite(&addr->persons[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
	printf("保存成功！\n");
}

void Load(AddressBook* addr) {
	FILE* fp = fopen("d:/test1.txt", "r");
	if (fp == NULL) {
		perror("打开失败\n");
		return;
	}
	PersonInfo tmp = { 0 };
	while (1) {
		int n = fread(&tmp, sizeof(PersonInfo), 1, fp);
		if (n < 1) {
			break;
		}
		if (addr->size >= addr->capacity) {
			ReallocPerson(addr);
		}
		addr->persons[addr->size] = tmp;
		addr->size++;
	}
	fclose(fp);
}

void Init(AddressBook* addr) {     //初始化函数
	addr->size = 0;

	addr->capacity = 20;    //一组联系人最多20
	addr->persons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));//先申请20个联系人的空间

	for (int i = 0; i < addr->capacity; i++) {
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
	if (addr->size > addr->capacity) {   //检测联系人是否已满
		ReallocPerson(addr);   //满了就进入扩容函数
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
	Init(&address_book);//初始化函数
	Load(&address_book);
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
			Save(&address_book);
			printf("程序结束!\n");

		}
		func[choice](&address_book);
	}
	
	return 0;
}