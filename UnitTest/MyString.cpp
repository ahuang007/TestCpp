#include "MyString.h"

MyString::MyString(const char* str)
{
	cout<<"MyString::MyString(char* str)"<<endl;
	this->m_str = this->AllocAndCopy(str);
}

MyString::~MyString()
{
	delete [] m_str;
}

void MyString::DisPlay() const
{
	cout<<m_str<<endl;
}

MyString::MyString(const MyString& other)
{
	this->m_str = this->AllocAndCopy(other.m_str);
}

char* MyString::AllocAndCopy(const char* str)
{
	int len = strlen(str) +1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

MyString& MyString::operator=(const MyString& other)
{
	cout<<"MyString& MyString::operator=(const MyString& other)"<<endl;
	if(this == &other)
	{
		return *this;
	}

	delete [] this->m_str;

	this->m_str = this->AllocAndCopy(other.m_str);

	return *this; //减少调用拷贝构造函数
}

MyString& MyString::operator=(const char* str)
{
	cout<<"MyString& MyString::operator=(const char* str)"<<endl;

	delete [] this->m_str;

	this->m_str = this->AllocAndCopy(str);

	return *this; //减少调用拷贝构造函数
}

bool MyString::operator!() const
{
	return strlen(this->m_str) == 0;
}

 MyString operator+(const MyString& str1, const MyString& str2)
{
	/*
	char *str;
	int len = strlen(str1.m_str) + strlen(str2.m_str) + 1;
	str = new char[len];
	memset(str, 0 , len);
	strcpy(str, str1.m_str);
	strcat(str, str2.m_str);

	MyString tmp(str);
	delete [] str;

	return tmp;
	*/
	MyString str(str1);
	str += str2;
	return str;
}

 MyString& MyString::operator+(const char* str)
 {
	char *tmp;
	int len = strlen(this->m_str) + strlen(str) + 1;
	tmp = new char[len];
	memset(tmp, 0 , len);
	strcpy(tmp, this->m_str);
	strcat(tmp, str);

	delete [] this->m_str;
	this->m_str = tmp;
	return *this;
 }

 MyString& MyString::operator+=(const MyString& str)
 {
	return (*this)+str.m_str;
 }

char& MyString::operator[](unsigned int index)
{
	cout<<"char& MyString::operator[](unsigned int index)"<<endl;
	//return m_str[index];
	//nonconst版本调用const版本
	return const_cast<char&>(static_cast<const MyString&>(*this)[index]);
}

const char& MyString::operator[](unsigned int index) const
{
	cout<<"const char& MyString::operator[](unsigned int index) const"<<endl;
	return m_str[index];
}

ostream & operator <<(ostream &os,const MyString& str)
{
	os<<str.m_str;
	return os;
}

istream & operator >>(istream &is, MyString& str)
{
	char tmp[1024];
	cin>>tmp;
	str = tmp;
	return is;
}