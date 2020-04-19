//typedef struct {
//	int front;    //��һ��Ԫ��λ��    
//	int rear;    //���һ��Ԫ��λ��    
//	int k;    //����    
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
//	//β��    
//	obj->array[obj->rear++] = value;
//	//ѭ���ı�־    
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
//	//ͷɾ    
//	++obj->front;
//	//��֤ѭ��    
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
