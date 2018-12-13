
#include<iostream>

using namespace std;

//extern int num; // 静态变量不能访问
extern int sum; 

void print_sum(void){
	cout << "sum is " << sum << endl;
	//cout << "num is " << num << endl;
}