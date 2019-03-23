#include<iostream>
#include <windows.h>
#include "Clock.h"
#include "MyString.h"
#include "Utility.h"
#include "Test.h"
#include "Date.h"
#include "Singleton.h"
#include<stdio.h>
#include<assert.h>
#include"MyStack.h"
#include"MyPoint.h"
#include "MyMD5.h"
#include<regex>
#include<vector>
#include "Array.h"

using namespace std;

#define MAX_LEN 1024
#define MAX 100

//会调用拷贝构造函数
void TestFun1(const Clock c)
{
	cout<<"TestFun1"<<endl;
}

//不会调用拷贝构造函数
void TestFun2(const Clock& c)
{
	cout<<"TestFun2"<<endl;
}

//会调用拷贝构造函数
Clock TestFun3(const Clock& c)
{
	cout<<"TestFun3"<<endl;
	return c;
}

//不会调用拷贝构造函数
/*const*/ Clock& TestFun4(const Clock& c)
{
	cout<<"TestFun4"<<endl;
	//return c;
	return const_cast<Clock&>(c); //如果前面返回值不加const 就需要const_cast强制类型转换(去除const属性)
}

//用c的方式实现栈
struct CLinkNode
{
	int data;
	struct CLinkNode* next;
};

struct CStack
{
	struct CLinkNode * head;
	int size;
};

