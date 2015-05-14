#ifndef _CLOCK_H
#define _CLOCK_H

class Clock
{
public:
	Clock();
	Clock(int, int, int);
	Clock(const Clock& c);
	Clock& operator=(const Clock& c); 
	~Clock();
	void Display();
	void SetHour(int);
	int	GetHour();
	void SetMinute(int);
	int GetMinute();
	void SetSecond(int);
	int GetSecond();
	void Update();
private:
	int m_hour;
	int m_minute;
	int m_second;
};

#endif //_CLOCK_H