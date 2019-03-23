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

//����ÿ������캯��
void TestFun1(const Clock c)
{
	cout<<"TestFun1"<<endl;
}

//������ÿ������캯��
void TestFun2(const Clock& c)
{
	cout<<"TestFun2"<<endl;
}

//����ÿ������캯��
Clock TestFun3(const Clock& c)
{
	cout<<"TestFun3"<<endl;
	return c;
}

//������ÿ������캯��
/*const*/ Clock& TestFun4(const Clock& c)
{
	cout<<"TestFun4"<<endl;
	//return c;
	return const_cast<Clock&>(c); //���ǰ�淵��ֵ����const ����Ҫconst_castǿ������ת��(ȥ��const����)
}

//��c�ķ�ʽʵ��ջ
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
	cout<<"��ջԪ��:"<<data<<endl;
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

	cout<<"��ջԪ��:"<<*data<<endl;

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
		cout<<"ջԪ������: "<<endl;
	}
	else
	{
		cout<<"ջ����Ԫ��"<<endl;
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




//ȫ��operator new, operator delete 
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
	Clock c1 = c;//�ȼ��� Clock c1(c); ���ÿ������캯��

	Clock c2;
	c2 = c1; //���ø�ֵ���������
	TestFun1(c);//���ÿ������캯��
	TestFun2(c1);
	Clock &c3 = TestFun3(c2); //���û�нӹ�������� �����溯��TestFun3�ͻ����� 
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
	cout<<a<<"�Ľ׳�: "<<result<<endl;
	*/

	/*
	int result = 1;
	int a;
	cin>>a;
	result = Fibonacci(a);
	cout<<"쳲��������е�"<<a<<"���ֵ��"<<result<<endl;
	*/

	/*Duff�豸*/
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
	MyString str2 = str1;  //����Ĭ�ϵĿ������캯��
						   //ϵͳ�ṩ��Ĭ�Ͽ������캯����ǳ���� ��str2.m_str = str1.m_str��
						   //��str2��str1ָ����ͬһ���ڴ� ���������ڽ�����ʱ�� ������������������ ͬһ���ڴ汻�ͷ����� -- ���� 
						   //������Ҫ�Լ�д�������캯�������
	
	MyString str3;
	str3.DisPlay();
	str3 = str2;		 //���ø�ֵ���������
						 //ϵͳ�ṩ��Ĭ�ϸ�ֵ���������Ҳ��ǳ����(str3.m_str = str1.m_str)
						 //������ڶ�̬�ڴ���� ������ʱ��Ҳ���������
						 //������Ҫ�Լ�д��ֵ��������������
	
	MyString str4;
	str4 = "123";	//��û�����صȺ������֮ǰ�� 1 ����ת�����캯�� 2 ���ø�ֵ�����
	str4.DisPlay();
	bool isEmpty = !str4;
	cout<<"str4 : "<<isEmpty<<endl;
	MyString str5;
	isEmpty = !str5;
	cout<<"str5 : "<<isEmpty<<endl;
	MyString str6 = "testing";
	cout<<str4+str6<<endl;
	cout<<str4+"hellocpp"<<endl; //�����÷����뽫+����Ϊ��Ԫ����
	str4[4] = 'Q'; //������õ���nonconst��[]��������غ��� 
	cout<<str4[4]<<endl;//������õ���const��[]��������غ���
	const MyString str7 = "sssssssssss";
	//str7[3] = 't'; //Error �������ܸı�
	cout<<str7[3]<<endl;
	str6+=str7;
	cout<<str6<<endl;

	//���������������
	MyString str8;
	cin>>str8;
	cout<<str8<<endl;
	*/

	/*	
	cout<<Test::GetCount()<<endl;
	Test t1;
	cout<<Test::GetCount()<<endl; // t1.GetCount()Ҳ�� �����Ƽ�
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

	Date d1; //����Ĭ�Ϲ��캯�� ��ʼ��Ϊ1900-01-01
	d1.Display();
	int a = d1;//��ʽ����ת��
	cout<<a<<endl;
	int b = (int)d1;
	cout<<b<<endl;//��ʾ����ת��

	//Date d2;
	//cin>>d2;
	//cout<<d2<<endl;
	*/

	//Singleton& s1 = Singleton::GetInstance();
	//Singleton& s2 = Singleton::GetInstance();
	//Singleton s3(*s1); //���ܵ��ÿ������캯��
    //*s2 = *s1;  //���ܵ��ø�ֵ�����
	
	/*
	const Test t(10);
	t.GetX();
	t.GetX();
	cout<<t.GetOutCount()<<endl;

	Test *t1 = new Test(100); // new operator <=> operator new + ���ù��캯��
	delete t1;
	char *str = new char[100]; //����ȫ��operator new
	//delete [] str;
	char tmp[10];
	Test *t2 = new (tmp) Test(100); //����placement new <=> �������ڴ� + ���ù��캯��
	cout<<t2->GetX()<<endl;
	t2->~Test(); //��ʾ������������ ��Ϊû�з����ڴ棬����ֱ�ӵ�����������

	Test *t3 = new (str) Test(100); //����placement new <=> �������ڴ� + ���ù��캯��
	cout<<t3->GetX()<<endl;
	delete t3; //������������ �ͷ�str�ڴ�

	Test* t4 = new(__FILE__, __LINE__)Test(300); //__FILE__ �ļ���(������·����) __LINE__ �ļ��к�
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
	typedef int(*pFun)(int, int); //����һ��������
	pFun pf;//ʹ�������Ͷ���һ������
	pf = add; //���������׵�ַ����ָ��
	cout<<pf(3, 5)<<endl;//���ú���ָ��
	cout<<getPower(3, 5, (*pf))<<endl;//����ָ����Ϊ����
	*/
	
	//�ָ��ַ���  ����һ strtok
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
	
	//������ stl
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

//c++11 �÷�
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
	
	//ԭ������ָ����÷�
	auto func = &printf; 
	(*func)("aaa"); 
*/

	//Ͱ����
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