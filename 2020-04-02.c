#include<stdio.h>
#include<stdlib.h>
//��ͷ����ѭ������


typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

typedef struct Head
{
	struct SListNode* head;  //�����һ����ЧԪ�ص�λ��
}Head;


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}


//�����ʼ��
void SListInit(Head* plist) {
	plist->head = NULL;
}



// �������ӡ
void SListPrint(Head* plist) {
	SListNode* cur = plist->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}


// ������β��
void SListPushBack(Head* pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	if (pplist == NULL) {
		pplist->head = node;
	}
	else {
		SListNode* cur = pplist->head;
		while (cur->next) {  //�ҵ����һ��Ԫ��
			cur = cur->next;
		}
		cur->next = node;
	}
}


// �������ͷ��
void SListPushFront(Head* pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	//�ж��Ƿ�Ϊ�ձ�
	if (pplist == NULL) {
		pplist->head = node;
	}
	else {
		node->next = pplist->head;
		pplist->head = node;
	}
}


// �������βɾ
void SListPopBack(Head* pplist) {
	//�ж��Ƿ�ǿ�����
	if (pplist->head) {
		SListNode* cur = NULL;  //���һ���ڵ��ǰһ���ڵ�
		SListNode* last = pplist->head;   //���һ���ڵ�
		while (last->next) {
			cur = last;
			last = last->next;
		}
		//���ж�ɾ�������ǲ���ͷ�ڵ㣬�������ǲ���ֻ��һ��Ԫ��
		if (last == pplist->head) {
			pplist->head = NULL;
		}
		else {
			cur->next = NULL;
		}
		free(last);
	}
}


// ������ͷɾ
void SListPopFront(Head* pplist) {
	if (pplist->head) {
		SListNode* cur = pplist->head;  //ָ���һ��Ԫ��
		pplist->head = cur->next;
		free(cur);
	}
}

/*
//ͷɾ������һ�ֲ�����������ָ�룬������ɾ��Ҳ�ɲ������ֶ���ָ�뷽ʽ
void SListPopFront(SListNode** pplist) {
	if (*pplist) {
		SListNode* new = (*pplist)->next;
		free(*pplist);
		*pplist = new;
	}
}
*/


// ���������
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


// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}


// ������ɾ��posλ��֮���ֵ
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


//�ͷ��������пռ�
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
	SListPrint(&plist);    //ͷ��5��
	printf("\n");


	SListPushBack(&plist, 100);
	SListPushBack(&plist, 200);
	SListPushBack(&plist, 300);
	SListPrint(&plist);   //β��3��
	printf("\n");

	SListPopBack(&plist);
	SListPrint(&plist);   //βɾ1��
	printf("\n");

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(&plist);   //ͷɾ2��
	printf("\n");

	SListNode* pos = SListFind(&plist, 2);
	SListInsertAfter(pos, 666);   //��2��߲���666
	SListPrint(&plist);
	printf("\n");

	SListNode* pos1 = SListFind(&plist, 3);
	SListEraseAfter(pos1);        //ɾ��3��ߵ�һ��Ԫ��
	SListPrint(&plist);
	printf("\n");


	return 0;
}