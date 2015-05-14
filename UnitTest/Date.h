#ifndef _DATE_H_
#define _DATE_H_

#include<string>
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class Date
{
public:
	Date();
	Date(int year, int month, int day);
	~Date();
	int getYear() const
	{
		return this->m_year;
	}
	int getMonth() const
	{
		return this->m_month;
	}
	int getDay() const
	{
		return this->m_day;
	}	
	void setYear(int year)
	{
		this->m_year = year;
	}
	void setMonth(int month)
	{
		this->m_month = month;
	}
	void setDay(int day)
	{
		this->m_day = day;
	}
	static bool IsLeapYear(int year)
	{
		return (year%4 == 0 && year%100!= 0 || year%400 == 0); 
	}
	bool IsLeapYear() const
	{
		return (m_year%4 == 0 && m_year%100!= 0 || m_year%400 == 0); 
	}
	void Display() const
	{  
       cout<<m_year<<"-"<<setfill('0')<<setw(2)<<m_month<<"-"<<setfill('0')<<setw(2)<<m_day<<endl;  
	}
	int DayOfMonth(int year, int month) const;
	int ToInt() const;
	Date& operator = (const Date& d);
	Date& operator + (const int day);
	Date& operator += (const int day);
	Date& operator ++();//前置++
	const Date operator ++(int);//后置++
	Date& operator - (const int day);
	Date& operator -= (const int day);
	friend bool operator > (const Date &a, const Date &b);  
    friend bool operator >=(const Date &a, const Date &b);  
    friend bool operator < (const Date &a, const Date &b);  
    friend bool operator <=(const Date &a, const Date &b);
    friend bool operator ==(const Date &a, const Date &b);  
    friend bool operator !=(const Date &a, const Date &b);
	friend int operator  - (const Date& a, const Date& b); //两个日期相减的绝对值
	friend ostream & operator <<(ostream &os,const Date &d);   
    friend istream & operator >>(istream &is,Date &d);
	
	operator int(); //类型转换运算符
private:
	int m_year;
	int m_month;
	int m_day;
};

#endif // _DATE_H_


