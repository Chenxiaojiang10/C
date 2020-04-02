#include<stdio.h>
#include<stdlib.h>
//无头单向不循环链表


typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

typedef struct Head
{
	struct SListNode* head;  //链表第一个有效元素的位置
}Head;


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}


//链表初始化
void SListInit(Head* plist) {
	plist->head = NULL;
}



// 单链表打印
void SListPrint(Head* plist) {
	SListNode* cur = plist->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}


// 单链表尾插
void SListPushBack(Head* pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	if (pplist == NULL) {
		pplist->head = node;
	}
	else {
		SListNode* cur = pplist->head;
		while (cur->next) {  //找到最后一个元素
			cur = cur->next;
		}
		cur->next = node;
	}
}


// 单链表的头插
void SListPushFront(Head* pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	//判断是否为空表
	if (pplist == NULL) {
		pplist->head = node;
	}
	else {
		node->next = pplist->head;
		pplist->head = node;
	}
}


// 单链表的尾删
void SListPopBack(Head* pplist) {
	//判断是否非空链表
	if (pplist->head) {
		SListNode* cur = NULL;  //最后一个节点的前一个节点
		SListNode* last = pplist->head;   //最后一个节点
		while (last->next) {
			cur = last;
			last = last->next;
		}
		//在判断删除掉的是不是头节点，即链表是不是只有一个元素
		if (last == pplist->head) {
			pplist->head = NULL;
		}
		else {
			cur->next = NULL;
		}
		free(last);
	}
}


// 单链表头删
void SListPopFront(Head* pplist) {
	if (pplist->head) {
		SListNode* cur = pplist->head;  //指向第一个元素
		pplist->head = cur->next;
		free(cur);
	}
}

/*
//头删的另外一种操作，传二级指针，其他增删改也可采用这种二级指针方式
void SListPopFront(SListNode** pplist) {
	if (*pplist) {
		SListNode* new = (*pplist)->next;
		free(*pplist);
		*pplist = new;
	}
}
*/


// 单链表查找
SListNode* SListFind(Head* plist, SLTDateType x) {
	SListNode* cur = plist->head;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}


// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos) {
	SListNode* next;
	if (pos == NULL){
		return;
	}
	next = pos->next;
	if (next) {
		pos->next = next->next;
		free(next);
	}
}


//释放链表所有空间
void SListDestory(Head* plist) {
	SListNode* cur = plist->head;
	while (cur) {
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

int main() {
	Head plist;
	SListInit(&plist);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(&plist);    //头插5个
	printf("\n");


	SListPushBack(&plist, 100);
	SListPushBack(&plist, 200);
	SListPushBack(&plist, 300);
	SListPrint(&plist);   //尾插3个
	printf("\n");

	SListPopBack(&plist);
	SListPrint(&plist);   //尾删1个
	printf("\n");

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(&plist);   //头删2个
	printf("\n");

	SListNode* pos = SListFind(&plist, 2);
	SListInsertAfter(pos, 666);   //在2后边插入666
	SListPrint(&plist);
	printf("\n");

	SListNode* pos1 = SListFind(&plist, 3);
	SListEraseAfter(pos1);        //删除3后边的一个元素
	SListPrint(&plist);
	printf("\n");


	return 0;
}