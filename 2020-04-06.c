#include<stdio.h>
#include<stdlib.h>

typedef int type;

typedef struct Stack {
	type* array;
	size_t size;
	size_t capacity;
}Stack;



//ջ��ʼ��
void StackInit(Stack* sl, size_t n) {
	sl->array = (type*)malloc(sizeof(type) * n);
	sl->capacity = n;
	sl->size = 0;
}

//��ջ
void StackPush(Stack* sl, type x) {
	if (sl->size == sl->capacity) {
		sl->capacity *= 2;
		sl->array = (type*)realloc(sl->array, sl->capacity);
		//����
	}
	//β��
	sl->array[sl->size++] = x;
}

//��ջ
void StcakPop(Stack* sl) {
	if (sl->size ) {
		sl->size--;
	}
}

//��ȡջ��Ԫ��
type StackTop(Stack* sl) {
		return sl->array[sl->size - 1];
}

//ջ�п�
int StackEmpty(Stack* sl) {
	if (sl->size == 0) {
		return 1;
	}
	return 0;
}

//��ȡջ����
size_t StackSize(Stack* sl) {
	return sl->size;
}

//ջ����
void StackDestory(Stack* sl) {
	free(sl->array);
	sl->array = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

int main() {
	Stack sl;
	StackInit(&sl, 10);
	StackPush(&sl, 1);
	StackPush(&sl, 2);
	StackPush(&sl, 3);
	StackPush(&sl, 4);
	StackPush(&sl, 5);

	int a = (int)StackSize(&sl);
	printf("size = %d\n", a);

	while (StackEmpty(&sl) != 1) {
		printf("%d ", StackTop(&sl));
		StcakPop(&sl);
	}
	printf("\n");

	return 0;
}