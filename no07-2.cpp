//class Parenthesis {
//public:
//	//�ж��ַ����������Ƿ�ƥ��
//	bool chkParenthesis(string A, int n) {
//		// Ԫ�ظ���Ϊ���������Բ�ƥ��
//		if (n % 2 != 0) {
//			return false;
//		}
//		int count = 0; //��¼�ж��ٸ�������
//		int i = 0;
//		while (A[i] != '\0') {
//			if (A[i] == ')') {
//				if (count > 0) {  //����һ�������ţ������ż�¼����һ
//					count--;
//				}
//				else {
//					return false;  //ֻ�������ţ�û�������ŵ����
//				}
//			}
//			else if (A[i] == '(') {  //�����ż�¼����һ
//				count++;
//			}
//			else {
//				return false;   //�ַ������в������ŵ��ַ�
//			}
//			i++;
//		}
//		if (count == 0) {  //��ÿ��������Ƿ���������е�������
//			return true;
//		}
//		return false;
//	}
//};