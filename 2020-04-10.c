#include<stdio.h>
#include<stdlib.h>


typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List {
	ListNode* header;
}List;



// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->prev = node->next = NULL;
	node->data = x;
	return node;
}


//链表初始化
void ListInit(List* lst) {
	lst->header = ListCreate(0);
	lst->header->next = lst->header;
	lst->header->prev = lst->header;
}

// 双向链表销毁
void ListDestory(List* lst) {
	ListNode* cur = lst->header->next;
	while (lst->header != cur) {
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->header);
	lst->header = NULL;
}

// 双向链表打印
void ListPrint(List* lst) {
	ListNode* cur = lst->header->next;
	while (cur != lst->header) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(List* lst, LTDataType x) {
	ListNode* node = ListCreate(x);
	ListNode* last = lst->header->prev;
	last->next = node;
	node->prev = last;

	node->next = lst->header;
	lst->header->prev = node;
}

// 双向链表尾删
void ListPopBack(List* lst) {
	ListNode* last;
	ListNode* prev;
	//不可以把头删掉
	if (lst->header == lst->header->next) {
		return;
	}
	last = lst->header->prev;
	prev = last->prev;

	prev->next = lst->header;
	lst->header->prev = prev;
	free(last);
}

// 双向链表头插
void ListPushFront(List* lst, LTDataType x) {
	ListNode* front = lst->header->next;
	ListNode* node = ListCreate(x);

	node->next = front;
	front->prev = node;
	
	node->prev = lst->header;
	lst->header->next = node;
}

// 双向链表头删
void ListPopFront(List* lst) {
	ListNode* front, *next;
	if (lst->header == lst->header->next) {
		return;
	}
	front = lst->header->next;
	next = front->next;

	free(front);
	lst->header->next = next;
	next->prev = lst->header;
}

// 双向链表查找
ListNode* ListFind(List* lst, LTDataType x) {
	ListNode* cur = lst->header->next;
	while (cur != lst->header) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* node = ListCreate(x);
	ListNode* prev = pos->prev;

	prev->next = node;
	node->prev = prev;

	node->next = pos;
	pos->prev = node;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	//header不可以删掉
	if (pos == pos->next) {
		return;
	}
	ListNode* front, * last;
	front = pos->prev;
	last = pos->next;

	free(pos);
	front->next = last;
	last->prev = front;
}



int main() {
	List lst;
	//初始化
	ListInit(&lst);
	ListPrint(&lst);

	//尾插
	ListPushBack(&lst, 1);
	ListPrint(&lst);
	ListPushBack(&lst, 2);
	ListPrint(&lst);
	ListPushBack(&lst, 3);
	ListPrint(&lst);
	ListPushBack(&lst, 4);
	ListPrint(&lst);
	ListPushBack(&lst, 5);
	ListPrint(&lst);

	//头插
	ListPushFront(&lst, 0);
	ListPrint(&lst);
	ListPushFront(&lst, 0);
	ListPrint(&lst);
	ListPushFront(&lst, 0);
	ListPrint(&lst);

	//查到3，删掉
	ListNode* pos = ListFind(&lst, 3); 
	ListErase(pos);
	ListPrint(&lst);

	//头删
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst); 
	ListPrint(&lst);
	
	//尾删
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	return 0;
}