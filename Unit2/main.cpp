
#include<iostream>
using namespace std;

int main(){
	long a = -1L;
	unsigned int b = 100;
	cout << sizeof(long) << "|" << sizeof(unsigned int) << "|"<<sizeof(float)<<"|"<<sizeof(double)<< endl;
	cout << "a vs b: " << (a > b ? a : b) << endl;
	system("pause");
	return 0;
}

// 结果为:  4294967295
/*原因分析
	尽管long等级比unsigned int高 但是在32/64位系统中都是32位整数
	且long 并不足以容纳unsigned int的所有值，因此编译器会将这两个操作数都转换为unsigned long
	如此 （unsigned long)a 的结果就变成了一个很大的数
	-1 在无符号中的表现为 FFFF FFFF = 2^32 - 1 = 4294967296 -1 = 4294967295
*/