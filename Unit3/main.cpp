#include<iostream>

using namespace std;

void func(void);

static int num = 10; // 全局静态变量(文件内可见)
int sum = 999;  

extern void print_sum(void);

int main(){
	while (num--){
		func();
	}
	print_sum();
	return 0;
}

void func(void){
	static int i = 5; // 局部静态变量(函数内可见)
	i++;
	cout << "变量i为 " << i;
	cout << ", 变量count为 " << num << endl;
}