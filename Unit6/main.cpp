#pragma pack(push) //保存对齐状态
#pragma pack (4) // 指定结构体内存对齐值

#include <iostream>

using namespace std;

struct{
	char a;
	char b;
	char c;
}A;

struct {
	short a;
	short b;
	short c;
}B;

struct {
	short a;
	char b;
	long c;
}C;

struct {
}D;

class E{
};

int main(){
	cout << "sizeof(A) = " << sizeof(A)<<endl; // 3
	cout << "sizeof(B) = " << sizeof(B)<<endl; // 6
	cout << "sizeof(C) = " << sizeof(C) << endl; // 8 ? 不正常啊 应该是12
	cout << "sizeof(D) = " << sizeof(D) << endl; // 1 空结构体 占一个字节 
	cout << "sizeof(E) = " << sizeof(E) << endl; // 1 空类 占一个字节 
	return 0;
}

#pragma pack(pop)//恢复对齐状态