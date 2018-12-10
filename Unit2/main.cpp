
#include<iostream>
using namespace std;

int main(){
	long a = -1L;
	unsigned int b = 100;
	cout << "avsb: " << (a > b ? a : b) << endl;
	system("pause");
	return 0;
}

// 结果为:  4294967295
//todo: 原因分析