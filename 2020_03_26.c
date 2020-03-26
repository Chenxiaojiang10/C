#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo{     //����һ����Ա�ṹ��
	char name[1024];
	char sex[4];
	char age[10];
	char phone[1024];
	char address[1024];
}PersonInfo;

typedef struct AddressBook {     //ʹ�����鶨�����ɸ���Ա�ṹ��
	PersonInfo* persons;     //�����ϵ������1000
	int size;     //��ǰ��ϵ������
	int capacity;   //��ǰ������������
}AddressBook;

AddressBook address_book;     //һ��AddressesBook̫���ˣ�����ջ�Ĵ洢��Χ������ͱ����ˡ�
                              //���Դ�����ȫ�ֱ���

void ReallocPerson(AddressBook* addr) {
	addr->capacity += 20;   //�����������
	//�������������Ŀռ�
	PersonInfo* newpersons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));
	//�ٰ�ԭ������ϵ����Ϣ�������¿ռ���
	memcpy(newpersons, addr->persons, sizeof(PersonInfo) * addr->capacity);
	//�ͷŵ�ԭ���Ŀռ�
	free(addr->persons);
	//�����µĿռ���λ
	addr->persons = newpersons;


	////Ҳ����ֱ��realloc���
	//addr->persons = (PersonInfo*)realloc(addr->persons, addr->capacity * sizeof(PersonInfo));
}

void Save(AddressBook* addr) {
	FILE* fp = fopen("d:/test1.txt", "w");
	if (fp == NULL) {
		perror("��ʧ��\n");
		return;
	}

	for (int i = 0; i < addr->size; i++) {
		fwrite(&addr->persons[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
	printf("����ɹ���\n");
}

void Load(AddressBook* addr) {
	FILE* fp = fopen("d:/test1.txt", "r");
	if (fp == NULL) {
		perror("��ʧ��\n");
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

void Init(AddressBook* addr) {     //��ʼ������
	addr->size = 0;

	addr->capacity = 20;    //һ����ϵ�����20
	addr->persons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));//������20����ϵ�˵Ŀռ�

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
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.�����ϵ��\n");
	printf("6.��ӡ��ϵ��\n");
	printf("0.�˳�����\n");
	printf("vvvvvvvvvvvvvvvvvvvvv\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}



void AddPersonInfo(AddressBook* addr) {   //���Ӻ���
	if (addr->size > addr->capacity) {   //�����ϵ���Ƿ�����
		ReallocPerson(addr);   //���˾ͽ������ݺ���
	}
	printf("��ʼ�����ϵ�ˣ�\n");
	PersonInfo* Info = &addr->persons[addr->size];   //����������Ϊ�˸����㣬��һ��ָ��ָ��Ҫ�������Ǹ��ط���
	//֮��Ϳ��������ָ�����=�ұ���һ�����ˣ����ҿ����޸�ԭ�ṹ������ݡ�
	//ע�ⲻҪ��PersonInfo Info  �������Ǵ����˾ֲ�������ʵ�ʺ����������û�ˣ�ԭ�ṹ������û�з����仯��
	

	printf("������������\n");
		scanf("%s", Info->name);
	printf("�������Ա�\n");
		scanf("%s", Info->sex);
	printf("���������䣺\n");
		scanf("%s", Info->age);
	printf("������绰��\n");
		scanf("%s", Info->phone);
	printf("�������ַ��\n");
		scanf("%s", Info->address);
	printf("�����ϵ�˳ɹ���\n");
	addr->size++;   //size��������һ��
	return;
}

void DelPresonInfo(AddressBook* addr) {   //ɾ������
	if (addr->size == 0) {
		printf("�޷�ɾ������ϵ��Ϊ�գ�\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�˵���ţ�");
	int i = 0;
	scanf("%d", &i);
	if (i<0 || i>addr->size) {
		printf("��ϵ�������������\n");
		return;
	}
	PersonInfo* last = &addr->persons[addr->size - 1];
	PersonInfo* delete = &addr->persons[i];
	*delete = *last;
	addr->size--;
	printf("ɾ���ɹ���\n");
	return;
}

void FindPersonInfo(AddressBook* addr) {   //���Һ���
	printf("��������Ҫ���ҵ���ϵ��������");   //�����������ң������Ͷ���ӡ����
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addr->size; i++) {
		PersonInfo* Info = &addr->persons[i];
		if (strcmp(name, Info->name) == 0) {
			printf("[%d]  %s  %s  %s  %s  %s\n", i, Info->name, Info->sex, Info->age, Info->phone, Info->address);
		}
	}
	printf("������ϵ����ɣ�\n");
	return;
}

void ModPersonInfo(AddressBook* addr) {   //�޸ĺ���
	if (addr->size == 0) {
		printf("��ϵ��Ϊ�գ��޷��޸�!\n");
		return;
	}
	int i = 0;
	printf("������Ҫ�޸ĵ���ϵ����ţ�");
	scanf("%d", &i);
	if (i<0 || i>addr->size) {
		printf("��ϵ���������\n");
		return;
	}
	
	PersonInfo* Info = &addr->persons[i];
	
	printf("�������޸ĺ������(����*��ʾ����)��");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(Info->name, name);
	}
	printf("�������޸ĺ��Ա�\n");
	scanf("%s", Info->sex);
	printf("�������޸ĺ����䣺\n");
	scanf("%s", Info->age);
	printf("�������޸ĺ�绰��\n");
	scanf("%s", Info->phone);
	printf("�������޸ĺ��ַ��\n");
	scanf("%s", Info->address);
	printf("�޸���ϵ�˳ɹ���\n");
	return;
}
void ClearPersonInfo(AddressBook* addr) {   //��պ���
	printf("ȷ��Ҫ�����\n");
	printf("1��ʾȷ����������ʾ��ɾ��\n");
	int a = 0;
	scanf("%d", &a);
	if (a == 1) {
		addr->size = 0;
		printf("ɾ���ɹ���\n");
		return;
	}
	else {
		printf("ɾ��ȡ����\n");
		return;
	}
	
}
void PrintPersonInfo(AddressBook* addr) {   //��ӡ����
	printf("��ӡ��ϵ�ˣ�\n");
	for (int i = 0; i < addr->size; i++) {
		PersonInfo* Info = &addr->persons[i];
		printf("[%d]  %s  %s  %s  %s  %s\n",i,Info->name,Info->sex,Info->age,Info->phone,Info->address);
	}
	printf("��ǰ����ӡ %d ����ϵ����Ϣ��\n ",addr->size);
}

int main() {
	Init(&address_book);//��ʼ������
	Load(&address_book);
	typedef void(*Func)(AddressBook*);    //��������ָ����ʵ��if-else�Ĺ���
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
			printf("��������!\n");
			continue;
		}
		if (choice == 0) {
			Save(&address_book);
			printf("�������!\n");

		}
		func[choice](&address_book);
	}
	
	return 0;
}