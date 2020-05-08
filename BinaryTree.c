#include<stdio.h>
#include<stdlib.h>
//����������ʽʵ��
//�������Ľṹ��
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//����
typedef BTNode* type;
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
	Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;
	return new;
}

//������ӣ�β��
void QueuePush(Queue* p, type x) {
	Node* node = CreatNode(x);
	if (p->front == NULL) {
		p->front = p->rear = node;
	}
	else {
		p->rear->next = node;
		p->rear = node;
	}
}

//���г��ӣ�ͷɾ
void QueuePop(Queue* p) {
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
	return num;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* p) {
	if (p->front == NULL) {
		return 1;
	}
	return 0;
}

//��������
void QueueDes(Queue* p) {
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





//�������ı������ݹ�Ļ���Ҫ����ջ��ʵ��
//ջ
typedef BTNode* type;
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
void StackPop(Stack* sl) {
	if (sl->size) {
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








// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {

	if (a[*pi] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = a[*pi];
		++(*pi);
		root->left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, pi);
		return root;
	}
	else {
		return NULL;
	}
}


// ����������
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	if (cur) {
		BinaryTreeDestory(&cur->left);
		BinaryTreeDestory(&cur->right);
		free(cur);
		*root = NULL;
	}
}


// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//��Ҷ�ӽڵ�ͷ���1
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	//�����������ķ�������1������
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}



// �������ڵ����
int BinaryTreeSize(BTNode* root, int* num) {
	if (root) {
		//ȫ�ֱ���num������¼����
		++(*num);
		BinaryTreeSize(root->left, num);
		BinaryTreeSize(root->right, num);
	}
	return *num;
}


// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1)
		+ BinaryTreeLevelKSize(root->right, k - 1);
}


// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	BTNode* ret;
	if (root == NULL) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}
	//�Ȳ���������
	ret = BinaryTreeFind(root->left, x);
	if (ret) {  //��������x���򷵻�ret
		return ret;
	}
	//��û�оͲ����ұߣ�����ʲôֱֵ�ӷ���
	return BinaryTreeFind(root->right, x);
}


// ������ǰ�����--�ǵݹ�
void BinaryTreePrevOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//ǰ��������ʵ�ǰ�ڵ�
			printf("%c ", cur->data);
			//�ѵ�ǰ�ڵ�ѹ��ջ
			StackPush(&st, cur);
			//��������Ϊ�վͳ����ѭ��
			cur = cur->left;
		}
		//��ȡջ��Ԫ�ز���ջ
		top = StackTop(&st);
		StackPop(&st);
		//����������
		cur = top->right;
	}
	printf("\n");
}


// �������������--�ǵݹ�
void BinaryTreeInOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//�ѵ�ǰ�ڵ�ѹ��ջ
			StackPush(&st, cur);
			//��������Ϊ�վͳ����ѭ��
			cur = cur->left;
		}

		//��ȡջ��Ԫ�ز���ջ
		top = StackTop(&st);
		//����������ʵ�ǰ�ڵ�
		printf("%c ", top->data);
		StackPop(&st);
		//����������
		cur = top->right;
	}
	printf("\n");
}



// �������������--�ǵݹ�
void BinaryTreePostOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	BTNode* prev = root;//��һ�η��ʵ�λ��
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//�ѵ�ǰ�ڵ�ѹ��ջ
			StackPush(&st, cur);
			//��������Ϊ�վͳ����ѭ��
			cur = cur->left;
		}

		//��ȡջ��Ԫ�ز���ջ
		top = StackTop(&st);
		if (top->right == NULL || top->right == prev) {
			//������Ϊ�ջ����Ѿ����ʣ��ʹ�ӡ����ڵ�
			printf("%c ", top->data);
			StackPop(&st);
			//����prev
			prev = top;
		}
		else {
			//��������û�з��ʣ��ȷ���������
			cur = top->right;
		}

	}
	printf("\n");
}


// �������
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	//��Ԫ�������
	if (root) {
		QueuePush(&q, root);
	}
	//���в�Ϊ�վͼ�������
	while (QueueEmpty(&q) != 1) {
		//��ȡ��ͷԪ��
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//���ʶ�ͷԪ��
		printf("%c ", front->data);
		//�ӽڵ���ӣ��������
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}
	}
}



// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root) {

		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 1) {
		//��ͷ���
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//�����ͷ��Ϊ�գ��������
		if (front) {
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else {
			//������һ���սڵ㣬ֹͣ���
			break;
		}
	}
	//�ж϶�����ʣ��Ԫ���Ƿ�Ϊ��
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front) {
			//ʣ��ڵ�����һ���ǿվͲ�����ȫ������
			return -1;
		}
	}
	//ʣ��ڵ�ȫ�ǿգ��������ȫ������
	return 1;
}

void preOrder(BTNode* root)
{
	if (root)
	{
		//ǰ����������浱ǰ�ڵ��ֵ
		printf("%c ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void InOrder(BTNode* root) {
	if (root) {
		InOrder(root->left);
		printf("%c ", root->data);
		InOrder(root->right);
	}
}

void postorderTraversal(BTNode* root) {
	if (root) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%c ", root->data);
	}
}

int main() {
	char str[] = "abc##de#g##f###";
	int pi = 0;
	int num = 0;
	BTNode* root = BinaryTreeCreate(str, &pi);
	BinaryTreeSize(root, &num);
	printf("�ڵ������%d\n", num);

	printf("ǰ��ݹ������\n");
	preOrder(root);
	printf("\n");
	printf("ǰ��ǵݹ������\n");
	BinaryTreePrevOrder(root);

	printf("����ݹ������\n");
	InOrder(root);
	printf("\n");
	printf("����ǵݹ����\n");
	BinaryTreeInOrder(root);

	printf("����ݹ������\n");
	postorderTraversal(root);
	printf("\n");
	printf("����ǵݹ����\n");
	BinaryTreePostOrder(root);

	printf("���������\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("����ȫ��������%d\n", BinaryTreeComplete(root));
	return 0;
}
