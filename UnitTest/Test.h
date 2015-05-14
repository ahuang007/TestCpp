#ifndef _TEST_H_
#define _TEST_H_
#include<iostream>
using namespace std;

class Test
{
public:
	Test(void)
	{
		++s_count;
	}
	Test(int x):m_x(x), m_count(0)
	{
		cout<<"Test(int x):m_x(x), m_count(0)"<<endl;
		++s_count;
	}
	~Test(void)
	{
		cout<<"~Test(void)"<<endl;
		--s_count;
	}

	static int GetCount()
	{
		//m_x = 1; // 错误 静态成员函数不可以访问非静态成员
		return Test::s_count;
	}

	int Fun1()
	{
		s_count = 10; //非静态成员函数可以访问静态成员
	}

	static const int s_num  = 1; //只有静态常量整型数据成员才可以在类中初始化

	int GetX() const //如果函数不修改对象的状态 应尽量将其声明为const成员函数
	{
		//m_x = 100; //错误 const成员函数不能修改对象的状态
		m_count++;
		return m_x;
	}
	
	int GetX() //与const函数构成重载
	{
		m_count++;
		return m_x;
	}

	int GetOutCount() const
	{
		return m_count;
	}

	void* operator new(size_t size)
	{
		cout<<"void* operator new(size_t size)"<<endl;  
		void* p = malloc(size);
		return p;
	}
	void operator delete(void *p)
	{
		cout<<"void operator delete(void *p)"<<endl;
		free(p);
	}
	void operator delete(void *p, size_t size)//如果上面函数和这个函数都存在 那么调用上面那个
	{
		cout<<"void operator delete(void *p, size_t size)"<<endl;
		free(p);
	}
	void* operator new(size_t size, const char* file, long line) //起到跟踪的作用 定位到哪个文件 哪一行
	{
		cout<<"void* operator new(size_t size, const char* file, long line)"<<endl;
		cout<<file<<":"<<line<<endl;
		void* p = malloc(size);
		return p;
	}
	void operator delete(void* p, const char* file, long line)
	{
		cout<<"void operator delete(void* p, const char* file, long line)"<<endl;
		cout<<file<<":"<<line<<endl;
		free(p);
	}
	void * operator new(size_t size, void *p)//placement new
	{
		cout<<"void * operator new(size_t size, void *p)"<<endl;
		return p;
	}
	void operator delete(void*, void*)  
	{  
		cout<<"destory"<<endl;
	}  


private:	
	static int s_count; //静态成员的引用性声明
	int m_x;
	mutable int m_count; //在const成员函数中可以修改
};

#endif //_TEST_H_