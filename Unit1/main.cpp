
#include<iostream>
#include<stdio.h>

using namespace std;

char* myString(){
	char buffer[6] = { 0 };
	char* str = "Hello world";
	cout << sizeof(str) << "|" << sizeof(buffer) << endl; // strΪָ�� ����Ϊ4  buffer����Ϊ sizeof(char)*6 = 6
	for (int i = 0; i < sizeof(buffer) - 1; i++){
		buffer[i] = *(str + i);
	}
	return buffer; // ��ʱ ���Ϊ Hello ����bufferΪջ���ڴ� ���������� ջ���ڴ���ͷ� buffer�Ľ��δ֪
}

char* myString1(){
	int len = 6;
	char* buffer = new char[len]; // malloc�÷�: char* buf = (char*)malloc(sizeof(char)*6); �� �ͷ���free  free(buf); 
	char* str = "Hello world";
	for (int i = 0; i < len - 1; i++){
		buffer[i] = *(str + i);
	}
	buffer[5] = '\0';
	return buffer; // ��ʱ ���Ϊ Hello bufferΪ�����ڴ� ���������� �����ڴ治���ͷ� ע��ʹ������ͷ�
}

/* std::endl �� '\n'������
'\n' ��ʾ����Ϊһ���س������ַ���
std::endl ����д'\n'���� ��������flush������ˢ�»�������
�ѻ������������д���ļ�������Ļ
*/
int main(){
	cout << "Hello,World!" << endl;

	printf("buffer1 : %s\n", myString()); // bufferΪ��ʱ�������δ֪
	char* buf = myString1();
	printf("buffer2 : %s\n", buf);
	delete buf; // Ҫ�ͷ� �������ڴ�й¶

	return 0;
}
