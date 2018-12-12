
#include<iostream>
#include<limits>
#include<string>
using namespace std;

#define PRINT_TYPE_INFO(T) cout <<#T<< "\t\t" << "byte：" << sizeof(T) << "\t\tmax:" << (numeric_limits<T>::max)() << "\t\tmin：" << (numeric_limits<T>::min)() << endl
// #T => "T"
// fixme: 本来打算写个模板函数 结果发现不知道怎么将类型作为函数的参数 
/*
template<typename T>
void printtypeinfo(typename T){ // 这么写编译不过
	cout <<#T<< "\t\t" << "byte：" << sizeof(T) << "\t\tmax:" << (numeric_limits<T>::max)() << "\t\tmin：" << (numeric_limits<T>::min)() << endl;
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
	cout << "string" << "\t\t" << "byte：" << sizeof(string) << endl;
	cout << "type:\t\t" << "-----------------size----------------" << endl;

	system("pause");
	return 0;
}

// 结果为:  4294967295
/*原因分析
	尽管long等级比unsigned int高 但是在系统中都是32位整数
	且long 并不足以容纳unsigned int的所有值，因此编译器会将这两个操作数都转换为unsigned long
	如此 （unsigned long)a 的结果就变成了一个很大的数
	-1 在无符号中的表现为 FFFF FFFF = 2^32 - 1 = 4294967296 -1 = 4294967295
*/