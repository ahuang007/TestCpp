#include "Date.h"

Date::Date():m_year(1900), m_month(1), m_day(1)
{
}

Date::Date(int year=1900, int month=1, int day=1):m_year(year), m_month(month), m_day(day)
{
	if(	(year<=0)||
		(month<=0 || month>12)||
		(day<=0 || day>DayOfMonth(year,month)))  
	{  
           m_year = 1900;  
           m_month = 1;
		   m_day = 1;
	}
}

Date::~Date(void)
{
}

int Date::DayOfMonth(int year, int month) const
{
	int day = 0;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break;
		case 2:
			day = 28 + this->IsLeapYear();
			break;
	}

	return day;
}

int Date::ToInt() const
{
	int sum = 0;
	for(int y=1;y<m_year;y++)
	{
		sum += 365 + this->IsLeapYear();
	}

	for(int m=1;m<m_month;m++)
	{
		sum += this->DayOfMonth(m_year, m);
	}

	sum += m_day;

	return sum;
}

bool operator > ( Date &a, Date &b)
{
    return a.ToInt()>b.ToInt();
}

bool operator >=( Date &a, Date &b)
{
    return a.ToInt()>=b.ToInt();
}

bool operator < ( Date &a, Date &b)
{
    return a.ToInt()<b.ToInt();
}

bool operator <=( Date &a, Date &b)
{
    return a.ToInt()<=b.ToInt();
}

bool operator ==( Date &a, Date &b)
{
    return a.ToInt()==b.ToInt();
}

bool operator !=( Date &a, Date &b)
{
    return a.ToInt()!=b.ToInt();
}

std::ostream & operator <<(std::ostream &os,const Date &d)
{
    os<<d.m_year<<"-"<<setfill('0')<<setw(2)<<d.m_month<<"-"<<setfill('0')<<setw(2)<<d.m_day;
    return os;
}

std::istream & operator >>(std::istream &is,Date &d)
{
    Date old = d;
    is>>d.m_year>>d.m_month>>d.m_day;
    if(	(d.m_year<=0) ||
		(d.m_month>12 ||d.m_month<=0) || 
		(d.m_day<=0	  ||d.m_day>d.DayOfMonth(d.m_year,d.m_month)))
    {
        d = old;
        throw exception("Invalid number of date.");
    }
    return is;
}

Date& Date::operator = (const Date& d)
{
	this->m_year = d.m_year;
	this->m_month = d.m_month;
	this->m_day = d.m_day;
	return *this;
}

Date& Date::operator + (const int day)
{
    if(day==0)
	{
		return *this;
	}

    if(day>0)
    {
        this->m_day += day;
        while(this->m_day>this->DayOfMonth(this->m_year, this->m_month))
        {
            this->m_day -= this->DayOfMonth(this->m_year, this->m_month);
            this->m_month++;
            if(this->m_month>12)
            {
                ++this->m_year;
                this->m_month = 1;
            }
        }
        return *this;
    }
    else
	{
        return (*this)-(-day);
	}
}

Date& Date::operator += (const int day)
{
    return (*this)+day;
}

Date& Date::operator - (const int day)
{
	if(day==0)
	{
		return *this;
	}

    if(day>0)
    {
        this->m_day -= day;
        while(this->m_day<=0)
        {
            --this->m_month;
            if(this->m_month==0)
            {
                this->m_month=12;
                --this->m_year;
            }
            this->m_day+=this->DayOfMonth(this->m_year,this->m_month);
        }
        return *this;
    }
    else
	{
        return (*this)+(-day);
	}
}

Date& Date::operator -= (const int day)
{
    return (*this)-day;
}

int operator - (const Date &a, const Date &b)
{
    return abs(a.ToInt()-b.ToInt());
}

Date& Date::operator ++()
{
	cout<<"Date& Date::operator ++()"<<endl;
	return (*this)+1;
}

const Date Date::operator ++(int)
{
	cout<<"Date& operator ++(int)"<<endl;
	Date tmp = (*this);
	(*this)+1;
	return tmp;
}

Date::operator int()
{
	cout<<"Date::int()"<<endl;
	return this->ToInt();
}