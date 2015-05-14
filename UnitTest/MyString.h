#pragma warning(disable:4996)
#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<cstring> //�ȼ��� #include<string.h>
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str = "");
	MyString(const MyString& other); //�������캯��
	MyString& operator=(const MyString& other);//��ֵ���������������
	MyString& operator=(const char* str);//��ֵ������������ַ�����
	~MyString();
	void DisPlay() const;
	bool operator!() const;
	MyString& operator+(const char* str); //������Ԫ��������ʵ����������Ĺ��� ֻ�Ƕ�һ��ת������
	friend MyString operator+(const MyString& str1, const MyString& str2);
	MyString& operator+=(const MyString& str);
	char& operator[](unsigned int index);
	const char& operator[](unsigned int index) const;
	friend ostream & operator <<(ostream &os,const MyString& str);   
    friend istream & operator >>(istream &is, MyString& str);   
	
private:
	char* AllocAndCopy(const char* str);
	char* m_str;
};

#endif //_MYSTRING_H_