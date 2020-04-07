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

//队列初始化
void QueueInit(Queue* p) {
	p->front = p->rear = NULL;
}

//创建新节点
struct Node* CreatNode(type x) {
	Node* new =(struct Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;
	return new;
}


//队列入队，尾插
void QueuePop(Queue* p, type x) {
	Node* node = CreatNode(x);
	if (p->front == NULL) {
		p->front = p->rear = node;
	}else{
		p->rear->next = node;
		p->rear = node;
	}
}

//队列出队，头删
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

//获取队头元素
type QueueFront(Queue* p) {
	return p->front->data;
}

//获取队尾元素
type QueueRear(Queue* p) {
	return p->rear->data;
}

//获得队列的长度
int QueueSize(Queue* p) {
	int num = 0;
	Node* cur = p->front;
	while (cur) {
		num++;
		cur = cur->next;
	}
	return cur;
}

//判断队列是否为空
int QueueEmpty(Queue* p) {
	if (p->front == NULL) {
		return 1;
	}
	return 0;
}

//队列销毁
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
	//尾插12345
	QueuePop(&p, 1);
	QueuePop(&p, 2);
	QueuePop(&p, 3);
	QueuePop(&p, 4);
	QueuePop(&p, 5);

	//获得头尾元素
	int a = QueueFront(&p);
	int b = QueueRear(&p);
	printf("front = %d , rear = %d\n", a, b);

	//打印所有的元素惹
	while (QueueEmpty(&p) != 1) {
		printf("%d ", QueueFront(&p));
		QueuePush(&p);
	}
	printf("\n");

	return 0;
}