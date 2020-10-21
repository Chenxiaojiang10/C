//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//
//
//class Solution {
//public:
//	/**
//	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	 * 合并且倒序有序非递减链表
//	 * @param a ListNode类 待合并的第1个链表
//	 * @param b ListNode类 待合并的第2个链表
//	 * @return ListNode类
//	 */
//	ListNode* MergeAndReverseList(ListNode* a, ListNode* b) {
//		// write code here
//		vector<int> arr1;
//		vector<int> arr2;
//		while (a != NULL) {
//			arr1.push_back(a->val);
//			a = a->next;
//		}
//		while (b != NULL) {
//			arr2.push_back(b->val);
//			b = b->next;
//		}
//		reverse(arr1.begin(), arr1.end());
//		reverse(arr2.begin(), arr2.end());
//
//		ListNode* tmp = NULL;
//		
//		ListNode* tmp1 = NULL;
//		
//		int j = 0;
//		int k = 0;
//		for (int i = 0; i < arr1.size() + arr2.size(); i++) {
//			if (j < arr1.size() && k < arr2.size()) {
//				if (arr1[j] >= arr2[k]) {
//					
//					ListNode* u = new ListNode;
//					u->val = arr1[j];
//					u->next = NULL;
//					
//					if (i == 0) {
//						tmp = u;
//						tmp1 = tmp;
//					}
//					else {
//						tmp->next = u;
//						tmp = u;
//					}
//					
//					j++;
//					
//				}
//				else if (arr1[j] < arr2[k]) {
//
//					ListNode* u = new ListNode;
//					u->val = arr2[k];
//					u->next = NULL;
//					if (i == 0) {
//						tmp = u;
//						tmp1 = tmp;
//					}
//					else {
//						tmp->next = u;
//						tmp = u;
//					}
//					k++;
//				}
//			}
//
//
//			else if (j >= arr1.size()) {
//				while (k < arr2.size()) {
//					ListNode* u = new ListNode;
//					u->val = arr2[k];
//					u->next = NULL;
//					tmp->next = u;
//					tmp = u;
//					k++;
//					
//				}
//				break;
//			}
//			else if (k >= arr2.size()) {
//				while (j < arr1.size()) {
//					ListNode* u = new ListNode;
//					u->val = arr1[j];
//					u->next = NULL;
//					tmp->next = u;
//					tmp = u;
//					j++;
//					
//				}
//				break;
//			}
//
//		}
//		return tmp1;
//	}
//};
//
//int main() {
//	ListNode a, b, c, d;
//	ListNode q, w, e, r;
//	a.val = 1;
//	b.val = 3;
//	c.val = 4;
//	d.val = 7;
//
//	a.next = &b;
//	b.next = &c;
//	c.next = &d;
//	d.next = NULL;
//
//
//
//	q.val = 2;
//	w.val = 5;
//	e.val = 6;
//	r.val = 9;
//
//	q.next = &w;
//	w.next = &e;
//	e.next = &r;
//	r.next = NULL;
//
//	Solution s;
//	ListNode* op = s.MergeAndReverseList(&a, &q);
//	while (op != NULL) {
//		cout << op->val << ',';
//		op = op->next;
//	}
//	cout << endl;
//	return 0;
//}