void CStackInit(struct CStack* stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void CStackPush(struct CStack* stack, const int data)
{
	struct CLinkNode* node = (struct CLinkNode*)malloc(sizeof(struct CLinkNode));
	assert(node != NULL);
	node->data = data;
	node->next = stack->head;
	stack->head = node;
	++stack->size;
	cout<<"入栈元素:"<<data<<endl;
}

int CStackEmpty(struct CStack* stack)
{
	return (stack->size == 0);
}

int CStackPop(struct CStack* stack, int* data)
{
	if(CStackEmpty(stack))
	{
		return 0;
	}

	struct CLinkNode* node = stack->head;
	*data = stack->head->data;
	stack->head = stack->head->next;
	free(node);
	--stack->size;

	cout<<"出栈元素:"<<*data<<endl;

	return 1;
}

void CStackCleanup(struct CStack* stack)
{
	struct CLinkNode* node;
	while(stack->head)
	{
		node = stack->head;
		stack->head = stack->head->next;
		free(node);
	}
	stack->size = 0;
}

void CStackTraverse(struct CStack* stack)
{
	if(!CStackEmpty(stack))
	{
		cout<<"栈元素如下: "<<endl;
	}
	else
	{
		cout<<"栈中无元素"<<endl;
	}

	struct CLinkNode* node = stack->head;
	while(node)
	{
		cout<<node->data<<" ";
		node = node->next;
	}

	cout<<endl;
}

int add(int a, int b)
{
	return a+b;
}

int getPower(int a, int b, int (*p)(int, int))
{
	int sum = (*p)(a, b);
	return sum*sum;
}




//全局operator new, operator delete 
/*
void* operator new(size_t size)
{
	cout<<"global void* operator new(size_t size)"<<endl;  
	void* p = malloc(size);
	return p;
}

void operator delete(void *p)
{
	cout<<"global void operator delete(void *p)"<<endl;
	free(p);
}

void* operator new[](size_t size)
{
	cout<<"global void* operator new[](size_t size)"<<endl;  
	void* p = malloc(size);
	return p;
}

void operator delete[](void *p)
{
	cout<<"global void operator delete[](void *p))"<<endl;
	free(p);
}
*/

void print(string str){
	cout << str << endl;
}

int main()
{
	/*
	SYSTEMTIME sysTime; 
	GetLocalTime(&sysTime); 

	Clock c(sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	Clock c1 = c;//等价于 Clock c1(c); 调用拷贝构造函数

	Clock c2;
	c2 = c1; //调用赋值运算符函数
	TestFun1(c);//调用拷贝构造函数
	TestFun2(c1);
	Clock &c3 = TestFun3(c2); //如果没有接管这个引用 调用玩函数TestFun3就会析构 
	TestFun4(c2);
	while(1)
	{
		Sleep(1000);
		c2.Update();
		c2.Display();
	}
	*/
	
	/*
	int a[] = {4,2,3,1,6,9,8,7,0};
	int n = sizeof(a)/sizeof(a[0]);
	//BubbleSort(a, n);
	QuickSort(a, 0, n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	*/

	/*
	double result = 1;
	int a;
	cin>>a;
    result = Factorial(a);
	cout<<a<<"的阶乘: "<<result<<endl;
	*/

	/*
	int result = 1;
	int a;
	cin>>a;
	result = Fibonacci(a);
	cout<<"斐波那契数列第"<<a<<"项的值："<<result<<endl;
	*/

	/*Duff设备*/
	/*
	int a[20] = {1,2,3,4,5,6,7,8,9,10,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	int b[20] = {};
	send(b, a, sizeof(a)/sizeof(a[0]));
	for(int i=0;i<20;i++)
	{
		cout<<b[i]<<" "<<endl;
	}
	*/

	/*
	MyString str1("HelloWorld");
	str1.DisPlay();
	MyString str2 = str1;  //调用默认的拷贝构造函数
						   //系统提供的默认拷贝构造函数是浅拷贝 （str2.m_str = str1.m_str）
						   //即str2和str1指向了同一块内存 当生存周期结束的时候 析构函数被调用两次 同一块内存被释放两次 -- 错误 
						   //所以需要自己写拷贝构造函数做深拷贝
	
	MyString str3;
	str3.DisPlay();
	str3 = str2;		 //调用赋值运算符函数
						 //系统提供的默认赋值运算符函数也是浅拷贝(str3.m_str = str1.m_str)
						 //如果存在动态内存分配 析构的时候也会出现问题
						 //所以需要自己写赋值运算符函数做深拷贝
	
	MyString str4;
	str4 = "123";	//（没有重载等号运算符之前） 1 调用转换构造函数 2 调用赋值运算符
	str4.DisPlay();
	bool isEmpty = !str4;
	cout<<"str4 : "<<isEmpty<<endl;
	MyString str5;
	isEmpty = !str5;
	cout<<"str5 : "<<isEmpty<<endl;
	MyString str6 = "testing";
	cout<<str4+str6<<endl;
	cout<<str4+"hellocpp"<<endl; //这种用法必须将+重载为友元函数
	str4[4] = 'Q'; //这个调用的是nonconst的[]运算符重载函数 
	cout<<str4[4]<<endl;//这个调用的是const的[]运算符重载函数
	const MyString str7 = "sssssssssss";
	//str7[3] = 't'; //Error 常量不能改变
	cout<<str7[3]<<endl;
	str6+=str7;
	cout<<str6<<endl;

	//流操作运算符重载
	MyString str8;
	cin>>str8;
	cout<<str8<<endl;
	*/

	/*	
	cout<<Test::GetCount()<<endl;
	Test t1;
	cout<<Test::GetCount()<<endl; // t1.GetCount()也行 但不推荐
	Test* t2 = new Test();
	cout<<Test::GetCount()<<endl;
	delete t2;
	cout<<Test::GetCount()<<endl;
	cout<<Test::s_num<<endl;
	*/

	/*
	int year = 2010;
	cout<<Date::IsLeapYear(year)<<endl;
	SYSTEMTIME sysTime; 
	GetLocalTime(&sysTime); 
	Date d(sysTime.wYear, sysTime.wMonth, sysTime.wDay);
	d.Display();
	d = d+3;
	d.Display();
	d = d+(-5);
	d.Display();
	d += 3;
	d.Display();
	d -= 5;
	d.Display();

	Date d1;
	cout<<d1 - d<<endl;
	Date d2 = d1++;
	d2.Display();
	d1.Display();
	++d1;
	d1.Display();

	Date d1; //调用默认构造函数 初始化为1900-01-01
	d1.Display();
	int a = d1;//隐式类型转换
	cout<<a<<endl;
	int b = (int)d1;
	cout<<b<<endl;//显示类型转换

	//Date d2;
	//cin>>d2;
	//cout<<d2<<endl;
	*/

	//Singleton& s1 = Singleton::GetInstance();
	//Singleton& s2 = Singleton::GetInstance();
	//Singleton s3(*s1); //不能调用拷贝构造函数
    //*s2 = *s1;  //不能调用赋值运算符
	
	/*
	const Test t(10);
	t.GetX();
	t.GetX();
	cout<<t.GetOutCount()<<endl;

	Test *t1 = new Test(100); // new operator <=> operator new + 调用构造函数
	delete t1;
	char *str = new char[100]; //调用全局operator new
	//delete [] str;
	char tmp[10];
	Test *t2 = new (tmp) Test(100); //调用placement new <=> 不分配内存 + 调用构造函数
	cout<<t2->GetX()<<endl;
	t2->~Test(); //显示调用析构函数 因为没有分配内存，所以直接调用析构函数

	Test *t3 = new (str) Test(100); //调用placement new <=> 不分配内存 + 调用构造函数
	cout<<t3->GetX()<<endl;
	delete t3; //调用析构函数 释放str内存

	Test* t4 = new(__FILE__, __LINE__)Test(300); //__FILE__ 文件名(带绝对路径的) __LINE__ 文件行号
	delete t4;
	*/
		
	/*
	struct CStack stack;
	CStackInit(&stack);
	CStackTraverse(&stack);
	for(int i=1;i<=5;i++)
	{
		CStackPush(&stack, i);
	}
	CStackTraverse(&stack);
	for(int i=1;i<=5;i++)
	{
		int m = 0;
		CStackPop(&stack, &m);
	}
	
	CStackTraverse(&stack);
	*/
	
	/*
	MyStack stack;
	stack.Traverse();
	for(int i=1;i<=5;i++)
	{
		stack.Push(i);
	}
	stack.Traverse();
	
	for(int i=1;i<=5;i++)
	{
		int m = 0;
		stack.Pop(m);
	}
	stack.Traverse();
	*/
	
	/*
	MyPoint p1(3,3);
	MyPoint p2(6,7);
	double distance = Distance(p1, p2);
	cout<<distance<<endl;
	*/
	
	/*
	typedef int(*pFun)(int, int); //定义一个新类型
	pFun pf;//使用新类型定义一个变量
	pf = add; //将函数的首地址赋给指针
	cout<<pf(3, 5)<<endl;//调用函数指针
	cout<<getPower(3, 5, (*pf))<<endl;//函数指针作为参数
	*/
	
	//分隔字符串  方法一 strtok
	/*
	char str[] = "now # is the time for all # good men to come to the # aid of their country";
	char delims[] = "#";
	char *result = NULL;
	result = strtok( str, delims );   
	while( result != NULL ) 
	{       
		printf( "result is \"%s\"\n", result );
		result = strtok( NULL, delims );   
	}            
	*/
	
	//方法二 stl
	/*
	string str = "123;abce;####;%%%%%%%;@@@@@@@@@@";
	const string delims = ";";
	vector<string> cvec;
	split(str, delims, cvec);
	vector<string>::iterator cit;
	for(cit=cvec.begin();cit!=cvec.end();cit++)
	{
		cout<<*cit<<endl;
	}
	*/
	
	/*
	double sum = 1;
	for(int i=0;i<31;i++)
		sum*=2;
	Date d1(1970,1,1);
	cout<<d1<<endl;
	d1 += sum/(3600*24);
	cout<<d1<<endl;

	int day = sum/(24*3600*100);
	cout<<"day : "<<day<<endl;
	*/
	
	/*
	int arr1[1024] = {1,2,3,4,10,12,15,19};  
	int arr2[] = {5,6,7,8,11,13,14,21};
	int len1 = 0;
	for(int j = 0 ; j<1024;j++){
		if(arr1[j] !=0)
			len1++;
	}
	int len2 = sizeof(arr2)/sizeof(int);
	sort2arr(arr1, len1, arr2, len2); 
	for(int i =0 ; i < len1+len2; i++)
		cout << arr1[i] << " ";
	cout<<endl;
	*/
	
	/*
	const char* c_str = "123456";
	cout<<CMD5(c_str).toString()<<endl;

	const std::regex pattern("111|123|abc");
	cout<<c_str<<" : "<<std::regex_search(c_str, pattern)<<endl;
	*/

//c++11 用法
/*
	auto index = 10;
	cout << ++index<< endl;

	auto ptr = [](int a, int b) {
		return a + b;
	};
	cout << ptr(3, 5) << endl;
	
	vector<int> vecTemp;
	vecTemp.push_back(2);
	vecTemp.push_back(3);
	for_each(vecTemp.begin(), vecTemp.end(), [](int v){cout << v << endl; });
	
	//原来函数指针的用法
	auto func = &printf; 
	(*func)("aaa"); 
*/

	//桶排序
/*
	int book[1001];
	for(int i = 0; i <= 1000; i++){
		book[i] = 0;
	}
	int arr[] = { 101, 105, 103, 101, 110, 109, 99, 1, 999, 666, 888, 777, 999, 9, 99, 88, 199 };
	int size = int(sizeof(arr) / sizeof(int));
	for (int i = 0; i < size; i++){
		book[arr[i]]++;
	}
	for (int i = 0; i <= 1000; i++){
		for (int j = 0; j < book[i]; j++){
			cout << i << " "; 
		}
	}
	cout << endl;
*/

	Array arr;
	for (int i = 1; i < 50; i++){
		arr.push_back(i);
	}
	for (int i = 0; i < arr.getSize(); i++){
		cout << arr.getValue(i) << endl;
	}

	system("pause");
	return 0;
}