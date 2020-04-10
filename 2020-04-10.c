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



// �������������ͷ���.
ListNode* ListCreate(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->prev = node->next = NULL;
	node->data = x;
	return node;
}


//�����ʼ��
void ListInit(List* lst) {
	lst->header = ListCreate(0);
	lst->header->next = lst->header;
	lst->header->prev = lst->header;
}

// ˫����������
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

// ˫�������ӡ
void ListPrint(List* lst) {
	ListNode* cur = lst->header->next;
	while (cur != lst->header) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(List* lst, LTDataType x) {
	ListNode* node = ListCreate(x);
	ListNode* last = lst->header->prev;
	last->next = node;
	node->prev = last;

	node->next = lst->header;
	lst->header->prev = node;
}

// ˫������βɾ
void ListPopBack(List* lst) {
	ListNode* last;
	ListNode* prev;
	//�����԰�ͷɾ��
	if (lst->header == lst->header->next) {
		return;
	}
	last = lst->header->prev;
	prev = last->prev;

	prev->next = lst->header;
	lst->header->prev = prev;
	free(last);
}

// ˫������ͷ��
void ListPushFront(List* lst, LTDataType x) {
	ListNode* front = lst->header->next;
	ListNode* node = ListCreate(x);

	node->next = front;
	front->prev = node;
	
	node->prev = lst->header;
	lst->header->next = node;
}

// ˫������ͷɾ
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

// ˫���������
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

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* node = ListCreate(x);
	ListNode* prev = pos->prev;

	prev->next = node;
	node->prev = prev;

	node->next = pos;
	pos->prev = node;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	//header������ɾ��
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
	//��ʼ��
	ListInit(&lst);
	ListPrint(&lst);

	//β��
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

	//ͷ��
	ListPushFront(&lst, 0);
	ListPrint(&lst);
	ListPushFront(&lst, 0);
	ListPrint(&lst);
	ListPushFront(&lst, 0);
	ListPrint(&lst);

	//�鵽3��ɾ��
	ListNode* pos = ListFind(&lst, 3); 
	ListErase(pos);
	ListPrint(&lst);

	//ͷɾ
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst); 
	ListPrint(&lst);
	
	//βɾ
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