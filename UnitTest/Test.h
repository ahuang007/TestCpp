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
		//m_x = 1; // ���� ��̬��Ա���������Է��ʷǾ�̬��Ա
		return Test::s_count;
	}

	int Fun1()
	{
		s_count = 10; //�Ǿ�̬��Ա�������Է��ʾ�̬��Ա
	}

	static const int s_num  = 1; //ֻ�о�̬�����������ݳ�Ա�ſ��������г�ʼ��

	int GetX() const //����������޸Ķ����״̬ Ӧ������������Ϊconst��Ա����
	{
		//m_x = 100; //���� const��Ա���������޸Ķ����״̬
		m_count++;
		return m_x;
	}
	
	int GetX() //��const������������
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
	void operator delete(void *p, size_t size)//������溯����������������� ��ô���������Ǹ�
	{
		cout<<"void operator delete(void *p, size_t size)"<<endl;
		free(p);
	}
	void* operator new(size_t size, const char* file, long line) //�𵽸��ٵ����� ��λ���ĸ��ļ� ��һ��
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
	static int s_count; //��̬��Ա������������
	int m_x;
	mutable int m_count; //��const��Ա�����п����޸�
};

#endif //_TEST_H_