#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int func(int x){
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1); // 二进制 相同为0 不同为1 
		// 所以运行的次数为： 将x转换成二进制 然后数1的个数
	}
	return count;
}

string num2bin(unsigned int x){ // 这里只能是unsigned int 如果为signed int 则负数高位永远都为1 while(x)无法退出 死循环
	string str = "";
	if (x == 0){
		str = "0";
		return str;
	}

	int count = 0;
	while (x){
		count++;
		if (count > 100){
			cout << "error|" << x << endl;
			break;
		}
		str = to_string(x & 1) + str; // string头文件 提供 to_string方法
		x = x >> 1;
	}
	return str;
}

#define SQR(X) X*X // 未加括号的宏定义 宏定义正常展开 之后根据优先级来计算结果
#define SQR1(X) ((X)*(X)) // 宏定义为了避免运算符优先级 最好都加括号

int main(){
	int x = -1;
	cout << num2bin(x) << endl;
	printf("%d, %x, %o\n", x, x, x); // %d 十进制 %x 十六进制 %o 八进制	
	cout << func(x) << endl;

	int a = 10;
	int b = 10;
	int k = 2;
	int m = 1;
	a /= SQR(k + m) / SQR(k + m); //a = a/(k+m*k+m/k+m*k+m)= 10/(2+2*1+1/2+2*1+1) = 10/7.5 = 1; // 整数类型转换

	// 如果 只将a类型改为double 则结果为 10/7 = 1.428...
	// 如果 将a, m ,k 类型都改为double 则结果为 10/7.5 = 1.333...
	//(注意：int/int结果为int double x = 1/2 结果为0  如果想得到浮点型数据 则可以这么修改 double x = 1*1.0/2)

	b /= SQR1(k + m) / SQR1(k + m); // a = a/1 = 10;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}