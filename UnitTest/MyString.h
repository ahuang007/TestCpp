#pragma warning(disable:4996)
#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<cstring> //等价于 #include<string.h>
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str = "");
	MyString(const MyString& other); //拷贝构造函数
	MyString& operator=(const MyString& other);//赋值运算符函数（对象）
	MyString& operator=(const char* str);//赋值运算符函数（字符串）
	~MyString();
	void DisPlay() const;
	bool operator!() const;
	MyString& operator+(const char* str); //下面友元函数可以实现这个函数的功能 只是多一个转换构造
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