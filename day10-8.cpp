#include<iostream>
#include<stack>
#include<string>
#include<cstring>
//��������
using namespace std;


class Exp
{
	stack<char> ops; //�����ջ
	stack<char> ds;  //����ջ
	double v, lh, rh;  //���������������������
	char op;   //������

public:
	double calinput() //��ȡ�������ʽֱ������
	{
		do
		{
			readdata();  //��ȡ����
			skipspace();  //�����հ��ַ�
		} while (readop());  //��ȡ�����


		calremain();
		return v;
	}

	void readdata()  //��ȡ���ݿ�������'('
	{
		while (!(cin >> v))  //��ȡʧ������ǡ�����
		{
			cin.clear();
			cin >> op;    //��ȡ������
			if (op != '(')
			{
				throw string("�ڸó�����ֵ�õط�������") + op;
			}
			ops.push(op);
		}
		ds.push(v);
	}

	void skipspace()
	{
		while (cin.peek() == ' ' || cin.peek() == '\t')
		{
			cin.ignore();
		}
	}

	bool readop()  //��ȡ���������������)�����ߡ�\n��
	{
		while ((op = cin.get()) == ')')
		{
			while (ops.top() != '(')  //ջ�еġ�����
			{
				rh = ds.top(); ds.pop(); //��ջ��ȡ�Ҳ�����
				lh = ds.top(); ds.pop(); //��ջ��ȡ�������
				ds.push(cal(lh, ops.top(), rh)); //��������ջ
				ops.pop();
			}

			ops.pop();  //����ջ�еġ�����
		}


		if (op == '\n') return false;
		if (strchr("+-*/", op) == NULL)
		{
			throw string("��Ч�����") + op;
		}



		while (!ops.empty() && ops.top() != '(' && prior(op, ops.top()))
		{
			rh = ds.top(); ds.pop(); //��ջ��ȡ�Ҳ�����
			lh = ds.top(); ds.pop(); //��ջ��ȡ�������
			ds.push(cal(lh, ops.top(), rh)); //��������ջ
			ops.pop();
		}

		ops.push(op);  //Ԥ�����ջ
		return true;
	}



	void calremain()
	{
		while (!ops.empty())
		{
			rh = ds.top(); ds.pop(); //��ջ��ȡ�Ҳ�����
			lh = ds.top(); ds.pop(); //��ջ��ȡ�������
			ds.push(cal(lh, ops.top(), rh)); //��������ջ
			ops.pop();
		}

		if (ds.size() != 1)
		{
			throw string("��Ч���ʽ");
		}
		v = ds.top();
		ds.pop();
	}



	double cal(double lh, char op, double rh)
	{
		return op == '+' ? lh + rh :
			op == '-' ? lh - rh :
			op == '*' ? lh * rh : lh / rh;

	}



	bool prior(char op1, char op2)  // op1�����ȼ��Ƿ����op2
	{
		return op1 != '+' && op1 != '-' && op2 != '*' && op2 != '/';
	}

};



int main()
{
	Exp e;
	try
	{
		cout << e.calinput() << endl;
	}
	catch (const string & e)
	{
		cout << e << endl;
	}

}

