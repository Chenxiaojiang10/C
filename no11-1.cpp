//#include <iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//typedef int type;
//typedef struct treeNode {
//	type data;
//	treeNode* left;
//	treeNode* right;
//}treeNode;
//
////按照层序遍历构造二叉树
////假设层序序列已经存进vector中，并且是一颗完全二叉树
//treeNode* creatBinTree(vector<int> arr) { 
//	queue<treeNode*> q;
//	//如果层序序列为空，返回空树
//	if (arr.empty()) {
//		return nullptr;
//	}
//	treeNode* head = new treeNode;	//头节点
//	head->data = arr[0];		//存放数组首元素
//	q.push(head);	//入队
//	treeNode* bt;
//
//	int i = 1;
//	while (!q.empty()) {
//		bt = q.front();  //取出头节点，准备给它安排左右孩子
//		q.pop();	//头节点出队，每一次新的循环，都让头出队
//		//先弄左孩子
//		//i只要不超过数组的有效长度，就有左孩子
//		if (i < arr.size()) {
//			bt->left = new treeNode;
//			bt->left->data = arr[i];
//			q.push(bt->left);  //左孩子入队
//			i++; //数组后移
//		}
//		else {
//			bt->left = nullptr;
//		}
//
//		//再弄右孩子
//		if (i < arr.size()) {
//			bt->right = new treeNode;
//			bt->right->data = arr[i];
//			q.push(bt->right);  //右孩子入队
//			i++;  //数组后移
//		}
//		else {
//			bt->right = nullptr;
//		}
//	}
//	return head;  //最后队列为空就出while，返回头节点
//}
//
////层序遍历二叉树
//void printBinTree(treeNode* head) {
//	queue<treeNode*> q;
//	treeNode* b;
//	//树为空
//	if (head == nullptr) {
//		cout << "treeNode is empty!" <<endl;
//		return;
//	}
//	//头节点入队
//	q.push(head);
//
//
//	while (!q.empty()) {
//		b = q.front();  //拿到队头，队头出队
//		q.pop();
//		cout << b->data << endl;  //打印对头的数据
//		//对头的左孩子存在就入队
//		if (b->left) {
//			q.push(b->left);
//		}
//		//对头的右孩子存在就入队
//		if (b->right) {
//			q.push(b->right);
//		}
//	}
//}
//
////最近公共祖先
//class LCA {
//public:
//	int getLCA(int a, int b) {
//		vector<int> a1;
//		vector<int> a2;
//		while (a > 0) {
//			a = a / 2;
//			a1.push_back(a);
//		}
//		while (b > 0) {
//			b /= 2;
//			a2.push_back(b);
//		}
//		reverse(a1.begin(), a1.end());
//		reverse(a2.begin(), a2.end());
//		int i = 0;
//		int max = a1.size();
//		if (a1.size() < a2.size()) {
//			max = a2.size();
//		}
//		while (i < max) {
//			if (a1[i] != a2[i]) {
//				break;
//			}
//			i++;
//		}
//		return a1[i - 1];
//	}
//};
//
//int main() {
//	/*vector<int> a;
//	for (int i = 0; i < 9; i++) {
//		a.push_back(i);
//	}
//	for (auto& p : a) {
//		cout << p;
//	}
//	cout << endl;
//	treeNode* head = creatBinTree(a);
//	printBinTree(head);*/
//	
//	LCA v;
//	v.getLCA(4,5);
//	return 0;
//}
