#ifndef _MYSTACK_H_
#define _MYSTACK_H_
#include<iostream>
using namespace std;

class MyStack
{
	//�ṹ��Ҳ����
	struct Node
	{
		int m_data;
		struct Node* m_next;
		Node(int data, struct Node* next):m_data(data), m_next(next)
		{
		}
	};
public:
	MyStack(void):m_head(0), m_size(0)
	{
	}
	~MyStack()
	{
		struct Node* node;
		while(m_head)
		{
			node = m_head;
			m_head = m_head->m_next;
			free(node);
		}
		m_size = 0;
	}
	void Push(const int data)
	{
		struct Node* node = new Node(data, m_head);
		m_head = node;
		++m_size;
		cout<<"��ջԪ��:"<<data<<endl;
	}
	bool Pop(int& data)
	{
		if(this->IsEmpty())
		{
			return false;
		}

		Node* tmp = m_head;
		data = tmp->m_data;
		m_head = m_head->m_next;
		delete tmp;
		--m_size;

		cout<<"��ջԪ��:"<<data<<endl;

		return true;
	}
	bool IsEmpty() const
	{
		return (m_size == 0);
	}
	void Traverse() const
	{
		if(!this->IsEmpty())
		{
			cout<<"ջԪ������: "<<endl;
		}
		else
		{
			cout<<"ջ����Ԫ��"<<endl;
		}

		struct Node* node = m_head;
		while(node)
		{
			cout<<node->m_data<<" ";
			node = node->m_next;
		}
		cout<<endl;
	}
private:
	Node* m_head;
	int m_size;
};

#endif //_MYSTACK_H_