#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include<iostream>
using namespace std;

class Singleton
{
public:

	static Singleton& GetInstance()
	{
		static Singleton m_instance; //局部静态对象
		return m_instance;
	}
	/*
	static Singleton* GetInstance()
	{
		if(m_instance == NULL)
		{
			m_instance = new Singleton;
		}
		return m_instance;
	}

	//手动析构释放内存 缺点 很多地方调用到不好控制
	static void Free()
	{
		if(m_instance != NULL)
		{
			delete m_instance;
		}
	}

	class Garbo
	{
	public:
		~Garbo()
		{
			if(Singleton::GetInstance() != NULL)
			{
				delete m_instance;
			}
		}
	};
	*/
	~Singleton(void);
private:
	Singleton(void);				   //构造函数
	Singleton(const Singleton& other); //拷贝构造函数
	Singleton& operator=(const Singleton& other);//赋值运算符函数
	//static Singleton* m_instance;
	//static Garbo m_garbo; //利用对象的确定性析构
};

#endif //_SINGLETON_H_