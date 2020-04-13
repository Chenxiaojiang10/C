//#include<stdio.h>
//#include<stdlib.h>
//typedef int type;
//typedef struct Stack {
//	type* array;
//	size_t size;
//	size_t capacity;
//}Stack;
//
////栈初始化
//void StackInit(Stack* sl, size_t n) {
//	sl->array = (type*)malloc(sizeof(type) * n);
//	sl->capacity = n;
//	sl->size = 0;
//}
//
////入栈
//void StackPush(Stack* sl, type x) {
//	if (sl->size == sl->capacity) {
//		sl->capacity *= 2;
//		sl->array = (type*)realloc(sl->array, sl->capacity);
//		//扩容
//	}
//	//尾插
//	sl->array[sl->size++] = x;
//}
//
////出栈
//void StackPop(Stack* sl) {
//	if (sl->size) {
//		sl->size--;
//	}
//}
//
////获取栈顶元素
//type StackTop(Stack* sl) {
//	return sl->array[sl->size - 1];
//}
//
////栈判空
//int StackEmpty(Stack* sl) {
//	if (sl->size == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////获取栈长度
//size_t StackSize(Stack* sl) {
//	return sl->size;
//}
//
////栈销毁
//void StackDestory(Stack* sl) {
//	free(sl->array);
//	sl->array = NULL;
//	sl->size = 0;
//	sl->capacity = 0;
//}
//
//
//typedef struct {
//	Stack pushST;
//	Stack popST;
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate() {
//	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&mq->pushST, 10);
//	StackInit(&mq->popST, 10);
//	return mq;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	StackPush(&obj->pushST, x);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	int ret;
//	if (StackEmpty(&obj->popST)) {
//		while (StackEmpty(&obj->pushST) != 1) {
//			int top = StackTop(&obj->pushST);
//			StackPop(&obj->pushST);
//			StackPush(&obj->popST, top);
//		}
//	}
//	ret = StackTop(&obj->popST);
//	StackPop(&obj->popST);
//	return ret;
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {
//	if (StackEmpty(&obj->popST)) {
//		while (StackEmpty(&obj->pushST) != 1) {
//			int top = StackTop(&obj->pushST);
//			StackPop(&obj->pushST);
//			StackPush(&obj->popST, top);
//		}
//	}
//	return StackTop(&obj->popST);
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
//}
//
//void myQueueFree(MyQueue* obj) {
//	StackDestory(&obj->popST);
//	StackDestory(&obj->pushST);
//	free(obj);
//}