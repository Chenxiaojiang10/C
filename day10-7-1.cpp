//��Ҫ˼·����ÿ��ȡһ�����֣����жϴ����Ƿ��������ֵ��ȥ��Сֵ�����ھ���D��
//����ÿ�ν��м������֮�󣬴��ڵ�begin������ǰ�ƶ�һλ�����Լ������Ӧ�ò��ù̶���λ�ķ�����
//���̶���λ��һ�ˣ�
//��������λ�õĿ����ԣ������Ϳ��Ա�֤�����ƶ����̲�������ظ���
//��Ϊ��һ���ж��Ѿ���������һ������λ���ˡ�

#include <iostream> 
#include <vector>
using namespace std;

long long C(long long n) {
	return (n - 1) * n / 2;
}

int main()
{
	int N, D; cin >> N >> D;
	long long count = 0;
	vector<int> res(N);
	for (int end = 0, begin = 0; end < N; end++) {
		cin >> res[end];
		while (end >= 2 && (res[end] - res[begin]) > D) {
			begin++;//��������begin��ǰ�ƶ�
		}
		count += C(end - begin);//�����ж�һ����ǰ�ƶ���forѭ���е�end++���������Բ���ÿ�ι̶���λ����ϡ�
	}
	cout << count % 99997867;
}