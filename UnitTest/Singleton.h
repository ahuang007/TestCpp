#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include<iostream>
using namespace std;

class Singleton
{
public:

	static Singleton& GetInstance()
	{
		static Singleton m_instance; //�ֲ���̬����
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

	//�ֶ������ͷ��ڴ� ȱ�� �ܶ�ط����õ����ÿ���
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
	Singleton(void);				   //���캯��
	Singleton(const Singleton& other); //�������캯��
	Singleton& operator=(const Singleton& other);//��ֵ���������
	//static Singleton* m_instance;
	//static Garbo m_garbo; //���ö����ȷ��������
};

#endif //_SINGLETON_H_