#include<iostream>
#include<stack>
#include<string>
#include<cstring>
//四则运算
using namespace std;


class Exp
{
	stack<char> ops; //运算符栈
	stack<char> ds;  //数据栈
	double v, lh, rh;  //结果、左运算符、右运算符
	char op;   //操作符

public:
	double calinput() //读取计数表达式直到结束
	{
		do
		{
			readdata();  //读取数据
			skipspace();  //跳过空白字符
		} while (readop());  //读取运算符


		calremain();
		return v;
	}

	void readdata()  //读取数据可能遇到'('
	{
		while (!(cin >> v))  //读取失败因该是‘（’
		{
			cin.clear();
			cin >> op;    //读取‘（’
			if (op != '(')
			{
				throw string("在该出现数值得地方遇到了") + op;
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

	bool readop()  //读取运算符可能遇到‘)’或者‘\n’
	{
		while ((op = cin.get()) == ')')
		{
			while (ops.top() != '(')  //栈中的‘（’
			{
				rh = ds.top(); ds.pop(); //从栈中取右操作数
				lh = ds.top(); ds.pop(); //从栈中取左操作数
				ds.push(cal(lh, ops.top(), rh)); //计算结果入栈
				ops.pop();
			}

			ops.pop();  //丢弃栈中的‘（’
		}


		if (op == '\n') return false;
		if (strchr("+-*/", op) == NULL)
		{
			throw string("无效运算符") + op;
		}



		while (!ops.empty() && ops.top() != '(' && prior(op, ops.top()))
		{
			rh = ds.top(); ds.pop(); //从栈中取右操作数
			lh = ds.top(); ds.pop(); //从栈中取左操作数
			ds.push(cal(lh, ops.top(), rh)); //计算结果入栈
			ops.pop();
		}

		ops.push(op);  //预算符入栈
		return true;
	}



	void calremain()
	{
		while (!ops.empty())
		{
			rh = ds.top(); ds.pop(); //从栈中取右操作数
			lh = ds.top(); ds.pop(); //从栈中取左操作数
			ds.push(cal(lh, ops.top(), rh)); //计算结果入栈
			ops.pop();
		}

		if (ds.size() != 1)
		{
			throw string("无效表达式");
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



	bool prior(char op1, char op2)  // op1的优先级是否高于op2
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

