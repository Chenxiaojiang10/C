#include<stdio.h>
#include<stdlib.h>

typedef int type;

typedef struct Node {
	type data;
	struct Node* next;
}Node;

typedef struct Queue {
	struct Node* front;
	struct Node* rear;
}Queue;

//���г�ʼ��
void QueueInit(Queue* p) {
	p->front = p->rear = NULL;
}

//�����½ڵ�
struct Node* CreatNode(type x) {
	Node* new =(struct Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;
	return new;
}


//������ӣ�β��
void QueuePop(Queue* p, type x) {
	Node* node = CreatNode(x);
	if (p->front == NULL) {
		p->front = p->rear = node;
	}else{
		p->rear->next = node;
		p->rear = node;
	}
}

//���г��ӣ�ͷɾ
void QueuePush(Queue* p) {
	if (p->front == NULL) {
		return;
	}
	Node* next = p->front->next;
	free(p->front);
	p->front = next;
	if (p->front == NULL) {
		p->rear = NULL;
	}
}

//��ȡ��ͷԪ��
type QueueFront(Queue* p) {
	return p->front->data;
}

//��ȡ��βԪ��
type QueueRear(Queue* p) {
	return p->rear->data;
}

//��ö��еĳ���
int QueueSize(Queue* p) {
	int num = 0;
	Node* cur = p->front;
	while (cur) {
		num++;
		cur = cur->next;
	}
	return cur;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* p) {
	if (p->front == NULL) {
		return 1;
	}
	return 0;
}

//��������
void QueueDes(Queue* p){
	Node* cur = p->front;
	while (cur) {
		cur->data = NULL;
		cur->next = NULL;
		free(cur);
		cur = cur->next;
	}
	p->front = NULL;
	p->rear = NULL;
}



int main() {
	Queue p;
	QueueInit(&p);
	//β��12345
	QueuePop(&p, 1);
	QueuePop(&p, 2);
	QueuePop(&p, 3);
	QueuePop(&p, 4);
	QueuePop(&p, 5);

	//���ͷβԪ��
	int a = QueueFront(&p);
	int b = QueueRear(&p);
	printf("front = %d , rear = %d\n", a, b);

	//��ӡ���е�Ԫ����
	while (QueueEmpty(&p) != 1) {
		printf("%d ", QueueFront(&p));
		QueuePush(&p);
	}
	printf("\n");

	return 0;
}