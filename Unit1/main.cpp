
#include<iostream>
#include<stdio.h>

using namespace std;

char* myString(){
	char buffer[6] = { 0 };
	char* str = "Hello world";
	cout << sizeof(str) << "|" << sizeof(buffer) << endl; // str为指针 长度为4  buffer长度为 sizeof(char)*6 = 6
	for (int i = 0; i < sizeof(buffer) - 1; i++){
		buffer[i] = *(str + i);
	}
	return buffer; // 此时 结果为 Hello 但是buffer为栈区内存 函数结束后 栈区内存会释放 buffer的结果未知
}

char* myString1(){
	int len = 6;
	char* buffer = new char[len]; // malloc用法: char* buf = (char*)malloc(sizeof(char)*6); ， 释放用free  free(buf); 
	char* str = "Hello world";
	for (int i = 0; i < len - 1; i++){
		buffer[i] = *(str + i);
	}
	buffer[5] = '\0';
	return buffer; // 此时 结果为 Hello buffer为堆区内存 函数结束后 堆区内存不会释放 注意使用完后释放
}

/* std::endl 与 '\n'的区别
'\n' 表示内容为一个回车符的字符串
std::endl 除了写'\n'以外 还调用了flush函数，刷新缓冲区，
把缓冲区里的数据写入文件或者屏幕
*/
int main(){
	cout << "Hello,World!" << endl;

	printf("buffer1 : %s\n", myString()); // buffer为临时变量结果未知
	char* buf = myString1();
	printf("buffer2 : %s\n", buf);
	delete buf; // 要释放 否则有内存泄露

	return 0;
}
