#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int func(int x){
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1); // ������ ��ͬΪ0 ��ͬΪ1 
		// �������еĴ���Ϊ�� ��xת���ɶ����� Ȼ����1�ĸ���
	}
	return count;
}

string num2bin(unsigned int x){ // ����ֻ����unsigned int ���Ϊsigned int ������λ��Զ��Ϊ1 while(x)�޷��˳� ��ѭ��
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
		str = to_string(x & 1) + str; // stringͷ�ļ� �ṩ to_string����
		x = x >> 1;
	}
	return str;
}

#define SQR(X) X*X // δ�����ŵĺ궨�� �궨������չ�� ֮��������ȼ���������
#define SQR1(X) ((X)*(X)) // �궨��Ϊ�˱�����������ȼ� ��ö�������

int main(){
	int x = -1;
	cout << num2bin(x) << endl;
	printf("%d, %x, %o\n", x, x, x); // %d ʮ���� %x ʮ������ %o �˽���	
	cout << func(x) << endl;

	int a = 10;
	int b = 10;
	int k = 2;
	int m = 1;
	a /= SQR(k + m) / SQR(k + m); //a = a/(k+m*k+m/k+m*k+m)= 10/(2+2*1+1/2+2*1+1) = 10/7.5 = 1; // ��������ת��
	b /= SQR1(k + m) / SQR1(k + m); // a = a/1 = 10;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}