#include<iostream>

using namespace std;

void func(void);

static int num = 10; // ȫ�־�̬����(�ļ��ڿɼ�)
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
	static int i = 5; // �ֲ���̬����(�����ڿɼ�)
	i++;
	cout << "����iΪ " << i;
	cout << ", ����countΪ " << num << endl;
}