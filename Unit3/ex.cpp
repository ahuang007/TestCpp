
#include<iostream>

using namespace std;

//extern int num; // 静态变量不能访问 它的可见域为文件内
extern int sum; 

void print_sum(void){
	cout << "sum is " << sum << endl;
	//cout << "num is " << num << endl;
}