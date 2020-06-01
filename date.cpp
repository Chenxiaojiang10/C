#include<iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
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
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		if (year > 0 && month > 0 && month < 13 && day > 0 &&
			day <= GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "���ڲ��Ϸ�" << year << "-" << month << "-" << day << endl;
		}
	}


	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	// ����+=����
	Date& operator+=(int day) {
		if (day < 0) {
			return *this -= day;
		}
		_day += day;
		//�·ݽ�λ
		while (_day > GetMonthDay(_year, _month)) {
			_day = _day - GetMonthDay(_year, _month);
			++_month;
			//��ݽ�λ
			if (_month == 13) {
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	// ����+����
	Date operator+(int day) {
		Date dd = *this;//����д��Date d(*this)�ȼ�
		dd += day;
		return dd;
	}

	// ����-����
	Date operator-(int day) {
		Date dd = *this;//����д��Date d(*this)�ȼ�
		dd -= day;
		return dd;
	}

	// ����-=����
	Date& operator-=(int day) {
		//
		if (day < 0) {
			return *this += day;
		}
		_day -= day;
		//�·ݽ�λ
		while (_day <= 0) {
			--_month;
			_day = GetMonthDay(_year, _month) + _day;
			//��ݽ�λ
			if (_month == 0) {
				_year -= 1;
				_month = 12;
			}
		}
		return *this;
	}

	// ǰ��++
	Date& operator++() {
		//����++֮���ֵ
		return *this += 1;
	}

	// ǰ��--
	Date& operator--() {
		//����--֮���ֵ
		return *this -= 1;
	}

	// ����++
	//����д��int������ʵ��û��ʵ�Σ�����Ϊ���ñ���������ǰ�ø����ú���
	Date operator++(int) {
		//��֮ǰ��ֵ
		Date dd(*this);
		//���ǻ���Ҫִ��++
		*this += 1;
		//����֮ǰ��ֵ����Ϊ�Ǿֲ����������Բ����Դ����á�
		return dd;
	}

	// ����--
	Date operator--(int) {
		//��֮ǰ��ֵ
		Date dd(*this);
		//���ǻ���Ҫִ��--
		*this -= 1;
		//����֮ǰ��ֵ����Ϊ�Ǿֲ����������Բ����Դ����á�
		return dd;
	}

	

	// >���������
	bool operator>(const Date& d) {
		return (_year >= d._year && _month >= d._month && _day > d._day);
	}


	// ==���������
	bool operator==(const Date& d) {
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	// >=���������
	bool operator >= (const Date& d) {
		return (_year >= d._year && _month >= d._month && _day >= d._day);
	}

	// <���������
	bool operator < (const Date& d) {
		return (_year <= d._year && _month <= d._month && _day < d._day);
	}

	// <=���������
	bool operator <= (const Date& d) {
		return (_year <= d._year && _month <= d._month && _day <= d._day);
	}

	// !=���������
	bool operator != (const Date& d) {
		return !(_year == d._year && _month == d._month && _day == d._day);
	}

	// ����-���� ��������
	int operator-(const Date& d) {
		int sum = 0;
		//��������һ�������м���
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


