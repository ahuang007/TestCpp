#include "MyPoint.h"
#include<math.h>

MyPoint::MyPoint(void)
{
}


MyPoint::~MyPoint(void)
{
}

double Distance(const MyPoint& p1, const MyPoint& p2)
{
	double x_dis = p1.m_x - p2.m_x;
	double y_dis = p1.m_y - p2.m_y;
	return sqrt(x_dis*x_dis + y_dis*y_dis);
}