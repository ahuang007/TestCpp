#ifndef _MYPOINT_H_
#define _MYPOINT_H_

class MyPoint
{
public:
	MyPoint(void);
	~MyPoint(void);
	MyPoint(int x, int y):m_x(x), m_y(y)
	{
	}
	friend double Distance(const MyPoint& p1, const MyPoint& p2);
private:
	int m_x;
	int m_y;
};

#endif //_MYPOINT_H_