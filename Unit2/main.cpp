
#include<iostream>
#include<limits>
#include<string>
using namespace std;

#define PRINT_TYPE_INFO(T) cout <<#T<< "\t\t" << "byte��" << sizeof(T) << "\t\tmax:" << (numeric_limits<T>::max)() << "\t\tmin��" << (numeric_limits<T>::min)() << endl
// #T => "T"
// fixme: ��������д��ģ�庯�� ������ֲ�֪����ô��������Ϊ�����Ĳ��� 
/*
template<typename T>
void printtypeinfo(typename T){ // ��ôд���벻��
	cout <<#T<< "\t\t" << "byte��" << sizeof(T) << "\t\tmax:" << (numeric_limits<T>::max)() << "\t\tmin��" << (numeric_limits<T>::min)() << endl;
}
*/

int main(){
	long a = -1L;
	unsigned int b = 100;
	cout << "max(a,b): " << (a > b ? a : b) << endl;

	cout << "type:\t\t" << "-----------------size----------------" << endl;
	PRINT_TYPE_INFO(bool);
	PRINT_TYPE_INFO(char); // signed char
	PRINT_TYPE_INFO(unsigned char);
	PRINT_TYPE_INFO(wchar_t);
	PRINT_TYPE_INFO(short);
	PRINT_TYPE_INFO(int); // signed int
	PRINT_TYPE_INFO(unsigned); //unsigned int
	PRINT_TYPE_INFO(long); //signed long 
	PRINT_TYPE_INFO(unsigned long);
	PRINT_TYPE_INFO(double);
	PRINT_TYPE_INFO(long double);
	PRINT_TYPE_INFO(float);
	PRINT_TYPE_INFO(size_t);
	cout << "string" << "\t\t" << "byte��" << sizeof(string) << endl;
	cout << "type:\t\t" << "-----------------size----------------" << endl;

	system("pause");
	return 0;
}

// ���Ϊ:  4294967295
/*ԭ�����
	����long�ȼ���unsigned int�� ������ϵͳ�ж���32λ����
	��long ������������unsigned int������ֵ����˱������Ὣ��������������ת��Ϊunsigned long
	��� ��unsigned long)a �Ľ���ͱ����һ���ܴ����
	-1 ���޷����еı���Ϊ FFFF FFFF = 2^32 - 1 = 4294967296 -1 = 4294967295
*/