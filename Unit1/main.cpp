
#include<iostream>

using namespace std;

int main(){
	cout << "Hello,World!" << endl;
	system("pause");
	return 0;
}

/* std::endl 与 '\n'的区别
 '\n' 表示内容为一个回车符的字符串
 std::endl 除了写'\n'以外 还调用了flush函数，刷新缓冲区，
 把缓冲区里的数据写入文件或者屏幕
 */