#include<stdio.h>
#include<stdlib.h>
//二叉树的链式实现
//二叉树的结构体
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//队列
typedef BTNode* type;
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
	Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;
	return new;
}

//队列入队，尾插
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

//队列出队，头删
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
	return num;
}

//判断队列是否为空
int QueueEmpty(Queue* p) {
	if (p->front == NULL) {
		return 1;
	}
	return 0;
}

//队列销毁
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





//二叉树的遍历不递归的话就要借用栈来实现
//栈
typedef BTNode* type;
typedef struct Stack {
	type* array;
	size_t size;
	size_t capacity;
}Stack;

//栈初始化
void StackInit(Stack* sl, size_t n) {
	sl->array = (type*)malloc(sizeof(type) * n);
	sl->capacity = n;
	sl->size = 0;
}

//入栈
void StackPush(Stack* sl, type x) {
	if (sl->size == sl->capacity) {
		sl->capacity *= 2;
		sl->array = (type*)realloc(sl->array, sl->capacity);
		//扩容
	}
	//尾插
	sl->array[sl->size++] = x;
}

//出栈
void StackPop(Stack* sl) {
	if (sl->size) {
		sl->size--;
	}
}

//获取栈顶元素
type StackTop(Stack* sl) {
	return sl->array[sl->size - 1];
}

//栈判空
int StackEmpty(Stack* sl) {
	if (sl->size == 0) {
		return 1;
	}
	return 0;
}

//获取栈长度
size_t StackSize(Stack* sl) {
	return sl->size;
}

//栈销毁
void StackDestory(Stack* sl) {
	free(sl->array);
	sl->array = NULL;
	sl->size = 0;
	sl->capacity = 0;
}








// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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


// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	if (cur) {
		BinaryTreeDestory(&cur->left);
		BinaryTreeDestory(&cur->right);
		free(cur);
		*root = NULL;
	}
}


// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//是叶子节点就返回1
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	//把左右子树的返回来的1加起来
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}



// 二叉树节点个数
int BinaryTreeSize(BTNode* root, int* num) {
	if (root) {
		//全局变量num遍历记录个数
		++(*num);
		BinaryTreeSize(root->left, num);
		BinaryTreeSize(root->right, num);
	}
	return *num;
}


// 二叉树第k层节点个数
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


// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	BTNode* ret;
	if (root == NULL) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}
	//先查找左子树
	ret = BinaryTreeFind(root->left, x);
	if (ret) {  //左子树有x，则返回ret
		return ret;
	}
	//左没有就查找右边，不管什么值直接返回
	return BinaryTreeFind(root->right, x);
}


// 二叉树前序遍历--非递归
void BinaryTreePrevOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//前序遍历访问当前节点
			printf("%c ", cur->data);
			//把当前节点压入栈
			StackPush(&st, cur);
			//当左子树为空就出这个循环
			cur = cur->left;
		}
		//获取栈顶元素并出栈
		top = StackTop(&st);
		StackPop(&st);
		//访问右子树
		cur = top->right;
	}
	printf("\n");
}


// 二叉树中序遍历--非递归
void BinaryTreeInOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//把当前节点压入栈
			StackPush(&st, cur);
			//当左子树为空就出这个循环
			cur = cur->left;
		}

		//获取栈顶元素并出栈
		top = StackTop(&st);
		//中序遍历访问当前节点
		printf("%c ", top->data);
		StackPop(&st);
		//访问右子树
		cur = top->right;
	}
	printf("\n");
}



// 二叉树后序遍历--非递归
void BinaryTreePostOrder(BTNode* root) {
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	BTNode* prev = root;//上一次访问的位置
	while (cur || StackEmpty(&st) != 1) {
		while (cur) {
			//把当前节点压入栈
			StackPush(&st, cur);
			//当左子树为空就出这个循环
			cur = cur->left;
		}

		//获取栈顶元素并出栈
		top = StackTop(&st);
		if (top->right == NULL || top->right == prev) {
			//右子树为空或者已经访问，就打印这个节点
			printf("%c ", top->data);
			StackPop(&st);
			//更新prev
			prev = top;
		}
		else {
			//右子树还没有访问，先访问右子树
			cur = top->right;
		}

	}
	printf("\n");
}


// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	//根元素先入队
	if (root) {
		QueuePush(&q, root);
	}
	//队列不为空就继续遍历
	while (QueueEmpty(&q) != 1) {
		//获取队头元素
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//访问队头元素
		printf("%c ", front->data);
		//子节点入队，先左后右
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}
	}
}



// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root) {

		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 1) {
		//队头入队
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//如果队头不为空，孩子入队
		if (front) {
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else {
			//遇到第一个空节点，停止入队
			break;
		}
	}
	//判断队列中剩余元素是否都为空
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front) {
			//剩余节点里有一个非空就不是完全二叉树
			return -1;
		}
	}
	//剩余节点全是空，则就是完全二叉树
	return 1;
}

void preOrder(BTNode* root)
{
	if (root)
	{
		//前序遍历，保存当前节点的值
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
	printf("节点个数：%d\n", num);

	printf("前序递归遍历：\n");
	preOrder(root);
	printf("\n");
	printf("前序非递归遍历：\n");
	BinaryTreePrevOrder(root);

	printf("中序递归遍历：\n");
	InOrder(root);
	printf("\n");
	printf("中序非递归遍历\n");
	BinaryTreeInOrder(root);

	printf("后序递归遍历：\n");
	postorderTraversal(root);
	printf("\n");
	printf("后序非递归遍历\n");
	BinaryTreePostOrder(root);

	printf("层序遍历：\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("是完全二叉树吗？%d\n", BinaryTreeComplete(root));
	return 0;
}
