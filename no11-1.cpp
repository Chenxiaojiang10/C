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
////���ղ���������������
////������������Ѿ����vector�У�������һ����ȫ������
//treeNode* creatBinTree(vector<int> arr) { 
//	queue<treeNode*> q;
//	//�����������Ϊ�գ����ؿ���
//	if (arr.empty()) {
//		return nullptr;
//	}
//	treeNode* head = new treeNode;	//ͷ�ڵ�
//	head->data = arr[0];		//���������Ԫ��
//	q.push(head);	//���
//	treeNode* bt;
//
//	int i = 1;
//	while (!q.empty()) {
//		bt = q.front();  //ȡ��ͷ�ڵ㣬׼�������������Һ���
//		q.pop();	//ͷ�ڵ���ӣ�ÿһ���µ�ѭ��������ͷ����
//		//��Ū����
//		//iֻҪ�������������Ч���ȣ���������
//		if (i < arr.size()) {
//			bt->left = new treeNode;
//			bt->left->data = arr[i];
//			q.push(bt->left);  //�������
//			i++; //�������
//		}
//		else {
//			bt->left = nullptr;
//		}
//
//		//��Ū�Һ���
//		if (i < arr.size()) {
//			bt->right = new treeNode;
//			bt->right->data = arr[i];
//			q.push(bt->right);  //�Һ������
//			i++;  //�������
//		}
//		else {
//			bt->right = nullptr;
//		}
//	}
//	return head;  //������Ϊ�վͳ�while������ͷ�ڵ�
//}
//
////�������������
//void printBinTree(treeNode* head) {
//	queue<treeNode*> q;
//	treeNode* b;
//	//��Ϊ��
//	if (head == nullptr) {
//		cout << "treeNode is empty!" <<endl;
//		return;
//	}
//	//ͷ�ڵ����
//	q.push(head);
//
//
//	while (!q.empty()) {
//		b = q.front();  //�õ���ͷ����ͷ����
//		q.pop();
//		cout << b->data << endl;  //��ӡ��ͷ������
//		//��ͷ�����Ӵ��ھ����
//		if (b->left) {
//			q.push(b->left);
//		}
//		//��ͷ���Һ��Ӵ��ھ����
//		if (b->right) {
//			q.push(b->right);
//		}
//	}
//}
//
////�����������
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
