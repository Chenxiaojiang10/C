#include<iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) {
		if (year > 0 && month > 0 && month < 13 && day > 0 &&
			day <= GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "日期不合法" << year << "-" << month << "-" << day << endl;
		}
	}


	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	// 日期+=天数
	Date& operator+=(int day) {
		if (day < 0) {
			return *this -= day;
		}
		_day += day;
		//月份进位
		while (_day > GetMonthDay(_year, _month)) {
			_day = _day - GetMonthDay(_year, _month);
			++_month;
			//年份进位
			if (_month == 13) {
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	// 日期+天数
	Date operator+(int day) {
		Date dd = *this;//这样写与Date d(*this)等价
		dd += day;
		return dd;
	}

	// 日期-天数
	Date operator-(int day) {
		Date dd = *this;//这样写与Date d(*this)等价
		dd -= day;
		return dd;
	}

	// 日期-=天数
	Date& operator-=(int day) {
		//
		if (day < 0) {
			return *this += day;
		}
		_day -= day;
		//月份进位
		while (_day <= 0) {
			--_month;
			_day = GetMonthDay(_year, _month) + _day;
			//年份进位
			if (_month == 0) {
				_year -= 1;
				_month = 12;
			}
		}
		return *this;
	}

	// 前置++
	Date& operator++() {
		//返回++之后得值
		return *this += 1;
	}

	// 前置--
	Date& operator--() {
		//返回--之后得值
		return *this -= 1;
	}

	// 后置++
	//参数写个int，但其实并没有实参，这是为了让编译器区分前置跟后置函数
	Date operator++(int) {
		//存之前得值
		Date dd(*this);
		//但是还是要执行++
		*this += 1;
		//返回之前的值，因为是局部变量，所以不可以穿引用。
		return dd;
	}

	// 后置--
	Date operator--(int) {
		//存之前得值
		Date dd(*this);
		//但是还是要执行--
		*this -= 1;
		//返回之前的值，因为是局部变量，所以不可以穿引用。
		return dd;
	}

	

	// >运算符重载
	bool operator>(const Date& d) {
		return (_year >= d._year && _month >= d._month && _day > d._day);
	}


	// ==运算符重载
	bool operator==(const Date& d) {
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	// >=运算符重载
	bool operator >= (const Date& d) {
		return (_year >= d._year && _month >= d._month && _day >= d._day);
	}

	// <运算符重载
	bool operator < (const Date& d) {
		return (_year <= d._year && _month <= d._month && _day < d._day);
	}

	// <=运算符重载
	bool operator <= (const Date& d) {
		return (_year <= d._year && _month <= d._month && _day <= d._day);
	}

	// !=运算符重载
	bool operator != (const Date& d) {
		return !(_year == d._year && _month == d._month && _day == d._day);
	}

	// 日期-日期 返回天数
	int operator-(const Date& d) {
		int sum = 0;
		//拷贝构造一份来进行计算
		Date d1(*this);
		Date d2(d);
		if (d1 > d2) {
			while (d1 > d2) {
				d1--;
				++sum;
			}
			return sum;
		}
		else {
			while (d1 < d2) {
				d2--;
				++sum;
			}
			return sum;
		}
	}

	void print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test1() {
	Date d(2020, 11, 11);
	d.print();
	d -= 5;
	d.print();
	d--;
	d.print();
	++d;
	d.print();
}

void test2() {
	Date d1(2020, 5, 12);
	Date d2(2020, 5, 12);
	Date d3(2020, 5, 18);
	Date d4(2020, 5, 10);
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 > d3) << endl;
	cout << (d1 > d4) << endl;
	cout << (d3 > d4) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 - d2) << endl;
	cout << (d3 - d4) << endl;
}

int main() {
	test2();
	return 0;
}


