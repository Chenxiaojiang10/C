//typedef struct {
//	int front;    //第一个元素位置    
//	int rear;    //最后一个元素位置    
//	int k;    //容量    
//	int* array;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	mq->array = (int*)malloc(sizeof(int) * k + 1);
//	mq->front = 0;
//	mq->rear = 0;
//	mq->k = k;
//	return mq;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//	if ((obj->rear+1) % (obj->k + 1) == obj->front) {
//		return false;
//	}
//	//尾插    
//	obj->array[obj->rear++] = value;
//	//循环的标志    
//	if (obj->rear == obj->k + 1) {
//		obj->rear = 0;
//	}
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//	if (obj->front == obj->rear) {
//		return false;
//	}
//	//头删    
//	++obj->front;
//	//保证循环    
//	if (obj->front == obj->k + 1) {
//		obj->front = 0;
//	}
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//	if (obj->front == obj->rear) {
//		return -1;
//	}
//	return obj->array[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//	if (obj->front == obj->rear) {
//		return -1;
//	}
//	if (obj->rear == 0) {
//		return obj->array[obj->k];
//	}
//	return obj->array[obj->rear - 1];
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//	if (obj->front == obj->rear) {
//		return true;
//	}
//	return false;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//	if ((obj->rear + 1) % (obj->k + 1) == obj->front) {
//		return true;
//	}
//	return false;
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//	free(obj->array);
//	free(obj);
//}
//
