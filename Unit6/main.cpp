#pragma pack(push) //�������״̬
#pragma pack (4) // ָ���ṹ���ڴ����ֵ

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
	cout << "sizeof(C) = " << sizeof(C) << endl; // 8 ? �������� Ӧ����12
	cout << "sizeof(D) = " << sizeof(D) << endl; // 1 �սṹ�� ռһ���ֽ� 
	cout << "sizeof(E) = " << sizeof(E) << endl; // 1 ���� ռһ���ֽ� 
	return 0;
}

#pragma pack(pop)//�ָ�����״̬