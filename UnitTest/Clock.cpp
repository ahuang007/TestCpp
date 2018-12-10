#include "Clock.h"
#include<iostream>
#include<iomanip>
using namespace std;

void Clock::Display()
{
	cout<<setfill('0')<<setw(2)<<m_hour<<":"<<setfill('0')<<setw(2)<<m_minute<<":"<<setfill('0')<<setw(2)<<m_second<<endl;
}

Clock::Clock()
{
	cout<<"Clock construct default"<<endl;
}

//推荐使用初始化列表初始化数据成员
Clock::Clock(int h, int m, int s):m_hour(h),m_minute(m),m_second(s)
{
	//m_hour = h;
	//m_minute = m;
	//m_second = s;
	cout<<"Clock construct"<<endl;
}

/*
Clock::Clock(int h, int m, int s)
{
	m_hour = h;
	m_minute = m;
	m_second = s;
}
*/

Clock::Clock(const Clock &c):m_hour(c.m_hour),m_minute(c.m_minute),m_second(c.m_second)
{
	cout<<"Clock copy construct"<<endl;
}

Clock& Clock::operator=(const Clock& c)
{
	cout<<"operator ="<<endl;
	this->m_hour = c.m_hour;
	this->m_minute = c.m_minute;
	this->m_second = c.m_second;

	return *this;
}

Clock::~Clock()
{
}

void Clock::Update()
{
	m_second++;
	if(m_second == 60)
	{
		m_minute++;
		m_second = 0;
	}
	if(m_minute == 60)
	{
		m_hour++;
		m_minute = 0;
	}
	if(m_hour == 24)
	{
		m_hour = 0;
	}
}

void Clock::SetHour(int h)
{
	m_hour = h;
}

int Clock::GetHour()
{
	return m_hour;
}

void Clock::SetMinute(int m)
{
	m_minute = m;
}

int Clock::GetMinute()
{
	return m_minute;
}

void Clock::SetSecond(int s)
{
	m_second = s;
}

int Clock::GetSecond()
{
	return m_second;
}
